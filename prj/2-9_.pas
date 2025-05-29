program no_game_no_life;
uses syntax;

var
    f: TextFile;

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

    writeln(is_correct(f));
end.