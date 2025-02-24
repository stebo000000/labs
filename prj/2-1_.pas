program MySet;
uses my_set;

var
    a, b, c, r: UsherbSet;
    f: TextFile;
    ch: char;

begin
     if ParamCount < 2 then
    begin
        writeln('Недостаточно параметров');
        exit;
    end;
    try
        AssignFile(f, ParamStr(1));
        Reset(f);
    except
        writeln('Невозможно открыть файл ''', Paramstr(1), ''' для чтения');
        exit;
    end;
    a := [];
    while not eoln(f) do
    begin
        read(f, ch);
        a += ch;
    end;
    readln(f);
    b := [];
    while not eoln(f) do
    begin
        read(f, ch);
        b += ch;
    end;
    readln(f);
    c := [];
    while not eoln(f) do
    begin
        read(f, ch);
        c += ch;
    end;
    CloseFile(f);

    try
        AssignFile(f, ParamStr(2));
        Rewrite(f);
    except
        writeln('Невозможно открыть файл ''', Paramstr(2), ''' для записи');
        exit;
    end;

     write(f, 'a: [');
    for ch := chr(0) to chr(255) do
        if ch in a then
            write(f, ch);
    writeln(f, ']');
     write(f, 'b: [');
    for ch := chr(0) to chr(255) do
        if ch in b then
            write(f, ch);
    writeln(f, ']');
     write(f, 'c: [');
    for ch := chr(0) to chr(255) do
        if ch in  c then
            write(f, ch);
    writeln(f, ']');

    write(f, 'Union: [');
    r := a + b;
    for ch := chr(0) to chr(255) do
        if ch in r then
            write(f, ch);
    writeln(f, ']');
    write(f, 'Intersection: [');
    r := a * b;
    for ch := chr(0) to chr(255) do
        if ch in r then
            write(f, ch);
    writeln(f, ']');
    write(f, 'Difference:    [');
    r := b - c;
    for ch := chr(0) to chr(255) do
        if ch in r then
            write(f, ch);
    writeln(f, ']');
    write(f, 'task:   [');
    r := (a * b) - (b - c);
    for ch := chr(0) to chr(255) do
        if ch in r then
            write(f, ch);
    writeln(f, ']');
    CloseFile(f);
end.