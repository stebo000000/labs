unit sort_functions;
    
interface
    procedure bubble_sort(var arr: array of integer);
    procedure pickme_sort(var arr: array of integer);
    procedure insert_sort(var arr: array of integer);
    procedure quick_sort(var arr: array of integer; s, e : integer);
    procedure bubble_sort(var arr: array of string);
    procedure pickme_sort(var arr: array of string);
    procedure insert_sort(var arr: array of string);
    procedure quick_sort(var arr: array of string; s, e : integer);

    
implementation

procedure bubble_sort(var arr: array of integer);
var buffer: integer;
begin
    for j: integer := 0 to high(arr) - 1 do
        for i: integer := 0 to high(arr) - 1 do
        begin
            if arr[i] > arr[i+1] then
            begin
                buffer := arr[i];
                arr[i] := arr[i+1];
                arr[i+1] := buffer;
            end;
        end;
end;

procedure bubble_sort(var arr: array of string);
var 
    buffer: string;
begin
    for j: integer := 0 to high(arr) - 1 do
        for i: integer := 0 to high(arr) - 1 do
        begin
            if arr[i] > arr[i+1] then
            begin
                buffer := arr[i];
                arr[i] := arr[i+1];
                arr[i+1] := buffer;
            end;
        end;
end;

procedure pickme_sort(var arr: array of integer);
var
    local_min: integer;
    local_min_i: integer;
begin
    for current_i : integer := 0 to high(arr) - 1 do
    begin
        local_min := arr[current_i];
        local_min_i := current_i;
        for i : integer := current_i + 1 to high(arr) do
        begin
            if arr[i] < arr[local_min_i] then
            begin
                local_min := arr[i];
                local_min_i := i;
            end;
        end;
        arr[local_min_i] := arr[current_i];
        arr[current_i] := local_min;

    end;
    
end;

procedure pickme_sort(var arr: array of string);
var
    local_min: string;
    local_min_i: integer;
begin
    for current_i : integer := 0 to high(arr) - 1 do
    begin
        local_min := arr[current_i];
        local_min_i := current_i;
        for i : integer := current_i + 1 to high(arr) do
        begin
            if arr[i] < arr[local_min_i] then
            begin
                local_min := arr[i];
                local_min_i := i;
            end;
        end;
        arr[local_min_i] := arr[current_i];
        arr[current_i] := local_min;

    end;
    
end;


procedure insert_sort(var arr: array of integer);
var
    i: integer;
    buffer: integer;
begin
    for current_i: integer := 1 to high(arr) do
    begin
        i := current_i;
        while (i > 0) and (arr[i-1] > arr[i]) do
        begin
            buffer := arr[i-1];
            arr[i-1] := arr[i];
            arr[i] := buffer;
            dec(i);
        end;
    end;
end;

procedure insert_sort(var arr: array of string);
var
    i: integer;
    buffer: string;
begin
    for current_i: integer := 1 to high(arr) do
    begin
        i := current_i;
        while (i > 0) and (arr[i-1] > arr[i]) do
        begin
            buffer := arr[i-1];
            arr[i-1] := arr[i];
            arr[i] := buffer;
            dec(i);
        end;
    end;
end;


procedure quick_sort(var arr: array of integer; s, e : integer);
var 
    pivot: integer := arr[s];
    sep_point: integer := s;
    buffer: integer;
begin
    if s < e then
    begin
        for i: integer := s + 1 to e do
        begin
            if arr[i] < pivot then
            begin
                buffer := arr[sep_point];
                arr[sep_point] := arr[i];
                arr[i] := buffer;
                inc(sep_point);
            end;
        end;

        if sep_point = s then
            inc(sep_point);
        quick_sort(arr, s, sep_point - 1);
        quick_sort(arr, sep_point, e);
    end;
end;

procedure quick_sort(var arr: array of string; s, e : integer);
var 
    pivot: string := arr[s];
    sep_point: integer := s;
    buffer: string;
begin
    if s < e then
    begin
        // writeln(s, ' ', e);
        for i: integer := s + 1 to e do
        begin
            if arr[i] < pivot then
            begin
                buffer := arr[sep_point];
                arr[sep_point] := arr[i];
                arr[i] := buffer;
                inc(sep_point);
            end;
        end;

        // writeln(sep_point);
        if sep_point = s then
            inc(sep_point);
        quick_sort(arr, s, sep_point - 1);
        quick_sort(arr, sep_point, e);
    end;
end;

    
end.