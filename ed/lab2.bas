Rem Attribute VBA_ModuleType=VBADocumentModule
Option VBASupport 1
Public Function fill_array(rng As Range) As Variant
    Dim arr() As Variant
    Dim cols As Integer
    Dim i As Integer
    Dim elem As Variant
    
    cols = rng.Columns.count
    ReDim arr(1 To cols)
    
    For i = 1 To cols
        elem = rng.Cells(1, i).Value
        If IsNumeric(elem) Then
            arr(i) = CDbl(elem)
        Else
            arr(i) = 0
        End If
    Next i
    
    fill_array = arr
End Function

Public Function find_min(arr As Variant) As Double
    Dim i As Integer
    Dim min_num As Double
    
    min_num = arr(0)

    For i = LBound(arr) + 1 To UBound(arr)
        If arr(i) < min_num Then min_num = arr(i)
    Next i

    find_min = min_num
End Function

Sub main_program()
    Dim rng As Range
    Dim arr As Variant
    Dim result As Double
    Dim outputCell As Range
    
    On Error Resume Next
    Set rng = Application.InputBox("введите диапозон:", Type:=8)
    On Error GoTo 0

    If rng Is Nothing Then
        MsgBox "диапозон не выбран", vbExclamation
    Else
        arr = fill_array(rng)
        result = find_min(arr)
        
        MsgBox "минимальный элемент: " & result, vbInformation
        Set outputCell = rng.Cells(1, rng.Columns.count + 2)
        outputCell.Value = "минимальный элемент:"
        outputCell.Offset(0, 1).Value = result
    End If
End Sub
