program MySet;
uses matrix_processing_unit;

var
    arr1, arr2: array of integer;
    matrix: array of array of integer;
    row: integer;
    num_replace_to: integer;

    f: TextFile;

procedure input(var mx: array of array of integer; var f: TextFile);
var
    n: integer;
    m: integer;
begin
    read(f, m);
    read(f, n);
    SetLength(mx, m);
    for i: integer := 0 to m - 1 do
    begin
        SetLength(mx[i], n);
        for j: integer := 0 to n - 1 do 
            read(f, mx[i][j]);
    end;
end;

procedure input(var num: integer; var f: TextFile);
begin
    readln(f, num);
end;

procedure input(var arr: array of integer; var f: TextFile);
var
    n: integer;
begin
    read(f, n);
    SetLength(arr, n);
    for i: integer := 0 to n - 1 do 
        read(f, arr[i]);
end;

procedure output(var mx: array of array of integer; var f: TextFile);
begin

    for i: integer := 0 to high(mx) do
    begin
        for j: integer := 0 to high(mx[i]) do 
            write(f, mx[i][j], ' ');
        writeln(f);
    end;
    writeln(f);
end;

procedure output(var arr: array of integer; var f: TextFile);
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
    
    input(num_replace_to, f);
    input(matrix, f);
    input(arr1, f);
    input(arr2, f);

    CloseFile(f);


    row := negative_row_in_matrix(matrix);

    if row = -1 then
        replace_zeros(matrix, num_replace_to)
    else
        array_processing(matrix[row]);
    
    array_processing(arr1);
    array_processing(arr2);

    try
        AssignFile(f, ParamStr(2));
        Rewrite(f);
    except
        writeln('Невозможно открыть файл ''', Paramstr(2), ''' для записи');
        exit;
    end;

    output(matrix, f);
    output(arr1, f);
    output(arr2, f);

    CloseFile(f);
end.