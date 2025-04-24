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


procedure right_input(var list: UnidirectionalList; f: TextFile);
var buffer: real;
begin
    while not eof(f) do
    begin
        readln(f, buffer);
        list.insert_by_rule(buffer);
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

    list.init();
    input(list, f);
    list.write_list();
    list.append(-5.8);
    list.insert_first(0.1);
    list.write_list();

    fn := list.return_first_negative();
    list.insert_after(0.2, fn);
    list.write_list();
    
    list.delete_all_negative();
    list.write_list();

    list.destroy();

    Reset(f);

    list.init();
    right_input(list, f);
    list.write_list();
    fn := list.return_first_negative();
    writeln('neg: ', fn^.data);
    list.delete_all_negative();
    list.write_list();
    list.destroy();
end.