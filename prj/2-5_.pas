program no_game_no_life;

uses types, compare_funcs, sort_in_array, sort_in_file, to_typed_file;

var
    f: TextFile;
    tf: file of Student;
    arr: array of Student;


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

    AssignFile(tf, 'D:\labs\nt.fs');
    Reset(tf);
    copy_to_typed_file(f, tf);
    CloseFile(tf);

    Reset(tf);
    try
        AssignFile(f, ParamStr(2));
        Rewrite(f);
    except
        writeln('Невозможно открыть файл ''', Paramstr(2), ''' для записи');
        exit;
    end;


    // read_in_array(arr, tf);
    // quick_sort(arr, 0, high(arr), scholarship_sort);
    // write_in_text_file(arr, f);
    // writeln(f);
    // quick_sort(arr, 0, high(arr), group_and_date_sort);
    // write_in_text_file(arr, f);
    // write_stupids(arr);
    // write_count_of_stupids(arr);


    pickme_sort(tf, scholarship_sort);
    write_in_file(tf, f);
    writeln(f);
    pickme_sort(tf, group_and_date_sort);
    write_in_file(tf, f);
    write_stupids(tf);
    write_count_of_stupids(tf);

    CloseFile(f);
    CloseFile(tf);

end.