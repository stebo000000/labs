unit my_set_chr;
    
interface
type
    UsherbSet = record
        len: integer := 0;
        values : array of char;
        
        {static procedure operator:=(new_set: array of char; var u_set: UsherbSet);
        begin
            u_set.len := 0;

            foreach var i in new_set do
            begin
                u_set.values[u_set.len] := i;
                u_set.len += 1;
            end;
        end;}

        static procedure operator+=(var u_set: UsherbSet; new_element: char);
        begin
            SetLength(u_set.values, u_set.len + 1);
            u_set.values[u_set.len] := new_element;
            u_set.len += 1;
        end;

        static function operator+(u_set1, u_set2: UsherbSet): UsherbSet;
        begin
            result.len := 0;
            for i: integer := 0 to u_set1.len - 1 do
                result += u_set1.values[i];
            for i: integer := 0 to u_set2.len - 1 do
                if u_set2.values[i] not in u_set1 then
                    result += u_set2.values[i];
        end;

        static function operator*(u_set1, u_set2: UsherbSet): UsherbSet;
        begin
            result.len := 0;
            for i: integer := 0 to u_set1.len - 1 do
                if u_set1.values[i] in u_set2 then
                    result += u_set1.values[i];
                
        end;
        
        static function operator-(u_set1, u_set2: UsherbSet): UsherbSet;
        begin
            result.len := 0;
            for i: integer := 0 to u_set1.len - 1 do
                if u_set1.values[i] not in u_set2 then
                    result += u_set1.values[i];
        end;

        static function operator in(ch: char; u_set: UsherbSet): boolean;
        var
            i: integer := 0;
        begin
            result := false;
            while (i < u_set.len) and not result do
            begin
                if ch = u_set.values[i] then result := true;
                i += 1;
            end;
        end;

        static function operator implicit(new_set: set of char): UsherbSet;
        begin
            result.len := 0;
            foreach var i in new_set do
            begin
                SetLength(result.values, result.len + 1);
                result.values[result.len] := i;
                result.len += 1;
            end;
        end;

    end;
    
implementation

initialization

finalization

end.