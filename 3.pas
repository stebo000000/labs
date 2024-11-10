program Recursion;

var
    x, e, temp_e: real;
    s, y: real;
    a: real;
    i: integer;
    k: integer;

begin
    write('Введите аргумент: ');
    readln(x);
    write('Введите точность: ');
    readln(e);

    a := x*(2 - x) / 2;
    s := a;
    i := 2;
    while abs(a) > e do
    begin
        a := (x**4 * (4*i - 2 - x)) / ((4*i - 5)*(4*i - 4)*(4*i - 3)*(4*i - 2)*(4*i-6-x));
        s += a;
        i += 1;
    end;
    y := (sin(x) + cos(x) - exp(-x))/2;

    temp_e := e;
    k := 0;
    while trunc(temp_e) <> temp_e do
    begin
        temp_e := temp_e * 10;
        k += 1;
    end;

    writeln('Сумма ряда          = ', s:0:k);
    writeln('Контрольная формула = ', y:0:k);
  
end.