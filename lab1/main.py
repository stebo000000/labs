import numpy
import sympy as sp
import matplotlib.pyplot as plt
import matplotlib

matplotlib.use("TkAgg")


def find_zero():
    x0: float = 1.0
    while x0 / 2 > 0:
        x0 = x0 / 2
    print("zero:", x0)


def find_epsilon():
    e = 1.0
    while 1 + e > 1:
        e = e / 2
    print("epsilon:", e)


def find_infinity():
    x0: float = 1.0
    while not numpy.isinf(x0):
        x0 = x0 * 2
    print("infinity:", x0)


def teylor_series():
    x = sp.symbols("x")
    F = sp.exp(x) * sp.sin(x)
    series_F = sp.series(F, x, 0, 7)

    print(series_F)


def S(x: float, N: int, term):
    total = 0
    for k in range(N):
        total += term(x, k)
    print(total)


def graf(f, term):
    x_vals = numpy.linspace(-2, 2, 400)

    plt.plot(x_vals, f(x_vals), label="f(x) = e^x", linewidth=2)
    for n in range(1, 6):
        y_vals = [S(x, n, term) for x in x_vals]
        plt.plot(x_vals, y_vals, label=f"S(x,{n})")

    plt.legend()
    plt.grid(True)
    plt.title("Функция и частичные суммы ряда Тейлора")
    plt.show()


def main():
    find_zero()
    find_epsilon()
    find_infinity()
    teylor_series()
    S(1, 10, lambda x, k: x**k / sp.factorial(k))
    graf(lambda x: numpy.exp(x) * numpy.sin(x), lambda x, k: x**k / sp.factorial(k))


if __name__ == "__main__":
    main()
