Function f_func(x As Long, y As Long, z As Long) As Long
    f_func = (x + y + z) And &HFF
End Function

Function G_func(x As Long, y As Long, z As Long) As Long
    G_func = (-x + y + z) And &HFF
End Function

Function H_func(x As Long, y As Long, z As Long) As Long
    H_func = (x - y + z) And &HFF
End Function

Function i_func(x As Long, y As Long, z As Long) As Long
    i_func = (x + y - z) And &HFF
End Function


Function multiplicative(hash_table_size As Long, s As String) As Double
    Const a As Double = 0.6180339887
    
    Dim hash As Double
    Dim l As Long
    Dim i As Long
    
    hash = 0
    l = Len(s)
    
    For i = 1 To l
        hash = (Asc(Mid$(s, i, 1))) * (i + 1)
    Next i
    
    multiplicative = Int(hash_table_size * ((hash * a) - Int(hash * a)))
End Function

Function md5(s As String, hash_table_size As Long) As Long
    Dim a As Long
    Dim b As Long
    Dim c As Long
    Dim d As Long
    Dim k As Long, ord_ch As Integer
    Dim res As Long
    
    a = 59
    b = 5
    c = 167
    d = 211
    
    For k = 1 To Len(s)
        ord_ch = Asc(Mid(s, k, 1))
        
        a = (a + f_func(b, c, d) + ord_ch) And &HFF
        a = ((a * 2) Or (a \ 128)) And &HFF
        b = (b + G_func(a, c, d) + ord_ch) And &HFF
        b = ((b * 8) Or (b \ 32)) And &HFF
        c = (c + H_func(a, b, d) + ord_ch) And &HFF
        c = ((c * 32) Or (c \ 8)) And &HFF
        d = (d + i_func(a, b, c) + ord_ch) And &HFF
        d = ((d * 128) Or (d \ 2)) And &HFF
        
    Next k
    
    res = a
    res = ((res * 128) Or b) 'ïðè 256 ïèøåò overflow'
    res = ((res * 128) Or c)
    res = ((res * 128) Or d)
    
    md5 = (res Mod hash_table_size)
End Function

Function adhd(s As String, hash_table_size As Long) As Double
    Dim hash As Double
    Dim i As Long
    Dim left_sdvig As Long
    Dim right_sdvig As Long
    
    hash = 0
    
    For i = 1 To Len(s)
        hash = hash + Asc(Mid$(s, i, 1))
        left_sdvig = (hash * 2)
        right_sdvig = (hash \ 2)
        hash = (left_sdvig Or right_sdvig)
    Next i
    
    adhd = (hash Mod hash_table_size)
End Function
Function select_table_size() As Long
    Dim hash_table_size As Long
    hash_table_size = Application.InputBox("Ââåäèòå ïðåäïîëîãàåìîå êîëè÷åñòâî ÿ÷ååê ïàìÿòè: ", Type:=1)
    select_table_size = hash_table_size
End Function

Sub main()
    Dim ws As Worksheet
    Dim lastRow As Long
    Dim i As Long
    Dim k As String
    Dim mult As Double
    Dim sdvig As Long
    Dim md_5 As Long
    Dim hash_table_size As Long
    Dim p As Long
    
    Set ws = ActiveSheet
    
    lastRow = ws.Cells(ws.Rows.Count, 1).End(xlUp).Row
    
    hash_table_size = select_table_size
    
    ws.Cells(1, 2).value = "multiplicative"
    ws.Cells(1, 3).value = "byte_sdvig"
    ws.Cells(1, 4).value = "md5"
    
    For i = 2 To lastRow
        k = ws.Cells(i, 1).value
        
        mult = multiplicative(hash_table_size, k)
        sdvig = adhd(k, hash_table_size)
        md_5 = md5(k, hash_table_size)
        
        ws.Cells(i, 2).value = mult
        ws.Cells(i, 3).value = sdvig
        ws.Cells(i, 4).value = md_5
    Next i
End Sub
