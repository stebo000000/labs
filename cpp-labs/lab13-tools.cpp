#include "lab11-tools.h"
#include "lab13-errors.h"
#include <math.h>
#include <stdio.h>

IntVector::IntVector() : size(0) { vector = new int[1]; }

IntVector::IntVector(int vector_size) : size(vector_size) {
    vector = new int[size];
}

IntVector::~IntVector() { delete[] vector; }

IntVector::IntVector(const IntVector &other) : size(other.size) {
    vector = new int[size];
    for (int i = 0; i < size; i++) {
        vector[i] = other.vector[i];
    }
}

int IntVector::len() const { return size; }

int &IntVector::operator[](int index) {
    if (index < 0 || index >= size)
        throw IndexError(index);
    return vector[index];
}

const int &IntVector::operator[](int index) const {
    if (index < 0 || index >= size)
        throw IndexError(index);
    return vector[index];
}

IntVector &IntVector::operator=(const IntVector &other) {
    size = other.size;
    vector = new int[size];
    for (int i = 0; i < size; i++) {
        vector[i] = other.vector[i];
    }
    return *this;
}

IntVector &IntVector::operator=(IntVector &&other) {
    size = other.size;
    vector = other.vector;
    other.size = 0;
    other.vector = nullptr;
    return *this;
}
IntMatrix::IntMatrix(double element) : rowCount(1) {
    matrix = new IntVector[rowCount];
    matrix[0][0] = element;
}
IntMatrix::IntMatrix(int rowC, int colC) : rowCount(rowC) {
    matrix = new IntVector[rowCount];
    for (int i = 0; i < rowCount; i++) {
        matrix[i] = IntVector(colC);
    }
}

IntMatrix::IntMatrix(const IntMatrix &other, int delta)
    : rowCount(other.rowCount) {
    matrix = new IntVector[rowCount];
    for (int i = 0; i < rowCount; i++) {
        matrix[i] = IntVector(other[i].len());
        for (int j = 0; j < matrix[i].len(); j++) {
            matrix[i][j] = other.matrix[i][j] + delta;
        }
    }
}

IntMatrix::IntMatrix(int rowC, int colC, char const *filename)
    : rowCount(rowC) {

    FILE *fptr = fopen(filename, "r");

    matrix = new IntVector[rowCount];

    for (int i = 0; i < rowCount; i++) {
        matrix[i] = IntVector(colC);
        for (int j = 0; j < matrix[i].len(); j++) {
            fscanf(fptr, "%d", &matrix[i][j]);
        }
    }

    fclose(fptr);
}

IntMatrix::IntMatrix(IntMatrix &&other)
    : rowCount(other.rowCount), matrix(other.matrix) {
    other.matrix = nullptr;
}

IntMatrix::~IntMatrix() { delete[] matrix; }

void IntMatrix::changeElement(int row, int col, int value) {
    matrix[row][col] = value;
}

int IntMatrix::element(int row, int col) const { return matrix[row][col]; }

void IntMatrix::print() const {
    for (int i = 0; i < rowCount; i++) {
        for (int j = 0; j < matrix[i].len(); j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}
double IntMatrix::toDouble() const {
    double sum = 0;
    for (int i = 0; i < rowCount; i++) {
        for (int j = 0; j < matrix[i].len(); j++) {
            sum += matrix[i][j];
        }
    }
    return sum / (rowCount * matrix[0].len());
}

IntMatrix &IntMatrix::operator=(const IntMatrix &other) {
    rowCount = other.rowCount;
    matrix = new IntVector[rowCount];
    for (int i = 0; i < rowCount; i++) {
        matrix[i] = IntVector(other[i].len());
        for (int j = 0; j < matrix[i].len(); j++) {
            matrix[i][j] = other.matrix[i][j];
        }
    }
    return *this;
}

IntMatrix &IntMatrix::operator=(IntMatrix &&other) {
    rowCount = other.rowCount;
    matrix = other.matrix;
    other.matrix = nullptr;
    return *this;
}

bool operator==(const IntMatrix &other, const IntMatrix &another) {
    if (other.rowCount != another.rowCount ||
        other[0].len() != another.matrix[0].len()) {
        return false;
    }
    for (int i = 0; i < other.rowCount; i++) {
        for (int j = 0; j < other.matrix[i].len(); j++) {
            if (other[i][j] != another.matrix[i][j]) {
                return false;
            }
        }
    }
    return true;
}

bool operator!=(const IntMatrix &other, const IntMatrix &another) {
    return !(other == another);
}

IntMatrix operator+(const IntMatrix &other, const IntMatrix &another) {
    if (other.rowCount != another.rowCount ||
        other[0].len() != another.matrix[0].len()) {
        throw DiffrentMatrixSizeError(other.rowCount, another.rowCount,
                                      other[0].len(), another[0].len());
    }
    IntMatrix result(other.rowCount, other[0].len());
    for (int i = 0; i < other.rowCount; i++) {
        for (int j = 0; j < other[i].len(); j++) {
            result[i][j] = other.matrix[i][j] + another.matrix[i][j];
        }
    }
    return result;
}

IntMatrix operator-(const IntMatrix &other, const IntMatrix &another) {
    IntMatrix result(other.rowCount, other[0].len());
    if (other.rowCount != another.rowCount ||
        other[0].len() != another.matrix[0].len()) {
        throw DiffrentMatrixSizeError(other.rowCount, another.rowCount,
                                      other[0].len(), another[0].len());
    }
    for (int i = 0; i < other.rowCount; i++) {
        for (int j = 0; j < other[i].len(); j++) {
            result[i][j] = other.matrix[i][j] - another.matrix[i][j];
        }
    }
    return result;
}

const IntVector &IntMatrix::operator[](int index) const {
    if (index < 0 || index >= rowCount)
        throw IndexError(index);
    return matrix[index];
}

IntVector &IntMatrix::operator[](int index) {
    if (index < 0 || index >= rowCount)
        throw IndexError(index);
    return matrix[index];
}

IntMatrix &operator+=(const int &value, IntMatrix &other) {
    for (int i = 0; i < other.rowCount; i++) {
        for (int j = 0; j < other[i].len(); j++) {
            other[i][j] += value;
        }
    }
    return other;
}

IntMatrix &operator+=(IntMatrix &other, const int &value) {
    for (int i = 0; i < other.rowCount; i++) {
        for (int j = 0; j < other[i].len(); j++) {
            other[i][j] += value;
        }
    }
    return other;
}

IntMatrix operator*(const IntMatrix &other, const int &value) {
    IntMatrix result(other.rowCount, other[0].len());
    for (int i = 0; i < other.rowCount; i++) {
        for (int j = 0; j < other[i].len(); j++) {
            result[i][j] = other.matrix[i][j] * value;
        }
    }
    return result;
}

IntMatrix operator*(const IntMatrix &other, const IntMatrix &another) {
    IntMatrix result(other.rowCount, other.matrix[0].len());
    for (int i = 0; i < other.rowCount; i++) {
        for (int j = 0; j < another.matrix[0].len(); j++) {
            int sum = 0;
            for (int k = 0; k < other[0].len(); k++) {
                sum += other[i][k] * another.matrix[k][j];
            }
            result.changeElement(i, j, sum);
        }
    }
    return result;
}
