program ArrayForm;

const
    nmax = 10;

type
    matrix = array [1..nmax, 1..nmax] of integer;
    arr_type = array [1..nmax * nmax] of integer;

var
    a, b, c:    matrix;
    ma, na, mb, nb, mc, nc: integer;
    pa, pb, pc: integer;

    d, e, f:    arr_type;
    nd, ne, nf: integer;
    arrm2, arrm3: real;
    ff: TextFile;


procedure input(var mx: matrix; var n: integer; var m: integer; var p: integer);
begin
    writeln('werwer');
    read(ff, p);
    read(ff, n);
    read(ff, m);
    writeln(p);
    writeln(n, m);
    for i: integer := 1 to n do for j: integer := 1 to m do read(ff, mx[i, j]);
end;


procedure form_array(var mx: matrix; var arr: arr_type; p: integer; var nn: integer; i_bg, i_end, j_bg, j_end: integer);
begin
    for i: integer := i_bg to i_end do
    begin
        for j: integer := j_bg to j_end do
        begin
            writeln(mx[i,j]);
            if mx[i, j] <> p then
            begin
                nn += 1;
                arr[nn] := mx[i, j];
            end;
        end;
    end;
end;


function mean(var arr: arr_type; n: integer): real;
begin
    result := 0;
    for i: integer := 1 to n do result += arr[i];
    result := result / n
end;


procedure left_shift(var arr: arr_type; n: integer; ii: integer);
begin
    for i: integer := ii to n-1 do
    begin
        arr[i] := arr[i+1];
    end;
end;


function change_array(var arr: arr_type; n: integer; m: real): integer;
begin
    var i: integer := 1;
    while i <= n do
    begin
        if arr[i-result] > m then
        begin
            left_shift(arr, n, i-result);
            result += 1;
        end;
        i += 1;
    end;
end;


procedure output(var arr: arr_type; n: integer);
begin
    for i: integer := 1 to n do 
    begin
        write(ff, arr[i]);
        write(ff, ' ');
    end;
    writeln(ff, '');
end;

begin
if ParamCount < 2 then
    writeln('Недостаточно параметров!')
else
begin
    if not FileExists(ParamStr(1)) then
            writeln('Невозможно открыть файл ''', ParamStr(1), ''' для чтения')
        else
        begin
            AssignFile(ff, ParamStr(1));
            Reset(ff);

            input(a, na, ma, pa);
            input(b, nb, mb, pb);
            input(c, nc, mc, pc);

            if ma mod 2 <> 0 then
                form_array(a, d, pa, nd, 1, na, ma div 2 + 2, ma)
            else
                form_array(a, d, pa, nd, 1, na, ma div 2 + 1, ma);
            form_array(b, e, pb, ne, 1, nb div 2, 1, mb);
            if nc mod 2 <> 0 then
                form_array(c, f, pc, nf, nc div 2 + 2, nc, 1, mc)
            else
                form_array(c, f, pc, nf, nc div 2 + 1, nc, 1, mc);

            if ne <> 0 then
            begin
                arrm2 := mean(e, ne);
                nd := nd - change_array(d, nd, arrm2);
                if nf <> 0 then
                begin
                    arrm3 := mean(f, nf);
                    ne := ne - change_array(e, ne, arrm3);
                end;
            end;

            CloseFile(ff);

            AssignFile(ff, ParamStr(2));
            Rewrite(ff);

            output(d, nd);
            output(e, ne);
            output(f, nf);

            CloseFile(ff);
        end;        
end;
end.