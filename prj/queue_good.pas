unit queue_good;
    
interface

type
    QE = record
        data: real;
        next: ^QE;
    end;

    Queue = record
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
            if Self.bottom <> nil then
                Self.bottom^.next := new_el;
            Self.bottom := new_el;

            if Self.top = nil then
                Self.top := Self.bottom;
        end;

        function pop(): real;
        var el_to_delete: ^QE;
        begin
            el_to_delete := Self.top;
            Self.top := Self.top^.next;
            result := el_to_delete^.data;
            dispose(el_to_delete);

            if Self.top = nil then
                Self.bottom := Self.top;
        end;

        procedure destroy();
        begin
            while not Self.is_empty do
                Self.pop();
        end;

        procedure scan();
        var current_el: ^QE := Self.top;
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