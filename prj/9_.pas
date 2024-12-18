program Lab12;

const
    nmax = 10;

type
    matrix = array [1..nmax, 1..nmax] of integer;  

var
    f: TextFile;
    a, b, c:    matrix;    
    na, nb, nc: integer; 

    kam, kbm, kcm: integer;

    kas, kbs, kcs: integer;
                         

procedure input(var mx: matrix; var n: integer);
begin
    read(f, n);
    for i: integer := 1 to n do for j: integer := 1 to n do read(f, mx[i, j]);
end;


procedure output();
begin
    if (kam = kbm) and (kbm = kcm) then
            writeln(f, 'Сумма подходящих элементов, расположенных выше главной диагонали, совпадает во всех трёх матрицах и равно ', kam:2)
        else if (kam = kbm) and (kam > kcm) then
            writeln(f, 'Сумма подходящих элементов, расположенных выше главной диагонали, максимально в матрицах A и B и равно ', kam:2)
        else if (kam = kcm) and (kam > kbm) then
            writeln(f, 'Сумма подходящих элементов, расположенных выше главной диагонали, максимально в матрицах A и C и равно ', kam:2)
        else if (kbm = kcm) and (kbm > kam) then
            writeln(f, 'Сумма подходящих элементов, расположенных выше главной диагонали, максимально в матрицах B и C и равно ', kbm:2)
        else if (kam > kbm) and (kam > kcm) then
            writeln(f, 'Сумма подходящих элементов, расположенных выше главной диагонали, максимально в матрице A и равно ', kam:2)
        else if (kbm > kam) and (kbm > kcm) then
            writeln(f, 'Сумма подходящих элементов, расположенных выше главной диагонали, максимально в матрице B и равно ', kbm:2)
        else
            writeln(f, 'Сумма подходящих элементов, расположенных выше главной диагонали, максимально в матрице C и равно ', kcm:2);

        if (kas = kbs) and (kbs = kcs) then
            writeln(f, 'Сумма подходящих элементов, и расположенных выше побочной диагонали, совпадает во всех трёх матрицах и равно ', kas:2)
        else if (kas = kbs) and (kas > kcs) then
            writeln(f, 'Сумма подходящих элементов, и расположенных выше побочной диагонали, максимально в матрицах A и B и равно ', kas:2)
        else if (kas = kcs) and (kas > kbs) then
            writeln(f, 'Сумма подходящих элементов, и расположенных выше побочной диагонали, максимально в матрицах A и C и равно ', kas:2)
        else if (kbs = kcs) and (kbs > kas) then
            writeln(f, 'Сумма подходящих элементов, и расположенных выше побочной диагонали, максимально в матрицах B и C и равно ', kbs:2)
        else if (kas > kbs) and (kas > kcs) then
            writeln(f, 'Сумма подходящих элементов, и расположенных выше побочной диагонали, максимально в матрице A и равно ', kas:2)
        else if (kbs > kas) and (kbs > kcs) then
            writeln(f, 'Сумма подходящих элементов, и расположенных выше побочной диагонали, максимально в матрице B и равно ', kbs:2)
        else
            writeln(f, 'Сумма подходящих элементов, и расположенных выше побочной диагонали, максимально в матрице C и равно ', kcs:2);

end;


function main_proccessing(var mx: matrix; n: integer):integer;
begin
    for i: integer := 1 to n do
    begin
        for j: integer := i to n do
        begin
            if (mx[i, j] mod 2) <> 0.0 then
            begin
                result +=mx[i, j]
            end;
        end;
    end;
end;


function not_main_proccessing(var mx: matrix; n: integer):integer;
begin
    for i: integer := 1 to n do
    begin
        for j: integer := 1 to n-i+1 do
        begin
            if (mx[i, j] mod 2) <> 0 then
            begin
                result +=mx[i, j]
            end;
        end;
    end;
end;


begin
if ParamCount < 2 then
    writeln('Недостаточно параметров!')
else
begin
    if not FileExists(ParamStr(1)) then
            writeln('Невозможно открыть файл ''', ParamStr(1), ''' для чтения')
    else
    begin

        AssignFile(f, ParamStr(1));
        Reset(f);
        
        input(a, na);
        input(b, nb);
        input(c, nc);

        kam := main_proccessing(a, na);
        kbm := main_proccessing(b, nb);
        kcm := main_proccessing(c, nc);

        kas := not_main_proccessing(a, na);
        kbs := not_main_proccessing(b, nb);
        kcs := not_main_proccessing(c, nc);

        CloseFile(f);
        AssignFile(f, ParamStr(2));
        Rewrite(f);

        output();

        CloseFile(f);
    end;
end;
end.