unit deque_bad;
    
interface

type
    Deque = record
        s: integer := 0;
        e: integer := 0;
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
            if Self.e + 2 > Self.array_len then
            begin
                SetLength(Self.data, Self.array_len + 5);
                Self.array_len += 5;
            end;
            Self.data[Self.e] := el;
            inc(Self.e);
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
            if Self.e + 2 > Self.array_len then
            begin
                SetLength(Self.data, Self.array_len + 5);
                Self.array_len += 5;
            end;

            for i: integer := e - 1 downto s do
            begin
                Self.data[i + 1] := Self.data[i];
            end;
            Self.data[s] := el;
            inc(Self.e);
        end;

        function get_first(): real;
        begin
            result := Self.data[Self.s];
            inc(Self.s);
        end;
        
        function get_last(): real;
        begin
            result := Self.data[Self.e - 1];
            dec(Self.e);
        end;

        function pop(): real;
        begin
            result := Self.get_last;
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
            writeln(';');
            for i: integer := Self.e - 1 downto Self.s do
            begin
                writeln(Self.data[i]);
            end;
            writeln();
        end;

    end;
implementation

    
end.