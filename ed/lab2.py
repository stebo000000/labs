def input_array(name: str):
    f = open(name, 'r')
    s = f.read().split()
    f.close()

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
    arr = input_array(name=r"D:\labs\ed\lab2.txt")

    f = open("lab2out.txt", "w")
    f.write(str(find_min(arr)))
    f.close()


main()
