program array_search;

const
    nmax = 10;
    mmax = 10;

type
    arr = array [1..nmax, 1..mmax] of integer;

var
    a: arr;
    n, m: integer;
    f: TextFile;
    column_was_found: boolean := false;
    positive_was_found: boolean;
    column: integer;
    row: integer;
    sum: integer;
    counter: integer;

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
            readln(f, n, m);
            for i: integer := 1 to n do for j: integer := 1 to n do read(f, a[i, j]);
            CloseFile(f);

            column := 0;
            counter := 0;
            while (column < m) and (not column_was_found) do
            begin
                column += 1;

                row := 0;
                sum := 0;
                positive_was_found := false;
                for row := 1 to n do
                begin
                    if a[row, column] >= 0 then positive_was_found := true;
                    sum += a[row, column];
                end;
                if sum > 0 then counter += 1;
                if not positive_was_found then column_was_found := true;
            end;

            AssignFile(f, ParamStr(2));
            rewrite(f);
            if column_was_found then writeln(f, 'Отрицательный столбец: ', column) else writeln(f, 'Отрицательный столбец не найден');
            CloseFile(f);

            for j: integer := column + 1 to m do
            begin
                sum := 0;
                for i: integer := 1 to n do
                begin
                    sum += a[i, j];
                end;
                if sum > 0 then counter += 1;
            end;

            AssignFile(f, ParamStr(2));
            append(f);
            writeln(f, 'Число положительных столбцов: ', counter);
            CloseFile(f);
        end;
end;
end.