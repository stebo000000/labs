// #include "lab9-tools.h"
#include "lab9-tools.h"
#include <cstdio>

IntMatrix::IntMatrix(double element) : rowCount(1), colCount(1) {
    matrix = new int *[rowCount];
    matrix[0] = new int[colCount];
    matrix[0][0] = element;
}
IntMatrix::IntMatrix(int rowC, int colC) : rowCount(rowC), colCount(colC) {
    matrix = new int *[rowCount];
    for (int i = 0; i < rowCount; i++) {
        matrix[i] = new int[colCount];
    }
}

IntMatrix::IntMatrix(const IntMatrix &other, int delta)
    : rowCount(other.rowCount), colCount(other.colCount) {
    matrix = new int *[rowCount];
    for (int i = 0; i < rowCount; i++) {
        matrix[i] = new int[colCount];
        for (int j = 0; j < colCount; j++) {
            matrix[i][j] = other.matrix[i][j] + delta;
        }
    }
}

IntMatrix::IntMatrix(IntMatrix &&other)
    : rowCount(other.rowCount), colCount(other.colCount), matrix(other.matrix) {
    other.matrix = nullptr;
}

IntMatrix::~IntMatrix() {
    for (int i = 0; i < rowCount; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
}

void IntMatrix::changeElement(int row, int col, int value) {
    matrix[row][col] = value;
}

int IntMatrix::element(int row, int col) const { return matrix[row][col]; }

void IntMatrix::print() const {
    for (int i = 0; i < rowCount; i++) {
        for (int j = 0; j < colCount; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}
IntMatrix::operator double() const {
    double sum = 0;
    for (int i = 0; i < rowCount; i++) {
        for (int j = 0; j < colCount; j++) {
            sum += matrix[i][j];
        }
    }
    return sum / (rowCount * colCount);
}
