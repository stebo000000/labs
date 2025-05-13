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

    my_btr.fill(f);
    my_btr.write_btr();

    my_node := my_btr.find(9);
    writeln('add after: ', my_node^.data);
    my_btr.add_left(my_node, 0);
    my_btr.write_btr();

    my_node := my_btr.find(9);
    my_btr.delete_sub_btr(my_node);
    my_btr.write_btr();

    count_of_negative := my_btr.count();
    writeln('count of negative: ', count_of_negative);
    my_btr.delete_sub_btr(my_btr.root);

end.