Option Explicit


Function init() As Variant
    init = Array()
End Function


Function is_empty(lst As Variant) As Boolean
    is_empty = (UBound(lst) < LBound(lst))
End Function


Function add_first(lst As Variant, el As String) As Variant
    Dim new_lst() As Variant
    Dim i As Long, length As Long


    length = IIf(is_empty(lst), 0, UBound(lst) + 1)
    ReDim new_lst(0 To length)

    new_lst(0) = Array(el, IIf(length > 0, 1, -1))
    
    For i = 1 To length - 1
        new_lst(i) = Array(lst(i - 1)(0), lst(i - 1)(1) + 1)
    Next i

    If length > 0 Then
        new_lst(length) = lst(length - 1)
    End If

    add_first = new_lst
End Function


Function add_last(lst As Variant, el As String) As Variant
    Dim new_lst() As Variant
    Dim i As Long, length As Long

    length = IIf(is_empty(lst), 0, UBound(lst) + 1)
    ReDim new_lst(0 To length)

    If length = 0 Then
        new_lst(0) = Array(el, -1)
    Else
        For i = 0 To length - 2
            new_lst(i) = lst(i)
        Next i
        new_lst(length - 1) = Array(lst(length - 1)(0), length)
        new_lst(length) = Array(el, -1)
    End If

    If length = 1 Then
        new_lst(0)(1) = 1
    End If

    add_last = new_lst
End Function


Function add_after_current(lst As Variant, current As Long, el As String) As Variant
    Dim new_lst() As Variant
    Dim i As Long, length As Long

    length = UBound(lst) + 1
    ReDim new_lst(0 To length)

    For i = 0 To current - 1
        new_lst(i) = lst(i)
    Next i

    new_lst(current) = Array(lst(current)(0), current + 1)
    new_lst(current + 1) = Array(el, current + 2)

    For i = current + 1 To length - 1
        new_lst(i + 1) = Array(lst(i)(0), lst(i)(1) + 1)
    Next i

    add_after_current = new_lst
End Function


Function del_first(lst As Variant) As Variant
    Dim new_lst() As Variant
    Dim i As Long, length As Long

    If is_empty(lst) Then
        del_first = lst
        Exit Function
    End If

    length = UBound(lst)
    If length = 0 Then
        del_first = Array()
        Exit Function
    End If

    ReDim new_lst(0 To length - 1)
    For i = 1 To length
        new_lst(i - 1) = Array(lst(i)(0), lst(i)(1) - 1)
    Next i

    del_first = new_lst
End Function


Function del_last(lst As Variant) As Variant
    Dim new_lst() As Variant
    Dim i As Long, length As Long

    If is_empty(lst) Then
        del_last = lst
        Exit Function
    End If

    length = UBound(lst)
    If length = 0 Then
        del_last = Array()
        Exit Function
    End If

    ReDim new_lst(0 To length - 1)
    For i = 0 To length - 2
        new_lst(i) = lst(i)
    Next i
    new_lst(length - 1) = Array(lst(length - 1)(0), -1)

    del_last = new_lst
End Function


Function del_current(lst As Variant, current As Long) As Variant
    Dim new_lst() As Variant
    Dim i As Long, length As Long

    length = UBound(lst) + 1
    ReDim new_lst(0 To length - 2)

    For i = 0 To current - 1
        new_lst(i) = lst(i)
    Next i

    For i = current + 1 To length - 1
        new_lst(i - 1) = Array(lst(i)(0), lst(i)(1) - 1)
    Next i

    del_current = new_lst
End Function


Function get_first(lst As Variant) As String
    If Not is_empty(lst) Then
        get_first = lst(0)(0)
    Else
        get_first = ""
    End If
End Function


Function get_last(lst As Variant) As String
    If Not is_empty(lst) Then
        get_last = lst(UBound(lst))(0)
    Else
        get_last = ""
    End If
End Function


Function get_current(lst As Variant, current As Long) As String
    If Not is_empty(lst) And current <= UBound(lst) Then
        get_current = lst(current)(0)
    Else
        get_current = ""
    End If
End Function





Function next_el(lst As Variant, current As Long) As Long
    If current >= 0 And current <= UBound(lst) Then
        next_el = lst(current)(1)
    Else
        next_el = -1
    End If
End Function


Function count(lst As Variant, target As Long) As Long
    Dim c As Long: c = 0
    Dim i As Long: i = 0

    Do While i <> -1
        If Len(get_current(lst, i)) = target Then
            c = c + 1
        End If
        i = next_el(lst, i)
    Loop

    count = c
End Function


Sub read_list(ByRef lst As Variant, rng As Range)
    Dim cell As Range
    lst = init()

    For Each cell In rng
        If cell.Value <> "" Then
            lst = add_last(lst, CStr(cell.Value))
        End If
    Next cell
End Sub


Sub main()
    Dim rng As Range
    Dim lst As Variant
    Dim i As Long
    Dim outputCell As Range

    On Error Resume Next
    Set rng = Application.InputBox("Выберите диапазон с текстом (в 1 строку)", Type:=8)
    On Error GoTo 0

    If rng Is Nothing Then
        MsgBox "Диапазон не выбран!", vbExclamation
        Exit Sub
    End If

    read_list lst, rng

    Set outputCell = rng.Worksheet.Range("A5")

    outputCell.Offset(i + 1, 0).Value = "кол-во букв"
    outputCell.Offset(i + 1, 1).Value = "кол-во в списке"

    For i = 1 To 9
        outputCell.Offset(i + 2, 0).Value = i
        outputCell.Offset(i + 2, 1).Value = count(lst, i)
    Next i
End Sub

