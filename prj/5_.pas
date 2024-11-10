program array_search;

const
    nmax = 10;

type
    arr = array [1..nmax] of integer;

var
    a: arr;
    n: integer;
    d: integer;
    f: TextFile;
    d_index: integer;
    is_exists: boolean;
    min_el: integer;
    temp_min_el: integer;
    min_el_index: integer;

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
            readln(f, n);
            for i: integer := 1 to n do
                read(f, a[i]);
            readln(f, d);
            CloseFile(f);

            is_exists := false;
            d_index := 0;
            while (d_index < n) and (not is_exists) do 
            begin
                d_index += 1;             
                if a[d_index] = d then is_exists := true;
            end;

            min_el_index := 0;
            min_el := -1;
            while (min_el_index < d_index) and (min_el <= 0) do
            begin
                min_el_index += 1;
                if a[min_el_index] > 0 then min_el := a[min_el_index];
            end;
            if min_el < 0 then
            begin
                AssignFile(f, ParamStr(2));
                rewrite(f);
                writeln(f, 'Нет положительных чисел');
                CloseFile(f);
            end
            else
            begin
                for i: integer := 1 to d_index do
                begin
                    if (a[i] > 0) and (a[i] < min_el) then
                    begin
                        min_el_index := i;
                        min_el := a[i];
                    end; 
                end;
                AssignFile(f, ParamStr(2));
                rewrite(f);
                writeln(f, 'Положительный минимум: ', min_el);
                writeln(f, 'Индекс: ', min_el_index);
                CloseFile(f);
            end;
        end;
end;
    
end.