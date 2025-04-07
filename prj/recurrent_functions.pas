unit recurrent_functions;

interface
    function linear_compare(const arr: array of integer; current_index: integer):boolean;
    function cascad_multiply(const arr: array of integer; start_i, end_i: integer):integer;

implementation

    function linear_compare(const arr: array of integer; current_index: integer):boolean;
    begin
        if current_index = high(arr) then
            result := arr[current_index] < 0 ? true : false
        else
            result := (arr[current_index] < 0) ? true : linear_compare(arr, current_index + 1);
    end;


    function cascad_multiply(const arr: array of integer; start_i, end_i: integer):integer;
    begin
        if start_i = end_i then
            result := start_i * start_i > abs(arr[start_i]) ? arr[start_i] : 1
        else
            result := cascad_multiply(arr, (start_i + end_i) div 2 + 1, end_i) * cascad_multiply(arr, start_i, (end_i + start_i) div 2);
    end;

initialization

finalization

end.