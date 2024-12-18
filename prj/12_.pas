program Lab12;

uses unit12, types, io12;

var
    f: TextFile;
    a, b: matrix;

    na, nb, nc: integer;
    ma, mb, mc: integer;

    mean_a1, mean_b1, mean_a2, mean_b2: real;

    y: vector;
    max: integer;
                         

begin
if ParamCount < 2 then
    writeln('Недостаточно параметров!')
else
begin
    if not FileExists(ParamStr(1)) then
            writeln('Невозможно открыть файл ''', ParamStr(1), ''' для чтения')
    else
    begin

        AssignFile(f, ParamStr(1));
        Reset(f);
        
        input(a, na, ma, f);
        input(b, nb, mb, f);

        CloseFile(f);
        AssignFile(f, ParamStr(2));
        Rewrite(f);

        mean_a1 := mean(a, na, ma, f1);
        mean_b1 := mean(b, nb, mb, f1);
        mean_a2 := mean(a, na, ma, f2);
        mean_b2 := mean(b, nb, mb, f2);

        if mean_a1 <> mean_b1 then
        begin
            if mean_a1 < mean_b1 then
            begin
                y := form_vector(a, na, ma);
                max := find_max(b, nb, mb);
                output_vector(y, na, f);
            end
            else
            begin
                y := form_vector(b, nb, mb);
                max := find_max(a, na, ma);
                output_vector(y, mb, f);
            end;
            output(max, f);
        end
        else
            output_error(f);

        
        if mean_a2 <> mean_b2 then
        begin
            if mean_a2 < mean_b2 then
            begin
                y := form_vector(a, na, ma);
                max := find_max(b, nb, mb);
                output_vector(y, na, f);
            end
            else
            begin
                y := form_vector(b, nb, mb);
                max := find_max(a, na, ma);
                output_vector(y, mb, f);
            end;
            output(max, f);
        end
        else
            output_error(f);

        CloseFile(f);
    end;
end;
end.