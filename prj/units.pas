unit units;

interface
uses types;

const
    nmax = 10;

function calculate_absolute_value(var mx: matrix; n, m: integer): integer;
procedure trans(var mx: matrix; n, m: integer);

implementation

function calculate_absolute_value(var mx: matrix; n, m: integer): integer;
begin
    result := 1;
    var is_negative: boolean := false;
    for i: integer := 1 to n do
        if mx[i, 1] < 0 then
            for j: integer := 1 to m do
                if mx[i, j] < 0 then
                begin
                    is_negative := true;
                    result := result * -mx[i, j];
                end;
    if not is_negative then result := -1;
end;


procedure trans(var mx: matrix; n, m: integer);
begin
    var temp: integer;
    for i: integer := 1 to n do
    begin
        for j: integer := i+1 to m do
        begin
            temp := mx[j, i];
            mx[j, i] := mx[i, j];
            mx[i, j] := temp;
        end;
    end;
end;


initialization

finalization

end.