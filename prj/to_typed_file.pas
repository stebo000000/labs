unit to_typed_file;
    
interface
uses types;    
procedure copy_to_typed_file(f: TextFile; tf: file of Student);

implementation

procedure copy_to_typed_file(f: TextFile; tf: file of Student);
var stdnt: Student;
begin
    while not eof(f) do
    begin
        readln(f, stdnt.grp);
        readln(f, stdnt.fio.first_name);
        readln(f, stdnt.fio.surname);
        readln(f, stdnt.fio.patronymic);
        readln(f, stdnt.year);
        readln(f, stdnt.gender);
        readln(f, stdnt.marks.phisics);
        readln(f, stdnt.marks.math);
        readln(f, stdnt.marks.comp_science);
        readln(f, stdnt.scholarship);
        // write(stdnt);
        write(tf, stdnt);
    end;
end;
end.