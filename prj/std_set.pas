unit std_set;
    
interface
type
    UsherbSet = record
        values : set of char;

        static procedure operator+=(var u_set: UsherbSet; new_element: char);
        begin
            u_set.values += [new_element];
        end;

        static function operator+(u_set1, u_set2: UsherbSet): UsherbSet;
        begin
            result.values := u_set1.values + u_set2.values
        end;

        static function operator*(u_set1, u_set2: UsherbSet): UsherbSet;
        begin
            result.values := u_set1.values * u_set2.values
        end;
        
        static function operator-(u_set1, u_set2: UsherbSet): UsherbSet;
        begin
            result.values := u_set1.values - u_set2.values
        end;

        static function operator in(ch: char; u_set: UsherbSet): boolean;
        begin
            result := ch in u_set.values;
        end;

        static function operator implicit(u_set: set of char): UsherbSet;
        begin
            result.values := u_set
        end;
    end;
    
implementation

initialization

finalization

end.