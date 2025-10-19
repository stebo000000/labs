Rem Attribute VBA_ModuleType=VBADocumentModule
Option VBASupport 1
Function input_matrix(rng As Range, n, m) As Variant
    Dim A() As Variant
    Dim i As Integer, j As Integer
    Dim elem As Variant
    
    ReDim A(1 To n, 1 To m)
    
    For i = 1 To n
        For j = 1 To m
            elem = rng.Cells(i, j).Value
            If IsNumeric(elem) Then
                A(i, j) = elem
            Else
                A(i, j) = 0
            End If
        Next j
    Next i
    
    input_matrix = A
End Function

Function has_bigger(A As Variant, n As Integer, m As Integer, num As Double)
    Dim flag As Boolean
    Dim i As Integer, j As Integer

    flag = False
    i = 1

    While i <= n And Not flag
        j = 1
        While j <= m And Not flag
            If A(i, j) < num Then
                flag = True
            End If
            j = j + 1
        Wend
        i = i + 1
    Wend
    
    has_bigger = flag
    
End Function

Sub prod_with_condition(ByRef A As Variant, n As Integer, m As Integer, num As Double)
    Dim i As Integer, j As Integer
    For i = 1 To n
        For j = 1 To m
            If (i, j) < num Then
                A(i, j) = A(i, j) * num
            End If
        Next j
    Next i
End Sub


Sub main_program()
    Dim matrix() As Variant
    Dim rng As Range
    Dim num As Double
    Dim n As Integer, m As Integer
    Dim outputRng As Range
    Dim outputCell As Range
    
    On Error Resume Next
    Set rng = Application.InputBox("Введите диапазон матрицы: ", Type:=8)
    On Error GoTo 0
    
    If rng Is Nothing Then
        MsgBox "Диапазон не выбран!", vbExclamation
    Else
        num = Application.InputBox("Введите заданное число: ", Type:=1)
        
        n = rng.Rows.Count
        m = rng.Columns.Count
        
        matrix = input_matrix(rng, n, m)
        
        If has_bigger(matrix, n, m, num) Then
            task matrix, n, m, num
            
            Set outputRng = rng.Offset(0, m + 1)
            
            outputRng.Resize(n, m).Value = matrix
            
            Cells(n + 2, 1).Value = "исходная матрица"
            Cells(n + 2, m + 2).Value = "измененная матрица"
        Else
            MsgBox "матрица не изменилась"
        End If
    End If
    
End Sub
