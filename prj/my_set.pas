unit my_set;
    
interface
type
    UsherbSet = record
        values : array [0..255] of boolean;
        
        {static procedure operator:=(new_set: set of char; var u_set: UsherbSet);
        begin

            for i: integer := 0 to 255 do
                u_set.values[i] := false;

            for i: integer := 0 to new_set.Length - 1 do
                u_set.values[ord(new_set[i])] := true;
        end;}

        static procedure operator+=(var u_set: UsherbSet; new_element: char);
        begin
            u_set.values[ord(new_element)] := true;
        end;

        static function operator+(u_set1, u_set2: UsherbSet): UsherbSet;
        begin
            for i: integer := 0 to 255 do 
                if u_set1.values[i] or u_set2.values[i] then
                begin
                    result.values[i] := true;
                end
                else
                begin
                    result.values[i] := false;
                end;
        end;

        static function operator*(u_set1, u_set2: UsherbSet): UsherbSet;
        begin
            for i: integer := 0 to 255 do 
                if u_set1.values[i] and u_set2.values[i] then
                begin
                    result.values[i] := true;
                end
                else
                begin
                    result.values[i] := false;
                end;
        end;
        
        static function operator-(u_set1, u_set2: UsherbSet): UsherbSet;
        begin
            for i: integer := 0 to 255 do 
            begin
                result.values[i] := false;
                if u_set1.values[i] then
                    result.values[i] := true;
                if u_set2.values[i] then
                    result.values[i] := false

            end;
        end;

        static function operator in(ch: char; u_set: UsherbSet): boolean;
        begin
            result := u_set.values[ord(ch)];
        end;

        static function operator implicit(u_set: set of char): UsherbSet;
        begin
            for i: integer := 0 to 255 do 
            begin
                result.values[i] := false;
            end;
            foreach var ch in u_set do 
            begin
                result.values[ord(ch)] := true;
            end;
        end;
    end;
    
implementation

initialization

finalization

end.