
#include "lab10-tools.h"
#include <math.h>
#include <stdio.h>

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

IntMatrix::IntMatrix(int rowC, int colC, char const *filename)
    : rowCount(rowC), colCount(colC) {

    FILE *fptr = fopen(filename, "r");

    matrix = new int *[rowCount];

    for (int i = 0; i < rowCount; i++) {
        matrix[i] = new int[colCount];
        for (int j = 0; j < colCount; j++) {
            fscanf(fptr, "%d", &matrix[i][j]);
        }
    }

    fclose(fptr);
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
    printf("\n");
}
double IntMatrix::toDouble() const {
    double sum = 0;
    for (int i = 0; i < rowCount; i++) {
        for (int j = 0; j < colCount; j++) {
            sum += matrix[i][j];
        }
    }
    return sum / (rowCount * colCount);
}

IntMatrix &IntMatrix::operator=(const IntMatrix &other) {
    rowCount = other.rowCount;
    colCount = other.colCount;
    matrix = new int *[rowCount];
    for (int i = 0; i < rowCount; i++) {
        matrix[i] = new int[colCount];
        for (int j = 0; j < colCount; j++) {
            matrix[i][j] = other.matrix[i][j];
        }
    }
    return *this;
}

IntMatrix &IntMatrix::operator=(IntMatrix &&other) {
    rowCount = other.rowCount;
    colCount = other.colCount;
    matrix = other.matrix;
    other.matrix = nullptr;
    return *this;
}

bool IntMatrix::operator==(const IntMatrix &other) const {
    if (rowCount != other.rowCount || colCount != other.colCount) {
        return false;
    }
    for (int i = 0; i < rowCount; i++) {
        for (int j = 0; j < colCount; j++) {
            if (matrix[i][j] != other.matrix[i][j]) {
                return false;
            }
        }
    }
    return true;
}

bool IntMatrix::operator!=(const IntMatrix &other) const {
    return !(*this == other);
}

IntMatrix IntMatrix::operator+(const IntMatrix &other) const {
    IntMatrix result(rowCount, colCount);
    for (int i = 0; i < rowCount; i++) {
        for (int j = 0; j < colCount; j++) {
            result.changeElement(i, j, matrix[i][j] + other.matrix[i][j]);
        }
    }
    return result;
}

IntMatrix IntMatrix::operator-(const IntMatrix &other) const {
    IntMatrix result(rowCount, colCount);
    for (int i = 0; i < rowCount; i++) {
        for (int j = 0; j < colCount; j++) {
            result.changeElement(i, j, matrix[i][j] - other.matrix[i][j]);
        }
    }
    return result;
}

const int *IntMatrix::operator[](int index) const { return matrix[index]; }

int *IntMatrix::operator[](int index) { return matrix[index]; }

IntMatrix &IntMatrix::operator+=(int &value) {
    for (int i = 0; i < rowCount; i++) {
        for (int j = 0; j < colCount; j++) {
            matrix[i][j] += value;
        }
    }
    return *this;
}
