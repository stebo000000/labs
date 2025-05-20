unit deque_good;
    
interface

type
    DE = record
        data: real;
        next: ^DE;
        prev: ^DE;
    end;

    Deque = record
        top: ^DE;
        bottom: ^DE;

        function is_empty(): boolean;
        begin
            result := (Self.top = nil);
        end;

        procedure append(el: real);
        var new_el: ^DE;
        begin
            new(new_el);
            new_el^.data := el;
            if Self.bottom <> nil then
                Self.bottom^.next := new_el;
            new_el^.prev := Self.bottom;
            Self.bottom := new_el;

            if Self.top = nil then
                Self.top := Self.bottom;
        end;

        procedure insert_first(el: real);
        var new_el: ^DE;
        begin
            new(new_el);
            new_el^.data := el;
            if Self.top <> nil then
                Self.top^.prev := new_el;
            new_el^.next := Self.top;
            Self.top := new_el;

            if Self.bottom = nil then
                Self.bottom := Self.top;
        end;

        function get_first(): real;
        var el_to_delete: ^DE;
        begin
            el_to_delete := Self.top;
            if Self.top^.next <> nil then
                Self.top^.next^.prev := nil;
            Self.top := Self.top^.next;
            result := el_to_delete^.data;
            dispose(el_to_delete);

            if Self.top = nil then
                Self.bottom := Self.top;
        end;
        
        function get_last(): real;
        var el_to_delete: ^DE;
        begin
            el_to_delete := Self.bottom;
            if Self.bottom^.prev <> nil then
                Self.bottom^.prev^.next := nil;
            Self.bottom := Self.bottom^.prev;
            result := el_to_delete^.data;
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
                Self.pop();
        end;

        procedure scan();
        var current_el: ^DE := Self.top;
        begin
            while current_el <> nil do
            begin
                writeln(current_el^.data);
                current_el := current_el^.next;
            end;
            writeln();
        end;

    end;
implementation
    

    
end.