unit io;

interface
uses types;

const
    nmax = 10;

procedure input(var mx: matrix; var n: integer; var m: integer; var f: TextFile);
procedure output(value: integer; var f: TextFile);

implementation

procedure input(var mx: matrix; var n: integer; var m: integer; var f: TextFile);
begin
    read(f, n);
    read(f, m);
    for i: integer := 1 to n do for j: integer := 1 to m do read(f, mx[i, j]);
end;


procedure output(value: integer; var f: TextFile);
begin
    if value = -1 then
        writeln(f, 'all elements are positive!')
    else
        writeln(f, value);
end;

initialization

finalization

end.