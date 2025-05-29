program no_game_no_life;

uses stack_good;
// uses stack_bad;
uses queue_good;
// uses queue_bad;
uses deque_good;
// uses deque_bad;

type
    // struct = Stack;
    // struct = Queue;
    struct = Deque;

var
    f: TextFile;
    // my_stack: Stack;
    // my_queue: Queue;
    my_deque: Deque;

procedure input(var st: Stack; f: TextFile);
var buffer: real;
begin
    while not eof(f) do
    begin
        readln(f, buffer);
        st.append(buffer);
    end;
end;

procedure input(var st: Queue; f: TextFile);
var buffer: real;
begin
    while not eof(f) do
    begin
        readln(f, buffer);
        st.append(buffer);
    end;
end;

procedure input(var st: Deque; f: TextFile);
var buffer: real;
begin
    while not eof(f) do
    begin
        readln(f, buffer);
        st.append(buffer);
        if not eof(f) then
        begin
            readln(f, buffer);
            st.insert_first(buffer);
        end;
    end;
end;


function copy_by_rule(st: Stack): struct;
var 
    new_st: struct;
    buffer: real;
begin
    while not st.is_empty() do
    begin
        buffer := st.pop();
        if buffer >= 0 then 
            new_st.append(buffer);
    end;
    result := new_st;
end;
function copy_by_rule(st: Queue): struct;
var 
    new_st: struct;
    buffer: real;
begin
    while not st.is_empty() do
    begin
        buffer := st.pop();
        if buffer >= 0 then 
            new_st.append(buffer);
    end;
    result := new_st;
end;
function copy_by_rule(st: Deque): struct;
var 
    new_st: struct;
    buffer1: real;
    buffer2: real;
begin
    while not st.is_empty() do
    begin
        buffer1 := st.pop();
        buffer2 := st.get_first();
        if (buffer1 >= 0) or (buffer2 >= 0) then 
        begin
            new_st.append(buffer1);
            new_st.insert_first(buffer2);
        end;
    end;
    result := new_st;
end;

begin

    if ParamCount < 2 then
    begin
        writeln('Недостаточно параметров');
        exit;
    end;
    try
        AssignFile(f, ParamStr(1));
        Reset(f);
    except
        writeln('Невозможно открыть файл ''', Paramstr(1), ''' для чтения');
        exit;
    end;


    // input(my_stack, f);
    // my_stack.scan();

    // my_stack.append(3);
    // my_stack.scan();
    // my_stack.pop();
    // my_stack.pop();
    // my_stack.append(2);
    // my_stack.scan();

    // my_stack := copy_by_rule(my_stack);
    // my_stack.scan();
    
    // my_stack.destroy();


    // input(my_queue, f);
    // my_queue.scan();

    // my_queue.append(1);
    // my_queue.append(2);
    // my_queue.scan();

    // my_queue.pop();
    // my_queue.pop();
    // my_queue.scan();

    // my_queue := copy_by_rule(my_queue);
    // my_queue.scan();

    // my_queue.destroy()


    input(my_deque, f);
    my_deque.scan();

    my_deque.append(1);
    my_deque.insert_first(2);
    my_deque.scan();

    my_deque.pop();
    my_deque.pop();
    my_deque.get_first();
    my_deque.scan();

    my_deque := copy_by_rule(my_deque);
    my_deque.scan();

    my_deque.destroy()



end.