unit sort_in_file;
    
interface
uses types;
procedure write_in_file(tf: file of Student; f: TextFile);
procedure pickme_sort(tf: file of Student; is_less: function(a, b: Student):boolean);
procedure write_stupids(tf: file of Student);
procedure write_count_of_stupids(tf: file of Student);

implementation

procedure write_in_file(tf: file of Student; f: TextFile);
var buffer: Student;
begin
    seek(tf, 0);
    while not eof(tf) do
    begin
        read(tf, buffer);
        writeln(f, buffer);
    end;
end;


procedure pickme_sort(tf: file of Student; is_less: function(a, b: Student):boolean);
var
    local_min: Student;
    buffer: Student;
    buffer2: Student;
    local_min_i: integer;
    current_i: integer := 0;

begin
    seek(tf, 0);
    while not eof(tf) do
    begin
        seek(tf, current_i);
        read(tf, local_min);
        local_min_i := current_i;
        while not eof(tf) do
        begin
            read(tf, buffer);
            if is_less(buffer, local_min) then
            begin
                local_min := buffer;
                local_min_i := FilePos(tf) - 1;
            end;
        end;
        
        seek(tf, current_i);
        read(tf, buffer2);
        seek(tf, current_i);
        write(tf, local_min);

        seek(tf, local_min_i);
        write(tf, buffer2);

        inc(current_i);

    end;
    
end;

function count_of_2(const stdnt: Student): integer;
var counter: integer := 0;
begin
    if stdnt.marks.math = 2 then inc(counter);
    if stdnt.marks.phisics = 2 then inc(counter);
    if stdnt.marks.comp_science = 2 then inc(counter);

    result := counter;
end;

procedure write_stupids(tf: file of Student);
var buffer: Student;
begin
    while not eof(tf) do
    begin
        read(tf, buffer);
        if (count_of_2(buffer) > 2) and (buffer.gender = 'male') then writeln(buffer.fio.surname);
    end;
end;

procedure write_count_of_stupids(tf: file of Student);
var 
    counter: integer := 0;
    buffer: Student;
begin
    while not eof(tf) do
    begin
        read(tf, buffer);
        if (count_of_2(buffer) > 2) and (buffer.gender = 'male') and (buffer.grp = 'A-13-10') then inc(counter);
    end;
    writeln('stpds in A-13-10: ', counter);
end;
end.