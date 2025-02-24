unit unit12;

interface
uses types;

function mean(var mx: matrix; n, m: integer; f: func): real;
function f2(x: integer): integer;
function f1(x: integer): integer;
function form_vector(var mx: matrix; n, m: integer): vector;
function find_max(var mx: matrix; n, m: integer): integer;

implementation

function f1(x: integer): integer;
begin
    result := x;
end;


function f2(x: integer): integer;
begin
    result := -x;
end;

function mean(var mx: matrix; n, m: integer; f: func): real;
begin
    var counter: integer := 0;
    for i: integer := 1 to n do
    begin
        for j: integer := 1 to m do
        begin
            if f(mx[i, j]) >= 0 then
            begin
                result += mx[i, j];
                counter += 1;
            end;
        end;
    end;
    result := result / counter;

end;

function form_vector(var mx: matrix; n, m: integer): vector;
begin
    var is_negative: boolean;
    var j: integer := 1;

    for i: integer := 1 to m do
    begin
        j := 1;
        is_negative := false;
        while (j <= n) and (not is_negative) do
        begin
            if mx[j, i] < 0 then
            begin
                is_negative := true;
                result[i] := 0;
            end;
            j += 1;
        end;
        if not is_negative then result[i] := 1;
    end;
end;


function find_max(var mx: matrix; n, m: integer): integer;
begin
    result := mx[1, 1];
    for i: integer := 1 to n do
        for j: integer := 1 to m do
            if (mx[i, j]) >= result then result := mx[i, j];

end;
        

initialization

finalization

end.