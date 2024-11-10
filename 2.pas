program Strings;

var
    str, temp_str: string;
    c: integer;
    i: integer;

    ans: string;

    f: TextFile;

begin
    AssignFile(f, 'input02.txt');
    Reset(f);

    while not eof(f) do
    begin
        readln(f, str);
        str += ' ';
        c := 0;
        temp_str := '';
        for i := 1 to length(str) do
            begin
                if str[i] = ' ' then
                    begin
                        c += 1;
                        if c mod 2 = 0 then
                            ans := ans + temp_str + ' ';
                        temp_str := '';
                    end
                else
                    begin
                        temp_str += str[i]
                    end;
            end;
        writeln(ans);
        ans := '';
    end;

CloseFile(f);
end.