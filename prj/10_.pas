program Lab12;

uses units, types, io;

const
    nmax = 10;

var
    f: TextFile;
    a, b, c: matrix;    
    na, nb, nc: integer;
    ma, mb, mc: integer;
    pa, pb, pc, pat, pbt, pct: integer;


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
        input(c, nc, mc, f);

        pa := calculate_absolute_value(a, na, ma);
        pb := calculate_absolute_value(b, nb, mb);
        pc := calculate_absolute_value(c, nc, mc);

        trans(a, na, ma);
        trans(b, nb, mb);
        trans(c, nc, mc);
        
        pat := calculate_absolute_value(a, na, ma);
        pbt := calculate_absolute_value(b, nb, mb);
        pct := calculate_absolute_value(c, nc, mc);

        CloseFile(f);
        AssignFile(f, ParamStr(2));
        Rewrite(f);

        if (pa = -1) or (pb = -1) or (pc = -1) then
            output(-1, f)
        else
            output(pa + pb*pc, f);
        if (pat = -1) or (pbt = -1) or (pct = -1) then
            output(-1, f)
        else
            output(pat + pbt*pct, f);

        CloseFile(f);
    end;
end;
end.