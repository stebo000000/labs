unit external_sort;
    
interface

procedure copy_file(f1, f2: TextFile);
procedure divide_file(input_file, ff, sf: TextFile; const len: integer);
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

procedure divide_file(input_file, ff, sf: TextFile; const len: integer);
var 
    buffer: integer;
begin
    for i: integer := 0 to len div 2 - 1 do
    begin
        readln(input_file, buffer);
        writeln(ff, buffer);
    end;
    for i: integer := len div 2 to len - 1 do
    begin
        readln(input_file, buffer);
        writeln(sf, buffer);
    end;
end;


procedure concat_files(output_file, ff, sf: TextFile; const seq_len, len: integer);
var
    a, b, ca, cb, i, cake: integer;
begin
    while (cake < (len div seq_len) div 2) and (not (eof(ff) and eof(sf))) do
    begin
        ca := 0;
        cb := 0;
        i := 0;
        readln(ff, a);
        readln(sf, b);
        while (not (eof(ff) and eof(sf))) and (i < seq_len) do
        begin
            if a < b then
            begin
                writeln(output_file, a);
                readln(ff, a);
                inc(ca);
            end
            else
            begin
                writeln(output_file, b);
                readln(sf, b);
                inc(cb);
            end;
            inc(i);
        end;
        
        while not (eof(ff) or eof(sf)) and (ca <> cb) do
        begin
            if (ca > cb) and not eof(sf) then
            begin
                writeln(output_file, b);
                readln(sf, b);
                inc(cb);
            end
            else if not eof(sf) then
            begin
                writeln(output_file, a);
                readln(ff, a);
                inc(ca);
            end;
        end;
        writeln(ca, ' ', cb);
        inc(cake);
    end;
    if a < b then
    begin
        writeln(output_file, a);
        writeln(output_file, b);
    end
    else
    begin
        writeln(output_file, b);
        writeln(output_file, a);
    end;
end;
    
end.