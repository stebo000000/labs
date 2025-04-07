unit matrix_processing_unit;
    
interface
    function negative_row_in_matrix(const mx: array of array of integer): integer;
    procedure array_processing(var arr: array of integer);
    procedure replace_zeros(var mx: array of array of integer; const num: integer);

implementation
    function is_negative_elemrnt_in_row(const row: array of integer): boolean;
    var
        column: integer;
    begin
        result := false;
        column := high(row);
        while (column >= 0) and not result do
            begin
                if row[column] < 0 then result := true;
                column -= 1;
            end;
    end;
    function negative_row_in_matrix(const mx: array of array of integer): integer;
    var
        row: integer := high(mx);
    begin
        result := -1;
        while (row >= 0) and (result = -1) do
        begin
            if is_negative_elemrnt_in_row(mx[row]) then result := row;            
            row -= 1;
        end;
    end;

    procedure array_processing(var arr: array of integer);
    var
        temp_num: integer;
    begin
        for i: integer := 0 to (high(arr) div 2 - 1) do
        begin
            temp_num := arr[high(arr) - i];
            arr[high(arr) - i] := arr[i];
            arr[i] := temp_num;
        end;
    end;

    procedure replace_zeros(var mx: array of array of integer; const num: integer);
    begin
        for i: integer := 0 to high(mx) do
            for j: integer := 0 to high(mx[i]) do 
                if mx[i][j] = 0 then
                    mx[i][j] := num;
    end;


initialization

finalization

end.