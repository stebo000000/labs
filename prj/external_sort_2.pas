unit external_sort_2;
    
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
    buffer, was_wrote: integer;
begin
    readln(input_file, buffer);
    writeln(ff, buffer);
    was_wrote := buffer;
    readln(input_file, buffer);


    while not eof(input_file) do
    begin
        while (was_wrote <= buffer) and not eof(input_file) do
        begin
            writeln(ff, buffer);
            was_wrote := buffer;
            readln(input_file, buffer);
        end;

        if not eof(input_file) then
        begin
            writeln(ff, -1);
            writeln(sf, buffer);
            was_wrote := buffer;
            readln(input_file, buffer);
        end
        else if (was_wrote <= buffer) then 
        begin
            writeln(ff, buffer);
            break;
        end
        else
        begin
            writeln(sf, buffer);
            break;
        end;


        while (was_wrote <= buffer) and not eof(input_file) do
        begin
            writeln(sf, buffer);
            was_wrote := buffer;
            readln(input_file, buffer);
        end;

        if not eof(input_file) then
        begin
            writeln(sf, -1);
            writeln(ff, buffer);
            was_wrote := buffer;
            readln(input_file, buffer);
        end
        else if (was_wrote <= buffer) then 
        begin
            writeln(sf, buffer);
            break;
        end
        else
        begin
            writeln(ff, buffer);
            break;
        end;
    end;
end;


procedure concat_files(output_file, ff, sf: TextFile; const seq_len, len: integer);
var
    a, b: integer;
    ca, cb : boolean;
    is_end: boolean := false;
begin
    readln(ff, a);
    readln(sf, b);

    while not is_end do
    begin
        ca := false;
        cb := false;

        while true do
        begin
            // writeln('a b ', a, ' ', b);
            if (a < b) then
            begin
                writeln(output_file, a);
                if not eof(ff) then readln(ff, a) 
                else
                begin
                    writeln(output_file, b);
                    is_end := true;
                    break;
                end;
                if (a = -1) and not eof(ff) then
                begin
                    readln(ff, a);
                    ca := true;
                    break;
                end
                else if eof(ff) and (a = -1) then
                begin
                    writeln(output_file, b);
                    is_end := true;
                    break;
                end;
            end
            else
            begin
                writeln(output_file, b);
                if not eof(sf) then readln(sf, b)
                else
                begin
                    is_end := true;
                    writeln(output_file, a);
                    break;
                end; 
                if (b = -1) and not eof(sf) then
                begin
                    readln(sf, b);
                    cb := true;
                    break;
                end
                else if eof(sf) and (b = -1) then
                begin
                // writeln('bb ' , b);
                    writeln(output_file, a);
                    is_end := true;
                    break;
                end;
            end;
        end;

        if is_end then break;

        if ca then
        begin
            while true do
            begin
                // writeln('b: ', b);
                writeln(output_file, b);
                if not eof(sf) then readln(sf, b)
                else
                begin
                    is_end := true;
                    writeln(output_file, a);
                    break;
                end;
                if (b = -1) and not eof(sf) then
                begin
                    readln(sf, b);
                    break;
                end
                else if eof(sf) and (b = -1) then
                begin
                    writeln(output_file, a);
                    is_end := true;
                    break;
                end;
            end;
        end
        else
        begin
            while true do
            begin
            // writeln('a: ', a);
                writeln(output_file, a);
                if not eof(ff) then readln(ff, a) 
                else
                begin
                    is_end := true;
                    writeln(output_file, b);
                    break;
                end; 
                if (a = -1) and not eof(ff) then
                begin
                    readln(ff, a);
                    break;
                end
                else if eof(ff) and (a = -1) then
                begin
                    writeln(output_file, b);
                    is_end := true;
                    break;
                end;
            end;
        end;


    end;

    while not eof(ff) do
    begin
        readln(ff, a);
        if (a <> -1) then writeln(output_file, a);
    end;

    while not eof(sf) do
    begin
        readln(sf, b);
        if (b <> -1) then writeln(output_file, b);
    end;

end;
    
end.