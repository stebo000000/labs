program bulb;
uses recurrent_functions;
var
    arr: array of integer;
    f: TextFile;
    lin_res, cas_res: integer;


procedure input(var arr: array of integer; var f: TextFile);
var
    n: integer;
begin
    read(f, n);
    SetLength(arr, n);
    for i: integer := 0 to n - 1 do 
        read(f, arr[i]);
end;

function is_array_correct(const arr: array of integer): boolean;
var
    i: integer := 0;
begin
    result := false;
    while (i < Length(arr)) and not result do
    begin
        if arr[i] < 0 then result := true;
        i += 1;
    end; 
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

    try
        AssignFile(f, ParamStr(2));
        Rewrite(f);
    except
        writeln('Невозможно открыть файл ''', Paramstr(2), ''' для записи');
        exit;
    end;

    if linear_compare(arr, 0) then
    begin
        cas_res := cascad_multiply(arr, 0, high(arr));
        writeln(f, 'cascad recurrent function');
        writeln(f, cas_res);
    end
    else
        writeln(f, 'incorrect array');
    CloseFile(f);
end.