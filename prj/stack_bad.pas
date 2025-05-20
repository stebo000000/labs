unit stack_bad;
    
interface

type
    Stack = record
        len: integer := 0;
        array_len: integer := 0;
        data: array of real;

        function is_empty(): boolean;
        begin
            result := (Self.len = 0);
        end;

        procedure append(el: real);
        begin
            if Self.len + 1 > Self.array_len then
            begin
                SetLength(Self.data, Self.array_len + 5);
                Self.array_len += 5;
            end;

            Self.data[Self.len] := el;
            inc(Self.len);
        end;

        function pop(): real;
        begin
            result := Self.data[Self.len];
            if Self.len + 5 < Self.array_len then
            begin
                SetLength(Self.data, Self.array_len - 5);
                Self.array_len -= 5;
            end;
            dec(Self.len);
        end;

        procedure destroy();
        begin
            Self.len := 0;
            SetLength(Self.data, 5);
            array_len := 5;
        end;

        procedure scan();
        begin
            for i: integer := 0 to Self.len - 1 do
            begin
                writeln(Self.data[i]);
            end;
            writeln();
        end;

    end;
implementation
    

    
end.