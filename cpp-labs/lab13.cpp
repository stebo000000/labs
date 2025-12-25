#include "lab11-tools.h"
#include "lab13-errors.h"
#include <stdio.h>
#include <typeinfo>

int main() {
    IntMatrix matrix1(2, 2);
    printf("%d\n", matrix1[0].len());
    matrix1.changeElement(0, 0, 1);
    matrix1.changeElement(0, 1, 0);
    matrix1.changeElement(1, 0, 3);
    matrix1.changeElement(1, 1, 4);

    // IntMatrix matrix2 = IntMatrix(1, 1);
    // matrix2.changeElement(0, 0, 1);
    IntVector matrix2 = IntVector(1);

    try {
        if (typeid(matrix1) != typeid(matrix2)) {
            throw DIfferentClassesError();
        }
        // IntMatrix mx4 = matrix1 + matrix2;
        // mx4.print();
        // IntMatrix mx5 = matrix1 - matrix2;
        // mx5.print();

        printf("%d", matrix1[1][3]);
    } catch (BaseError &exception) {
        exception.print();
    }

    return 0;
}
