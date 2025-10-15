import typing


def input_matrix(name: str, n: int, m: int):
    f = open(name, "r")

    matrix = [[]] * n
    
    for i in range(n):
        matrix[i] = [0.0] * m

        temp = f.readline().split(" ")

        for j in range(m):
            matrix[i][j] = float(temp[j])

    f.close()

    return matrix


def output(f: typing.TextIO, matrix: list[list[float]], n: int, m: int):
    for i in range(n):
        f.write("\n")
        for j in range(m):
            f.write(str(matrix[i][j]) + " ")


def has_bigger(num: int, matrix: list[list[float]], n: int, m: int):
    is_bigger = False

    i = 0
    while i < n and not is_bigger:
        j = 0
        while j < m and not is_bigger:
            if matrix[i][j] < num:
                is_bigger = True
            j += 1
        i += 1

    return is_bigger


def prod_with_condition(num: int, matrix: list[list[float]], n: int, m: int):
    for i in range(n):
        for j in range(m):
            if matrix[i][j] < num:
                matrix[i][j] *= num

    return matrix


def main():
    n = int(input("enter row count: "))
    m = int(input("enter column count: "))
    matrix = input_matrix(r"C:\Users\Admin\Desktop\task3withdata.txt", n, m)
    num = int(input("enter number: "))

    f = open("output.txt", "w")

    f.write("matrix before")
    output(f, matrix, n, m)

    if has_bigger(num, matrix, n, m):
        matrix = prod_with_condition(num, matrix, n, m)
        f.write("\nmatrix after")
        output(f, matrix, n, m)
    else:
        f.write("matrix dont change\n")

    f.close()


main()
