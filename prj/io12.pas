unit io12;

interface
uses types;

procedure output_error(var f: TextFile);
procedure output(value: integer; var f: TextFile);
procedure input(var mx: matrix; var n: integer; var m: integer; var f: TextFile);
procedure output_vector(var v: vector; n: integer; var f: TextFile);

implementation

procedure input(var mx: matrix; var n: integer; var m: integer; var f: TextFile);
begin
    read(f, n);
    read(f, m);
    for i: integer := 1 to n do for j: integer := 1 to m do read(f, mx[i, j]);
end;


procedure output_vector(var v: vector; n: integer; var f: TextFile);
begin
    for i: integer := 1 to n do
        write(f, v[i], ' ');
    writeln(f);

end;


procedure output(value: integer; var f: TextFile);
begin
    writeln(f, value);
end;

procedure output_error(var f: TextFile);
begin
    writeln(f, 'в обоих матрицах значения совпадают');
end;

initialization

finalization

end.