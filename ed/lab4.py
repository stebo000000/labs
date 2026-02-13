import typing


def init():
    return []


def is_empty(lst: list):
    return len(lst) == 0


def add_first(lst: list[str], el: str):
    length = len(lst)
    new_lst = [["", 0]] * (length + 1)

    new_lst[0][0] = el
    if length > 0:
        new_lst[0][1] = 1
    else:
        new_lst[0][1] = -1

    for i in range(1, length):
        new_lst[i][0] = lst[i - 1][0]
        new_lst[i][1] = lst[i - 1][1] + 1

    return new_lst


def add_last(lst: list[str], el: str):
    length = len(lst)
    new_lst = [["", 0] for _ in range(length + 1)]

    if is_empty(lst):
        new_lst[length][0] = el
        new_lst[length][1] = -1
    else:
        for i in range(length - 1):
            new_lst[i][0] = lst[i][0]
            new_lst[i][1] = lst[i][1]

        new_lst[length - 1][0] = lst[length - 1][0]
        new_lst[length - 1][1] = length

        new_lst[length][0] = el
        new_lst[length][1] = -1

    return new_lst


def add_after_currnet(lst: list[str], current: int, el: str):
    length = len(lst)
    new_lst = [["", 0]] * (length + 1)

    for i in range(current):
        new_lst[i][0] = lst[i][0]
        new_lst[i][1] = lst[i][1]
    
    new_lst[current][0] = lst[current][0]
    new_lst[current][1] = current + 1

    new_lst[current + 1][0] = el
    new_lst[current + 1][1] = current + 2

    for i in range(current, length):
        new_lst[i + 1][0] = lst[i][0]
        new_lst[i + 1][1] = lst[i][1] + 1
        
    return new_lst


def get_first(lst: list[str]):
    if not is_empty(lst):
        return lst[0][0]
    else:
        return []


def get_last(lst: list[str]):
    if not is_empty(lst):
        return lst[-1][0]
    else:
        return []


def get_current(lst: list[str], current: int):
    if not is_empty(lst):
        return lst[current][0]
    else:
        return []
    

def del_first(lst: list[str]):
    if not is_empty(lst):
        length = len(lst)
        new_lst = [["", 0]] * (length - 1)

        for i in range(1, length):
            new_lst[i - 1][0] = lst[i][0]
            new_lst[i - 1][1] = lst[i][1] - 1
    else:
        new_lst = []

    return new_lst


def del_last(lst: list[str]):
    if not is_empty(lst):
        length = len(lst)
        new_lst = [["", 0]] * (length - 1)

        for i in range(length - 2):
            new_lst[i][0] = lst[i][0]
            new_lst[i][1] = lst[i][1]

        new_lst[length - 2][0] = lst[length - 2][0]
        new_lst[length - 2][1] = -1
    else:
        new_lst = []

    return new_lst


def del_current(lst: list[str], current: int):
    length = len(lst)
    
    new_lst = [["", 0]] * (length - 1)

    for i in range(current - 1):
        new_lst[i][0] = lst[i][0]
        new_lst[i][1] = lst[i][1]

    for i in range(current + 1, length):
        new_lst[i - 1][0] = lst[i][0]
        new_lst[i - 1][1] = lst[i][1] - 1

    return new_lst


def next_el(lst: list[str], current: int):
    if current < len(lst):
        current = lst[current][1]
    else:
        current = -1
    return current


def input_lst(name: str):
    lst = init()

    f = open(name, "r")
    temp = f.readline().split()
    f.close()

    for i in range(len(temp)):
        lst = add_last(lst, temp[i])

    return lst


def output(lst: list[str], f: typing.TextIO):
    i = 0
    while i != -1:
        print(1, i)
        f.write(str(get_current(lst, i)) + " ")
        i = next_el(lst, i)


def count(lst: list[str], target: int):
    c = 0
    i = 0

    while i != -1:
        print(2, i)
        if len(get_current(lst, i)) == target:
            c += 1
        i = next_el(lst, i)
    
    return c


def main():
    lst = input_lst("lab4.txt")

    f = open("output.txt", "w")
    f.write("list:\n")
    output(lst, f)

    for i in range(1, 10):
        c = count(lst, i)
        f.write(f"\n{i}: {c}")

    f.close()


main()
