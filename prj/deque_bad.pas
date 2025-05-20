unit btree;
    
interface

type
    Stack = record
        s, e: integer := 0;
        array_len: integer := 5;
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

        procedure insert_first(el: real);
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

            for i: integer := e - 1 downto s do
            begin
                Self.data[i + 1] := Self.data[i];
            end;
            Self.data[s] := el;
            inc(Self.len);
        end;

        function get_first(): real;
        var el_to_delete: ^SE;
        begin
            result := Self.data[Self.s];
            inc(Self.s);
        end;
        
        function get_last(): real;
        var el_to_delete: ^SE;
        begin
            result := Self.data[Self.e - 1];
            dec(Self.s);
        end;

        function pop(): real;
        begin
            result := Self.get_last;
        end;

        procedure destroy();
        begin
            while not Self.is_empty do
                Self.pop(Self.top);
        end;

    end;
implementation
    

    
end.