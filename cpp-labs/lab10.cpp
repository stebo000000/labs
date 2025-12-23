#include "lab10-tools.h"
#include <stdio.h>

int main() {
    IntMatrix matrix1(2, 2);
    matrix1.changeElement(0, 0, 1);
    matrix1.changeElement(0, 1, 0);
    matrix1.changeElement(1, 0, 3);
    matrix1.changeElement(1, 1, 4);

    IntMatrix matrix2 = IntMatrix(2, 2);
    matrix2.changeElement(0, 0, 1);
    matrix2.changeElement(0, 1, 0);
    matrix2.changeElement(1, 0, 3);
    matrix2.changeElement(1, 1, 4);

    IntMatrix mx4 = matrix1 + matrix2;
    mx4.print();
    IntMatrix mx5 = matrix1 - matrix2;
    mx5.print();

    mx4 += 10;
    mx4.print();

    mx4 = mx4 * 2;
    mx4.print();

    mx4 = mx4 * mx5;
    mx4.print();

    printf("%d", mx4[1][0]);
    return 0;
}
