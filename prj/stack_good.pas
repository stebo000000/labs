unit btree;
    
interface

type
    SE = record
        data: real;
        next: ^SE;
    end;

    Stack = record
        top: ^SE;

        function is_empty(): boolean;
        begin
            result := (Self.top = nil);
        end;

        procedure append(el: real);
        var new_el: ^SE;
        begin
            new(new_el);
            new_el^.data := el;
            new_el^.next := Self.top;
            Self.top := new_el;
        end;

        function pop(): real;
        var el_to_delete: ^SE;
        begin
            el_to_delete := Self.top;
            Self.top := Self.top^.next;
            dispose(el_to_delete);
        end;

        procedure destroy();
        begin
            while not Self.is_empty do
                Self.pop(Self.top);
        end;

        procedure scan();
        var current_el: ^SE := Self.top;
        begin
            while current_el <> nil do
            begin
                writeln(current_el^.data);
                current_el := current_el^.next;
            end;
        end;

    end;
implementation
    

    
end.