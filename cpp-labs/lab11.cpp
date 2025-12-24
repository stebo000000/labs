#include "lab11-tools.h"
#include <stdio.h>

int main() {
    IntMatrix matrix1(2, 2);
    printf("%d\n", matrix1[0].len());
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

    mx4 += 1;
    mx4.print();

    printf("is same: %d\n", 1 == IntMatrix(1));

    1 += mx4; // cannot be done without friend
    mx4.print();

    printf("%d", mx4[1][0]);
    return 0;
}
