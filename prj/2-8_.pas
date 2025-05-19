program no_game_no_life;

uses btree;

var
    f: TextFile;
    my_btr: BTR;
    my_node: ^Node;
    count_of_negative: integer;

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