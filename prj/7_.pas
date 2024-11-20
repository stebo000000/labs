program array_search;

const
    nmax = 10;
    mmax = 10;

type
    arr = array [1..nmax, 1..mmax] of integer;

var
    f: TextFile;
    ft: file of real;
    el: real;

procedure print_typed_file(ft: file of real);
begin
    Seek(ft, 0);
    while not Eof(ft) do
    begin
        read(ft, el);
        writeln(el)
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
            AssignFile(ft, ParamStr(2));
            rewrite(ft);

            while not Eof(f) do
            begin
                read(f, el);
                if (el >= -4.9) and (el <= 1.9) then write(ft, el)
            end;

            print_typed_file(ft);
        end;

        
end;
end.