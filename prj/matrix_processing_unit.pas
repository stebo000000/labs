unit matrix_processing_unit;
    
interface
    function negative_row_in_matrix(const mx: array of array of integer): integer;
    procedure array_processing(var arr: array of integer);
    procedure replace_zeros(var mx: array of array of integer; const num: integer);

implementation
    function negative_row_in_matrix(const mx: array of array of integer): integer;
    var
        row: integer := high(mx);
        var column: integer;
    begin
        result := -1;
        while (row >= 0) and (result = -1) do
        begin
            column := high(mx[0]);
            while (column >= 0) and (result = -1) do
            begin
                if mx[row][column] < 0 then result := row;
                column -= 1;
            end;
            row -= 1;
        end;
    end;

    procedure array_processing(var arr: array of integer);
    var
        temp_num: integer;
    begin
        if high(arr) = 0 then raise Exception.Create('Get array with zero length');
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