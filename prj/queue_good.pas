unit btree;
    
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
            Self.bottom^.next := new_el;
            Self.bottom := new_el;

            if Self.top = nil then
                Self.top := Self.bottom;
        end;

        function pop(): real;
        var el_to_delete: ^SE;
        begin
            el_to_delete := Self.top;
            Self.top := Self.top^.next;
            dispose(el_to_delete);

            if Self.top = nil then
                Self.bottom := Self.top;
        end;

        procedure destroy();
        begin
            while not Self.is_empty do
                Self.pop(Self.top);
        end;

    end;
implementation
    

    
end.