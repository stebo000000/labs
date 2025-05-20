unit queue_bad;
    
interface

type
    Queue = record
        s: integer := 0;
        e: integer := 0;
        array_len: integer := 0;
        data: array of real;

        function is_empty(): boolean;
        begin
            result := (Self.s = Self.e);
        end;

        procedure append(el: real);
        begin
            if Self.s = Self.e then
            begin
                Self.s := 0;
                Self.e := 0;
                SetLength(Self.data, 5);
                array_len := 5;
            end;
            if Self.e + 2 > Self.array_len then
            begin
                SetLength(Self.data, Self.array_len + 5);
                Self.array_len += 5;
            end;
            Self.data[Self.e] := el;
            inc(Self.e);
        end;

        function pop(): real;
        begin
            result := Self.data[Self.s];
            inc(Self.s);
        end;

        procedure destroy();
        begin
            Self.s := 0;
            Self.e := 0;
            SetLength(Self.data, 5);
            array_len := 5;
        end;


        procedure scan();
        begin
            for i: integer := Self.s to Self.e - 1 do
            begin
                writeln(Self.data[i]);
            end;
            writeln();
        end;

    end;
implementation
    

    
end.