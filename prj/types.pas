unit types;

interface

const
    nmax = 10;

type
    Student = record 
        grp: string[100];
        fio: record
            first_name: string[100];
            surname: string[100];
            patronymic: string[100];
        end;
        year: integer;
        gender: string[100];
        marks: record
            phisics: integer;
            math: integer;
            comp_science: integer;
        end;
        scholarship: integer;
    end;

implementation
initialization
finalization
end.