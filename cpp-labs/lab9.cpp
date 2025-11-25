#include "lab9-tools.h"
#include <cstdio>

int main() {
    IntMatrix matrix(3, 3);
    matrix.changeElement(0, 0, 1);
    matrix.changeElement(0, 1, 2);
    matrix.changeElement(0, 2, 3);
    matrix.changeElement(1, 0, 4);
    matrix.changeElement(1, 1, 5);
    matrix.changeElement(1, 2, 6);
    matrix.changeElement(2, 0, 7);
    matrix.changeElement(2, 1, 8);
    matrix.changeElement(2, 2, 9);
    matrix.print();

    IntMatrix matrix2 = IntMatrix(matrix, 10);
    matrix2.print();

    IntMatrix matrix3 = IntMatrix(2, 2);
    matrix3.changeElement(0, 0, 1);
    matrix3.changeElement(0, 1, 2);
    matrix3.changeElement(1, 0, 3);
    matrix3.changeElement(1, 1, 4);
    matrix3.print();
    IntMatrix matrix4(5.0);
    matrix4.print();

    printf("%lf\n", (double)matrix);
    return 0;
}
