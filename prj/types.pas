unit types;

interface

const
    nmax = 10;

type
    matrix = array [1..nmax, 1..nmax] of integer;
    func = function(x: integer): integer;
    vector = array [1..nmax] of integer;

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