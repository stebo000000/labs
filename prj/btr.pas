unit my_list;
    
interface

type
    Node := record
        left_node: ^Node := nil;
        right_node: ^Node := nil;
        parent: ^Node := nil;
        data: real;
    end;

    BTR := record
        root: ^Node := nil;
        private

        procedure set_root(el: real);
        var
            new_node: ^Node;
        begin
            new(new_node);
            new_node^.data := el;
            Self.root := new_node;
        end;

        function add_left(target: ^Node; el: real);
        var
            new_node: ^Node;
        begin
            new(new_node);
            new_node^.data := el;
            target^.left_node := new_node;
            result := new_node;
        end;

        function add_right(target: ^Node; el: real);
        var
            new_node: ^Node;
        begin
            new(new_node);
            new_node^.data := el;
            target^.right_node := new_node;
            result := new_node;
        end;

        function get_node_by_data(el: real; current_node: ^Node := nil; is_start: boolean := true):^Node;  # не уверен в ифках и что он остановится но пофиг 
        begin
            if is_start then current_node := Self.root;
            if current_node <> nil then
            begin
                if (el <> current_node^.data) then
                    result := get_node_by_data(el, current_node^.left_node, false);
                if (el <> current_node^.data) then
                    result := get_node_by_data(el, current_node^.right_node, false);
            end
            else
                result := nil;
        end;

        procedure delete_leaf(target: Node);
        var
            to_delete: ^Node;
        begin
            to_delete := target;
            if target = Self.root then
            begin
                Self.root := nil;
            end
            else
            begin
                if target^.parent^.left_node = target then
                    target^.parent^.left_node := nil
                else
                    target^.parent^.right_node := nil;
            end;
            dispose(to_delete); 
            
        end;

        procedure input(f, current_node: ^Node);
        var
            buffer: real;
            new_node: ^Node;
        begin
            if not eof(f) then
            begin
                readln(f, buffer);
                if buffer <> '*' then
                begin
                    new_node := Self.add_left(current_node, buffer);
                    input(f, new_node);
                end;
            end;

            if not eof(f) then
            begin
                readln(f, buffer);
                if buffer <> '*' then
                begin
                    new_node := Self.add_right(current_node, buffer);
                    input(f, new_node);
                end;
            end;
        end;

        public

        procedure fill(f: TextFile);
        var
            buffer: real;
        begin
            readln(f, buffer);
            Self.set_root(buffer);

        end;

        procedure write_btr(current_node: ^Node := nil; is_start: boolean := true);
        begin
            if is_start then current_node := Self.root;

            if (nil <> current_node^.left_node) then
            begin
                writeln(current_node^.data);
                get_node_by_data(current_node^.left_node, false);
            end;

            if (nil <> current_node^.right_node) then
            begin
                writeln(current_node^.data);
                get_node_by_data(current_node^.right_node, false);
            end;
        end;

        procedure delete_sub_btr(current_node: ^Node := nil);
        begin
            if (nil <> current_node^.left_node) then
            begin
                get_node_by_data(current_node^.left_node);
            end;

            if (nil <> current_node^.right_node) then
            begin
                get_node_by_data(current_node^.right_node);
            end;
            Self.delete_leaf(current_node);
        end;

    end;
implementation
    

    
end.