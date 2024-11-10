program Arrays;

const
    nmax = 10;

type
    arr = array [1..nmax] of real;

var
    a: arr;
    c: arr;
    n: integer;
    b: real;
    f: TextFile;


    is_exists: boolean = true;
    counter : integer = 0;
    sum : real;
    max_sum: real;

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
        for i: integer := 1 to n do
            read(f, c[i]);
        readln(f, b);
        CloseFile(f);

        {for i : integer := 1 to n do if b > a[i] then is_exists := false;}
        var ii : integer = 1;
        while (ii < n) and not is_exists do 
        begin
            if b > a[ii] then is_exists := false;
            ii += 1
        end;

        if is_exists then
        begin
            for i: integer := 1 to n do
            begin
                if c[i] < 0 then
                begin
                    counter += 1;
                    c[i] := c[i] / i;
                end;
            end;
            AssignFile(f, ParamStr(2));
            rewrite(f);
            writeln(f, 'чисел < 0: ', counter);
            for i: integer := 1 to n do write(f, ' ', c[i]);
            CloseFile(f);
        end
        else
        begin
            max_sum := abs(a[1] + c[n]);
            for i: integer := 2 to n do
            begin
                sum := abs(a[i] + c[n - i + 1]);
                if sum > max_sum then max_sum := sum
            end;
            AssignFile(f, ParamStr(2));
            rewrite(f);
            Writeln(f, 'сумма: ', max_sum);
            CloseFile(f);
        end;

    end;
end;
    
end.