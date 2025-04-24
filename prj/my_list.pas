unit my_list;
    
interface


type
    ULE = record
        next_el_pointer: ^ULE;
        data: real;
    end;

    UnidirectionalList = record
        first_el_pointer: ^ULE;
    
        private
        procedure sub_destroy(current: ^ULE);
        var new_el: ^ULE;
        begin
            if current^.next_el_pointer <> nil then
            begin
                new_el := current^.next_el_pointer;
                current^.next_el_pointer := nil;
                Self.sub_destroy(new_el);
            end;
            new_el := current^.next_el_pointer;
            current^.next_el_pointer := nil;
            dispose(new_el);
        end;

        procedure delete_el(var target: ^ULE);
        var
            current: ^ULE := Self.first_el_pointer;
            new_el: ^ULE;
        begin
            while current^.next_el_pointer <> target do current := current^.next_el_pointer;
            current^.next_el_pointer := target^.next_el_pointer;
            dispose(target);
            target := current^.next_el_pointer;
        end;


        public
        procedure insert_after(el: real; target: ^ULE);
        var
            new_el: ^ULE;
        begin
            new(new_el);
            new_el^.next_el_pointer := target^.next_el_pointer;
            new_el^.data := el;

            target^.next_el_pointer := new_el;
        end;

        procedure init();
        begin
            Self.first_el_pointer := nil;
        end;


        function return_first_negative(): ^ULE;
        var
            current: ^ULE := Self.first_el_pointer;
            new_el: ^ULE;
        begin
            while (current^.next_el_pointer <> nil) and (current^.data >= 0) do current := current^.next_el_pointer;
            result := current;
        end;

        procedure delete_all_negative();
        var
            current: ^ULE := Self.first_el_pointer;
        begin
            begin
                while current <> nil do 
                begin
                    if current^.data < 0 then
                    begin
                        if Self.first_el_pointer = current then Self.first_el_pointer := current^.next_el_pointer;
                        Self.delete_el(current)
                    end
                    else
                    current := current^.next_el_pointer;
                end;
            end;
        end;

        procedure destroy();
        begin
            Self.sub_destroy(Self.first_el_pointer);
        end;

        procedure insert_by_rule(el: real);
        var
            current: ^ULE := Self.first_el_pointer;
            new_el: ^ULE;
        begin
            if current = nil then 
            begin
                new(new_el);
                new_el^.next_el_pointer := nil;
                new_el^.data := el;

                Self.first_el_pointer := new_el;
            end
            else if current^.data < el then
            begin
                new(new_el);
                new_el^.next_el_pointer := current^.next_el_pointer;
                new_el^.data := current^.data;

                current^.next_el_pointer := new_el;
                current^.data := el;
            end
            else
            begin
                while (current^.next_el_pointer <> nil) and (current^.next_el_pointer^.data > el) do
                begin
                    current := current^.next_el_pointer;
                end; 

                Self.insert_after(el, current);
            end;
        end;
        
        procedure append(el: real);
        var
            current: ^ULE := Self.first_el_pointer;
            new_el: ^ULE;
        begin
            if Self.first_el_pointer = nil then
            begin
                new(new_el);
                new_el^.next_el_pointer := nil;
                new_el^.data := el;

                Self.first_el_pointer := new_el;
            end
            else
            begin
                while current^.next_el_pointer <> nil do 
                begin
                    current := current^.next_el_pointer;
                end;

                Self.insert_after(el, current);
            end;
        end;

        procedure insert_first(el: real);
        var
            current: ^ULE := Self.first_el_pointer;
            new_el: ^ULE;
        begin

            if current = nil then
            begin
                new(new_el);
                new_el^.next_el_pointer := nil;
                new_el^.data := el;

                Self.first_el_pointer := new_el;
            end
            else
            begin
                new(new_el);
                new_el^.next_el_pointer := current;
                new_el^.data := el;

                Self.first_el_pointer := new_el;
            end;
        end;

        procedure write_list();
        var
            current: ^ULE := Self.first_el_pointer;
        begin
            while current <> nil do 
            begin
                writeln(current^.data);
                current := current^.next_el_pointer;
            end;
            writeln('');
        end;
    end;
    
implementation
    

    
end.