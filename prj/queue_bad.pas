unit btree;
    
interface

type
    Stack = record
        s, e: integer := 0;
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
            if Self.e + 2 < Self.array_len then
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
            inc(Self.s);
        end;

        procedure destroy();
        begin
            while not Self.is_empty do
                Self.pop(Self.top);
        end;

    end;
implementation
    

    
end.