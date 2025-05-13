program no_game_no_life;

uses my_list;

var
    f: TextFile;
    lst: List;
    fn, ln: LE;


procedure input(var lst: List; f: TextFile);
var buffer: real;
begin
    while not eof(f) do
    begin
        readln(f, buffer);
        lst.append(buffer);
    end;
end;


procedure right_input(var lst: List; f: TextFile);
var buffer: real;
begin
    while not eof(f) do
    begin
        readln(f, buffer);
        lst.insert_by_rule(buffer);
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

    lst.init();
    input(lst, f);
    writeln('first input');
    lst.write_list();
    lst.append(-5.8);
    lst.insert_first(0.1);
    writeln('insert first & append');
    lst.write_list();

    lst.search(fn, ln);
    if fn <> nil then
        lst.insert_after(0.2, fn);
    writeln('insert after negative');
    lst.write_list();
    
    lst.delete_all_negative();
    writeln('del all neg');
    lst.write_list();

    lst.destroy();

    Reset(f);

    lst.init();
    right_input(lst, f);
    writeln('right input');
    lst.write_list();
    lst.search(fn, ln);
    if fn <> nil then
        writeln('neg: ', fn^.data);
    lst.delete_all_negative();
    writeln('del all neg');
    lst.write_list();
    lst.destroy();
end.