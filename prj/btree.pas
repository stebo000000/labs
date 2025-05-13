unit btree;
    
interface

type
    Node = record
        left_node: ^Node := nil;
        right_node: ^Node := nil;
        parent: ^Node := nil;
        data: real;
    end;

    BTR = record
        root: ^Node := nil;
        el_count: integer := 0;

        private
        procedure set_root(el: real);
        var
            new_node: ^Node;
        begin
            new(new_node);
            new_node^.data := el;
            Self.root := new_node;
            Self.el_count := 1;

        end;

        function get_node_by_data(el: real; current_node: ^Node := nil; is_start: boolean := true):^Node;  // не уверен в ифках и что он остановится но пофиг 
        var
            ln, rn: ^Node;
        begin
            if is_start then current_node := Self.root;
            if current_node <> nil then
            begin
                if el = current_node^.data then
                    result := current_node
                else
                begin
                    if (el <> current_node^.data) then
                        ln := get_node_by_data(el, current_node^.left_node, false);
                    if (el <> current_node^.data) then
                        rn := get_node_by_data(el, current_node^.right_node, false);
                    result := (ln <> nil ? ln : rn);
                end;
            end;
        end;

        procedure delete_leaf(target: ^Node);
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
            Self.el_count -= 1;
            
        end;

        procedure input(f: TextFile; current_node: ^Node);
        var
            buffer: real;
            new_node: ^Node;
        begin
            if not eof(f) then
            begin
                readln(f, buffer);
                if buffer <> 111 then
                begin
                    new_node := Self.add_left(current_node, buffer);
                    input(f, new_node);
                end;
            end;

            if not eof(f) then
            begin
                readln(f, buffer);
                if buffer <> 111 then
                begin
                    new_node := Self.add_right(current_node, buffer);
                    input(f, new_node);
                end;
            end;
        end;

        public
        function add_left(target: ^Node; el: real): ^Node;
        var
            new_node: ^Node;
        begin
            if target^.left_node <> nil then exit;
            new(new_node);
            new_node^.data := el;
            target^.left_node := new_node;
            new_node^.parent := target;
            Self.el_count += 1;
            result := new_node;
        end;

        function add_right(target: ^Node; el: real): ^Node;
        var
            new_node: ^Node;
        begin
            if target^.right_node <> nil then exit;
            new(new_node);
            new_node^.data := el;
            target^.right_node := new_node;
            new_node^.parent := target;
            Self.el_count += 1;
            result := new_node;
        end;

        procedure fill(f: TextFile);
        var
            buffer: real;
        begin
            readln(f, buffer);
            Self.set_root(buffer);
            Self.input(f, Self.root);
        end;

        function find(el: real): ^Node;
        begin
            result := Self.get_node_by_data(el);
        end;

        procedure write_btr(current_node: ^Node := nil; is_start: boolean := true; space_count: integer := 0);
        begin
            if is_start then
            begin
                current_node := Self.root;
                space_count := Self.el_count;
            end;

            writeln(' ' * space_count * 4, current_node^.data);
            if (nil <> current_node^.left_node) then
            begin
                write_btr(current_node^.left_node, false, space_count - 1);
            end;

            if (nil <> current_node^.right_node) then
            begin
                write_btr(current_node^.right_node, false, space_count + 2);
            end;
        end;

        procedure delete_sub_btr(current_node: ^Node := nil);
        begin
            if (nil <> current_node^.left_node) then
            begin
                delete_sub_btr(current_node^.left_node);
            end;

            if (nil <> current_node^.right_node) then
            begin
                delete_sub_btr(current_node^.right_node);
            end;
            if current_node <> Self.root then
                Self.delete_leaf(current_node);
        end;

        function count(current_node: ^Node := nil; is_start: boolean := true): integer;
        var
            cl, cr: integer;
        begin
            if is_start then current_node := Self.root;

            if (nil <> current_node^.left_node) then
            begin
                cl := count(current_node^.left_node, false) + (current_node^.data < 0 ? 1 : 0);
            end;

            if (nil <> current_node^.right_node) then
            begin
                cr := count(current_node^.right_node, false) + (current_node^.data < 0 ? 1 : 0);
            end;

            result := (current_node^.data < 0 ? 1 : 0) + cl + cr;
        end;

    end;
implementation
    

    
end.