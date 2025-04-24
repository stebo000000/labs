unit my_list;
    
interface


type
    BLE = record
        next_el_pointer: ^BLE;
        prev_el_pointer: ^BLE;
        data: real;
    end;

    BidirectionalList = record
        first_el_pointer: ^BLE;
        last_el_pointer: ^BLE;
    
        private
        procedure sub_destroy(current: ^BLE);
        var new_el: ^BLE;
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

        procedure delete_el(var target: ^BLE);
        begin
            target^.prev_el_pointer^.next_el_pointer := target^.next_el_pointer;
            dispose(target);
            target := current^.next_el_pointer;
        end;


        public
        procedure insert_after(el: real; target: ^BLE);
        var
            new_el: ^BLE;
        begin
            new(new_el);
            new_el^.next_el_pointer := target^.next_el_pointer;
            new_el^.data := el;

            target^.next_el_pointer := new_el;
            if target.next_el_pointer = nil then Self.last_el_pointer = new_el;
        end;

        procedure init();
        begin
            Self.first_el_pointer := nil;
            Self.last_el_pointer := nil;
        end;


        function return_first_negative(): ^BLE;
        var
            current: ^BLE := Self.first_el_pointer;
            new_el: ^BLE;
        begin
            while (current^.next_el_pointer <> nil) and (current^.data >= 0) do current := current^.next_el_pointer;
            result := current;
        end;
        
        function return_last_negative(): ^BLE;
        var
            current: ^BLE := Self.first_el_pointer;
            new_el: ^BLE;
        begin
            while (current^.last_el_pointer <> nil) and (current^.data >= 0) do current := current^.last_el_pointer;
            result := current;
        end;

        procedure delete_all_negative();
        var
            current: ^BLE := Self.first_el_pointer;
        begin
            begin
                while current <> nil do 
                begin
                    if current^.data < 0 then
                    begin
                        if Self.first_el_pointer = current then Self.first_el_pointer := current^.next_el_pointer;
                        if Self.last_el_pointer = current then Self.last_el_pointer := current^.prev_el_pointer;
                        Self.delete_el(current)
                    end;
                    else
                    current := current^.next_el_pointer;
                end;
            end;
        end;

        procedure destroy();
        begin
            Self.sub_destroy(Self.first_el_pointer);
        end;

        procedure insert_by_rBLE(el: real);
        var
            current: ^BLE := Self.first_el_pointer;
            new_el: ^BLE;
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
            current: ^BLE := Self.first_el_pointer;
            new_el: ^BLE;
        begin
            if Self.first_el_pointer = nil then
            begin
                new(new_el);
                new_el^.next_el_pointer := nil;
                new_el^.data := el;

                Self.first_el_pointer := new_el;
                Self.last_el_pointer := new_el;
            end
            else
            begin
                new(new_el);
                new_el^.next_el_pointer := nil;
                new_el^.data := el;

                Self.last_el_pointer^.next_el_pointer := new_el;
                Self.last_el_pointer := new_el;
            end;
        end;

        procedure insert_first(el: real);
        var
            current: ^BLE := Self.first_el_pointer;
            new_el: ^BLE;
        begin

            if current = nil then
            begin
                new(new_el);
                new_el^.next_el_pointer := nil;
                new_el^.data := el;

                Self.first_el_pointer := new_el;
                Self.last_el_pointer := new_el;
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
            current: ^BLE := Self.first_el_pointer;
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