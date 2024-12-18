program ArrayForm;

const
    nmax = 10;

type
    func = function(x: real): real;

var
    a, b, e: real;
    k: integer;
    ans11, ans12, ans13: real;
    ans21, ans22, ans23: real;


function func1(x: real): real;
begin
    result := (1/3)*(exp(-x) - power(exp(x), 0.5) + 3.7) - x;
end;


function func2(x: real):real;
begin
    result := power((ln(7.9) + exp(-x) - x*x/11), 0.5) - x;
end;


function iter(x, e: real; phi: func; k: real := 0.5): real;
begin
    var x0: real;
    repeat
        x0 := x;
        x := phi(x)*k+x;
    until (abs(x0 - x) < e);
    result := x;
end;


function sec(x1, x2, e: real; phi: func): real;
begin
    var x3: real;
    repeat
        x3 := x2 - phi(x2)*(x2 - x1)/(phi(x2) - phi(x1));
        x1 := x2;
        x2 := x3;
    until (abs(x1 - x2) < e);
    result := x3;
end;


function newton(x, e: real; phi: func): real;
begin
    var phi1, x0: real;
    repeat
        x0 := x;
        phi1 := (phi(x + e/2) - phi(x - e/2))/e;
        x := x0 - phi(x)/phi1;
    until (abs(x0 - x) < e);
    result := x;
end;


begin
    writeln('e: ');
    readln(e);
    k:=ceil(abs(log10(e)));
    writeln('a, b: ');
    readln(a,b);


    ans11:= iter((a+b)/2, e, func1);
    writeln('x:', ans11:(k+4):k, ' y', func1(ans11):(k+4):k);
    ans21 := iter((a+b)/2, e, Func2);
    writeln('x:', ans21:(k+4):k, ' y:', func2(ans21):(k+4):k);
    writeln();

    ans12 := sec(a,b,e, func1);
    writeln('x:', ans12:(k+4):k, ' y:', func1(ans12):(k+4):k);
    ans22 := sec(a,b,e, Func2);
    writeln('x:', ans22:(k+4):k, ' y:', func2(ans22):(k+4):k); 
    writeln();

    ans13 := newton((a+b)/2,e, func1);
    writeln('x:', ans13:(k+4):k, ' y:', func1(ans13):(k+4):k);
    ans23 := newton((a+b)/2,e, func2);
    writeln('x:', ans23:(k+4):k, ' y:', func2(ans23):(k+4):k);
  
end.