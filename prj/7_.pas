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
    el1: real;
    pos: integer;
    is_exists: boolean := false;
    is_end: boolean;

procedure print_typed_file(ft: file of real);
begin
    Seek(ft, 0);
    while not Eof(ft) do
    begin
        read(ft, el);
        writeln(el)
    end;
end;

procedure find_right_el(ft: file of real);
begin
Seek(ft, pos);
    begin
        read(ft, el);
        if el < 0 then
        begin
            is_exists := true;
        end;
        if (pos > 0) and (not is_exists) then
        begin
            pos -= 1;
            find_right_el(ft);
        end;
    end;
end;

function replace_elements(ft: file of real):boolean;
begin
    Seek(ft, pos);
    if pos <> fileSize(ft)-1 then
    begin
        read(ft, el);
        read(ft, el1);
        Seek(ft, pos);
        write(ft, el1);
        write(ft, el);
        result := false
    end
    else
    begin
        result := true
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
            writeln;
            pos:= fileSize(ft)-1;
            find_right_el(ft);
            if is_exists then
            begin
                write('element: ', el, ' at pos: ', pos+1);
                writeln;
                writeln;

                while (not is_end) do
                begin
                    is_end := replace_elements(ft);
                    pos += 1
                end;

                print_typed_file(ft)
            end;
        end;        
end;
end.