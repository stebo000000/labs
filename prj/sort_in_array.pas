unit sort_in_array;
    
interface
uses types;
procedure read_in_array(var arr: array of Student; tf: file of Student);
procedure quick_sort(var arr: array of Student; s, e : integer; is_less: function(a, b: Student):boolean);
procedure write_stupids(const arr: array of Student);
procedure write_count_of_stupids(const arr: array of Student);
procedure write_in_text_file(var arr: array of Student; f: TextFile);

implementation



procedure read_in_array(var arr: array of Student; tf: file of Student);
var i: integer := 0;
begin
    while not eof(tf) do
    begin
        SetLength(arr, i+1);
        read(tf, arr[i]);
        inc(i);
    end;
end;


procedure write_in_text_file(var arr: array of Student; f: TextFile);
begin
    for i: integer := 0 to high(arr) do
    begin
        writeln(f, arr[i]);
    end;
end;


procedure quick_sort(var arr: array of Student; s, e : integer; is_less: function(a, b: Student):boolean);
var 
    pivot: Student := arr[s];
    sep_point: integer := s;
    buffer: Student;
begin
    if s < e then
    begin
        for i: integer := s + 1 to e do
        begin
            if is_less(arr[i], pivot) then
            begin
                buffer := arr[sep_point];
                arr[sep_point] := arr[i];
                arr[i] := buffer;
                inc(sep_point);
            end;
        end;

        if sep_point = s then
            inc(sep_point);
        quick_sort(arr, s, sep_point - 1, is_less);
        quick_sort(arr, sep_point, e, is_less);
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

procedure write_stupids(const arr: array of Student);
begin
    for i: integer := 0 to high(arr) do if (count_of_2(arr[i]) > 2) and (arr[i].gender = 'male') then writeln(arr[i]);
end;

procedure write_count_of_stupids(const arr: array of Student);
var counter: integer := 0;
begin
    for i: integer := 0 to high(arr) do if (count_of_2(arr[i]) > 2) and (arr[i].grp = 'A-13-10') and (arr[i].gender = 'male') then inc(counter);
    writeln('stpds in A-13-10: ', counter);
end;
end.