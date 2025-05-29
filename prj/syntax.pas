unit syntax;
    
interface
    function get_type(ch: char): string;
    function is_correct(f: TextFile; state: string := 'start'):boolean;



type
    dct = dictionary<char, string>;

    
implementation
    var types: dct := Dict(Arr((' ', 'space'), ('_', 'letter'), ('(', 'ob'), (')', 'cb'), (',', 'comma'), ('+', 'op'), ('-', 'op'), ('.', 'point'), ('=', 'eq')));
    var was_read: string := '';
    var counter: integer:= 0;
    function get_type(ch: char): string;
    begin
        try
            if ch in ['a'..'z', 'A'..'Z'] then result := 'letter'
            else if ch in ['0'..'9'] then result := 'digit'
            else result := types.Get(ch);
        except
            result := 'not a symbol';
        end;
    end;

    procedure write_error(f: TextFile; text: string);
    begin
        Reset(f);
        readln(f, was_read);
        writeln(was_read);
        writeln(' '*(counter-1), '~');
        writeln();
        writeln(text);

    end;
    

    function is_correct(f: TextFile; state: string):boolean;
    var ch: char;
    begin
        // writeln('state: ', state);
        repeat
            if eof(f) then
            begin
                write_error(f, 'expected ")" but "' + 'end of file' + '" was given');
                result := false;
                exit;
            end;
            read(f, ch);
            was_read += ch;
            inc(counter);
            // writeln('read: ', ch);
        until ((get_type(ch) <> 'space'));

        if get_type(ch) = 'cb' then
        begin
            result := true;
            exit;
        end;  

        if state = 'start' then
        begin
            if get_type(ch) <> 'ob' then
            begin
                write_error(f, 'expected "(" but "' + ch + '" was given');
                result := false;
                exit;
            end;

            result := is_correct(f, 'sname');          
        end

        else if (state = 'name') or (state = 'sname') then
        begin
            if get_type(ch) = 'eq' then
            begin
                result := is_correct(f, 'svalue');
                exit;
            end;
            if ((get_type(ch) <> 'letter') and (state = 'sname')) or ((get_type(ch) <> 'letter') and (get_type(ch) <> 'digit') and (state = 'name')) then
            begin
                write_error(f, 'expected <letter> but "' + ch + '" was given');
                result := false;
                exit;
            end;
            result := is_correct(f, 'name');
        end

        else if (state = 'svalue') or (state = 'bvalue') or (state = 'value') then
        begin
            if get_type(ch) = 'comma' then
            begin
                result := is_correct(f, 'name');
                exit;
            end;
            if ((get_type(ch) <> 'digit') and (get_type(ch) <> 'op') and (state = 'svalue')) or ((get_type(ch) <> 'digit') and (get_type(ch) <> 'point') and (state = 'bvalue')) or ((get_type(ch) <> 'digit') and (state = 'value')) then
            begin
                write_error(f, 'expected <digit> but "' + ch + '" was given');
                result := false;
                exit;
            end;

            if (get_type(ch) <> 'point') and (state <> 'value') then
                result := is_correct(f, 'bvalue')
            else
                result := is_correct(f, 'value')

        end;
    end;

initialization

end.