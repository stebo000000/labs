#include "lab13-errors.h"

void IndexError::print() {
    printf("IndexError: index %d out of range\n", index);
}

IndexError::IndexError(int index) : index(index) {}

DiffrentMatrixSizeError::DiffrentMatrixSizeError(int rowsA, int rowsB,
                                                 int colsA, int colsB)
    : rowsA(rowsA), rowsB(rowsB), colsA(colsA), colsB(colsB) {}

void DiffrentMatrixSizeError::print() {
    printf("DiffrentMatrixSizeError: matrix size %d:%d != %d:%d\n", rowsA,
           colsA, rowsB, colsB);
}
