def read_file(name: str):
    with open(name, 'r') as f:
        s = f.read().split()

    n = len(s)
    arr = [0.0] * n

    for i in range(n):
        arr[i] = float(s[i])
    return arr


def find_min(arr: list[float]):
    min_num = arr[0]
    for i in range(1, len(arr)):
        if arr[i] < min_num:
            min_num = arr[i]
    return min_num


def main():
    arr = read_file(name=rf"D:\labs\ed\lab2.txt")

    with open("lab2out.txt", "w") as f:
        f.write(str(find_min(arr)))


main()
