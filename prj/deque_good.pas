unit btree;
    
interface

type
    DE = record
        data: real;
        next: ^QE;
        prev: ^QE;
    end;

    Deque = record
        top: ^QE;
        bottom: ^QE;

        function is_empty(): boolean;
        begin
            result := (Self.top = nil);
        end;

        procedure append(el: real);
        var new_el: ^QE;
        begin
            new(new_el);
            new_el^.data := el;
            Self.bottom^.next := new_el;
            Self.bottom := new_el;

            if Self.top = nil then
                Self.top := Self.bottom;
        end;

        procedure insert_first(el: real);
        var new_el: ^QE;
        begin
            new(new_el);
            new_el^.data := el;
            Self.top^.prev := new_el;
            Self.top := new_el;

            if Self.bottom = nil then
                Self.bottom := Self.top;
        end;

        function get_first(): real;
        var el_to_delete: ^SE;
        begin
            el_to_delete := Self.top;
            Self.top := Self.top^.next;
            dispose(el_to_delete);

            if Self.top = nil then
                Self.bottom := Self.top;
        end;
        
        function get_last(): real;
        var el_to_delete: ^SE;
        begin
            el_to_delete := Self.bottom;
            Self.bottom := Self.top^.prev;
            dispose(el_to_delete);

            if Self.bottom = nil then
                Self.top := Self.bottom;
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

        procedure scan();
        var current_el: ^DE := Self.top;
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