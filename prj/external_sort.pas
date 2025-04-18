unit external_sort;
    
interface

procedure copy_file(f1, f2: TextFile);
procedure divide_file(input_file, ff, sf: TextFile; const len, seq_len: integer);
procedure concat_files(output_file, ff, sf: TextFile; const seq_len, len: integer);


implementation

procedure copy_file(f1, f2: TextFile);
var buffer: integer;
begin
    while not eof(f1) do
    begin
        readln(f1, buffer);
        writeln(f2, buffer);
    end;
end;

procedure divide_file(input_file, ff, sf: TextFile; const len, seq_len: integer);
var 
    buffer: integer;
begin
    for i : integer := 0 to len - 1 do
    begin
        readln(input_file, buffer);
        if (i div seq_len) mod 2 = 0 then writeln(ff, buffer)
        else writeln(sf, buffer);
    end;
end;


procedure concat_files(output_file, ff, sf: TextFile; const seq_len, len: integer);
var
    a, b, ca, cb: integer;
    is_end: boolean := false;
begin
    readln(ff, a);
    readln(sf, b);

    while not is_end do
    begin
        ca := 0;
        cb := 0;

        while ((ca < seq_len) and (cb < seq_len)) do
        begin
            if (a < b) then
            begin
                writeln(output_file, a);
                inc(ca);
                if not eof(ff) then readln(ff, a) 
                else
                begin
                    writeln(output_file, b);
                    is_end := true;
                    break;
                end; 
            end
            else
            begin
                writeln(output_file, b);
                inc(cb);
                if not eof(sf) then readln(sf, b)
                else
                begin
                    is_end := true;
                    writeln(output_file, a);
                    break;
                end; 
            end;
        end;

        if is_end then break;

        while (ca <> cb) do
        begin
            if (ca > cb) then
            begin
                writeln(output_file, b);
                inc(cb);
                if not eof(sf) then readln(sf, b)
                else
                begin
                    is_end := true;
                    writeln(output_file, a);
                    break;
                end;
            end
            else
            begin
                writeln(output_file, a);
                inc(ca);
                if not eof(ff) then readln(ff, a) 
                else
                begin
                    is_end := true;
                    writeln(output_file, b);
                    break;
                end; 
            end;
        end;


    end;

    while not eof(ff) do
    begin
        readln(ff, a);
        writeln(output_file, a);
    end;

    while not eof(sf) do
    begin
        readln(sf, b);
        writeln(output_file, b);
    end;

end;
    
end.