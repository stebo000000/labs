program Geometry;

var
    xc, r: real;
    xt, a, b: real;
    p, a1, b1, c1: real;

begin
    writeln('Введите координату центра круга и радиус круга: ');
    readln(xc, r);

    writeln('Введите координату прямого угла, сторону a и b: ');
    readln(xt, a, b);

    if (a > 0) and (r > 0) and (b > 0) then
        begin
            a1 := r;
            b1 := b - abs(xc - xt);
            c1 := ((b - r - abs(xc - xt))*(b1 + r))**0.5;
            p := (a1 + b1 + c1)/2;

            if (abs(xc - xt) > b + r) or ((xt - xc > 0) and (xt - xc > r)) then
                begin
                    writeln('не пересекаются');
                end

            else if (((b <= (r + abs(xc - xt))) and (a = (r**2 - abs(xc - xt)**2)**0.5) and (abs(xt - xc) < r)) or ((b = (r + abs(xc - xt))) and (a <= (r**2 - abs(xc - xt)**2)**0.5) and (abs(xt - xc) < r))) or ((((a/(a**2 + b**2)**0.5) >= ((2*(p*(p - a1)*(p - b1)*(p - c1))**0.5)/(c1*b1))) and (abs(xc - xt) = r)) or (((a/(a**2 + b**2)**0.5) = ((2*(p*(p - a1)*(p - b1)*(p - c1))**0.5)/(c1*b1))) and (abs(xc - xt) >= r))) then
                writeln('фигуры касаются')

            else if ((b < r + abs(xc - xt)) and (a < (r**2 - abs(xc - xt)**2)**0.5) and (abs(xt - xc) < r)) then
                begin
                    writeln('треугольник внутри');
                end

            else if ((((a/(a**2 + b**2)**0.5) > ((2*(p*(p - a1)*(p - b1)*(p - c1))**0.5)/(c1*b1))) and (abs(xc - xt) > r))) then
                begin
                    writeln('круг внутри');
                end
            else
                writeln('пересекаются');
        
        
        end
    else
        writeln('данные не корректны');
    
end.