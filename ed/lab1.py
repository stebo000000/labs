def multiplicative(string: str, n: int):
    s = 0
    a = 0.6180339887
    for i in range(len(string)):
        s += ord(string[i]) * (i + 1)
    return int(n * ((s * a) - int((s * a))))


def adhd(string: str, n: int):
    h = 0
    for i in range(len(string)):
        h += ord(string[i])
        h = (h << 7) | (h >> 25)
    return h % n


def f(x, y, z):
    return x & y | ~x & z


def g(x, y, z):
    return x & z | y & ~z


def h(x, y, z):
    return x ^ y ^ z


def i(x, y, z):
    return y ^ (x | ~z)


def md5(string: str, n: int):
    a, b, c, d = 1234, 5678, 9987, 6543

    for j in range(len(string)):
        a = (a + f(b, c, d) + ord(string[j])) & 0xFF
        b = (b + g(a, c, d) + ord(string[j])) & 0xFF
        c = (c + h(a, b, d) + ord(string[j])) & 0xFF
        d = (d + i(a, b, c) + ord(string[j])) & 0xFF
        a = ((a << 1) | (a >> 7)) & 0xFF
        b = ((b << 3) | (b >> 5)) & 0xFF
        c = ((c << 5) | (c >> 3)) & 0xFF
        d = ((d << 7) | (d >> 1)) & 0xFF

    res = a
    res = ((res << 7) | b)
    res = ((res << 7) | c)
    res = ((res << 7) | d)

    return res % n


def main():
    n = int(input("enter \"n\": "))

    f1 = open(rf"D:\labs\ed\sets.txt", "r")
    f2 = open("output.txt", "w")
    strings_list = f1.read().strip().split()
    f2.write("key       multiplicative byte_sdvig md5 \n")

    for j in range(len(strings_list)):
        string = strings_list[j]
        h1 = multiplicative(string, n)
        h2 = adhd(string, n)
        h3 = md5(string, n)
        f2.write(f"{string:<18}     {h1}  {h2}  {h3}\n")

    f1.close()
    f2.close()


main()
