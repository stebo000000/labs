program no_game_no_life;

uses my_list;

var
    f: TextFile;
    list: UnidirectionalList;
    fn, ln: ^ULE;


procedure input(var list: UnidirectionalList; f: TextFile);
var buffer: real;
begin
    while not eof(f) do
    begin
        readln(f, buffer);
        list.append(buffer);
    end;
end;


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


end.