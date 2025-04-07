program MySet;
uses sort_functions;

var
    arr, arr1, arr2, arr3: array of integer;
    s_arr, s_arr1, s_arr2, s_arr3: array of string;
    f: TextFile;
    t1, t2, t3, t4: System.DateTime;

procedure input(var arr: array of integer; var f: TextFile);
var
    n: integer;
begin
    read(f, n);
    SetLength(arr, n);
    for i: integer := 0 to n - 1 do 
        read(f, arr[i]);
end;
procedure input(var arr: array of string; var f: TextFile);
var
    n: integer;
begin
    readln(f, n);
    SetLength(arr, n);
    for i: integer := 0 to n - 1 do 
        readln(f, arr[i]);

end;

procedure output(var arr: array of integer; var f: TextFile);
begin
    for j: integer := 0 to high(arr) do 
            write(f, arr[j], ' ');
        writeln(f);
end;
procedure output(var arr: array of string; var f: TextFile);
begin
    for j: integer := 0 to high(arr) do 
            write(f, arr[j], ' ');
        writeln(f);
end;


begin
     if ParamCount < 2 then
    begin
        writeln('Недостаточно параметров');
        exit;
    end;
    try
        AssignFile(f, ParamStr(1));
        Reset(f);
    except
        writeln('Невозможно открыть файл ''', Paramstr(1), ''' для чтения');
        exit;
    end;
    
    input(arr, f);
    CloseFile(f);
    Reset(f);
    input(s_arr, f);
    CloseFile(f);

    try
        AssignFile(f, ParamStr(2));
        Rewrite(f);
    except
        writeln('Невозможно открыть файл ''', Paramstr(2), ''' для записи');
        exit;
    end;

    arr1 := copy(arr);
    arr2 := copy(arr);
    arr3 := copy(arr);

    t1 := System.DateTime.Now;
    bubble_sort(arr1);
    writeln(System.DateTime.Now - t1, f);
    t2 := System.DateTime.Now;
    pickme_sort(arr2);
    writeln(System.DateTime.Now - t2, f);
    t3 := System.DateTime.Now;
    insert_sort(arr3);
    writeln(System.DateTime.Now - t3, f);
    t4 := System.DateTime.Now;
    quick_sort(arr, 0, high(arr));
    writeln(System.DateTime.Now - t4, f);


    output(arr1, f);
    output(arr2, f);
    output(arr3, f);
    output(arr, f);

    s_arr1 := copy(s_arr);
    s_arr2 := copy(s_arr);
    s_arr3 := copy(s_arr);

    t1 := System.DateTime.Now;
    bubble_sort(s_arr1);
    writeln(System.DateTime.Now - t1, f);
    t2 := System.DateTime.Now;
    pickme_sort(s_arr2);
    writeln(System.DateTime.Now - t2, f);
    t3 := System.DateTime.Now;
    insert_sort(s_arr3);
    writeln(System.DateTime.Now - t3, f);
    t4 := System.DateTime.Now;
    quick_sort(s_arr, 0, high(arr));
    writeln(System.DateTime.Now - t4, f);


    output(s_arr1, f);
    output(s_arr2, f);
    output(s_arr3, f);
    output(s_arr, f);

    CloseFile(f);
end.