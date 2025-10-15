import typing


def init():
    return []


def is_empty(lst: list):
    return len(lst) == 0


def add_first(lst: list[str], el: str):
    length = len(lst)
    new_lst = [""] * (length + 1)

    new_lst[0] = el

    for i in range(1, length):
        new_lst[i] = lst[i - 1]

    return new_lst


def add_last(lst: list[str], el: str):
    length = len(lst)
    new_lst = [""] * (length + 1)

    for i in range(length):
        new_lst[i] = lst[i]

    new_lst[length] = el

    return new_lst


def add_after_currnet(lst: list[str], current: int, el: str):
    length = len(lst)
    new_lst = [""] * (length + 1)

    for i in range(current):
        new_lst[i] = lst[i]
    
    new_lst[current] = el

    for i in range(current, length):
        new_lst[i + 1] = lst[i]
        
    return new_lst


def get_first(lst: list[str]):
    if not is_empty(lst):
        return lst[0]
    else:
        return None


def get_last(lst: list[str]):
    if not is_empty(lst):
        return lst[-1]
    else:
        return None


def get_current(lst: list[str], current: int):
    if not is_empty(lst):
        return lst[current]
    else:
        return None
    

def del_first(lst: list[str]):
    if not is_empty(lst):
        length = len(lst)
        new_lst = [""] * (length - 1)

        for i in range(1, length):
            new_lst[i - 1] = lst[i]
    else:
        new_lst = []

    return new_lst


def del_last(lst: list[str]):
    if not is_empty(lst):
        length = len(lst)
        new_lst = [""] * (length - 1)

        for i in range(length - 1):
            new_lst[i] = lst[i]
    else:
        new_lst = []

    return new_lst


def del_current(lst: list[str], current: int):
    length = len(lst)
    
    new_lst = [0.0] * (length - 1)

    for i in range(current):
        new_lst[i] = lst[i]

    for i in range(current + 1, length):
        new_lst[i - 1] = lst[i]

    return new_lst


def next_el(lst: list[str], current: int):
    if current < len(lst) - 1:
        current += 1
    else:
        current = None
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
    while i is not None:
        f.write(str(get_current(lst, i)) + " ")
        i = next_el(lst, i)


def count(lst: list[str], target: int):
    c = 0
    i = 0

    while i is not None:
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
