program kys;
uses external_sort;

var
    len, counter: integer;
    f1, f, sf, ff: TextFile;
    t1, t2, t3, t4: System.DateTime;


begin
    if ParamCount < 2 then
    begin
        writeln('Недостаточно параметров');
        exit;
    end;

    AssignFile(f1, ParamStr(1));
    AssignFile(f, ParamStr(2));
    AssignFile(ff, 'D:\labs\txts\ff.txt');
    AssignFile(sf, 'D:\labs\txts\sf.txt');

    Reset(f1);
    Rewrite(f);
    readln(f1, len);
    copy_file(f1, f);
    CloseFile(f1);
    CloseFile(f);

    writeln(ParamStr(1));
    // writeln(len);
    writeln('UwU');
    writeln('UwU');

    counter := 1;

    while counter < len do
    begin
        
        Reset(f);
        Rewrite(ff);
        Rewrite(sf);
        divide_file(f, ff, sf, len, counter);
        CloseFile(f);
        CloseFile(ff);
        CloseFile(sf);

        Rewrite(f);
        Reset(ff);
        Reset(sf);
        concat_files(f, ff, sf, counter, len);
        CloseFile(f);
        CloseFile(ff);
        CloseFile(sf);
        

        counter *= 2;
        writeln(counter);
    end;

    writeln('UwU');


    
end.