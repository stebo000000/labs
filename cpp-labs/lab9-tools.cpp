// #include "lab9-tools.h"
#include <cstdio>
class IntMatrix {
  private:
    int **matrix;
    const int rowCount, colCount;

  public:
    IntMatrix(double element) : rowCount(1), colCount(1) {
        matrix = new int *[rowCount];
        matrix[0] = new int[colCount];
        matrix[0][0] = element;
    }
    IntMatrix(int rows = 0, int cols = 0) : rowCount(rows), colCount(cols) {
        matrix = new int *[rowCount];
        for (int i = 0; i < rowCount; i++) {
            matrix[i] = new int[colCount];
        }
    }

    IntMatrix(const IntMatrix &other, int delta = 0)
        : rowCount(other.rowCount), colCount(other.colCount) {
        matrix = new int *[rowCount];
        for (int i = 0; i < rowCount; i++) {
            matrix[i] = new int[colCount];
            for (int j = 0; j < colCount; j++) {
                matrix[i][j] = other.matrix[i][j] + delta;
            }
        }
    }

    IntMatrix(IntMatrix &&other)
        : rowCount(other.rowCount), colCount(other.colCount),
          matrix(other.matrix) {
        other.matrix = nullptr;
    }

    ~IntMatrix() {
        for (int i = 0; i < rowCount; i++) {
            delete[] matrix[i];
        }
        delete[] matrix;
    }

    void changeElement(int row, int col, int value) {
        matrix[row][col] = value;
    }

    int element(int row, int col) const { return matrix[row][col]; }

    void print() const {
        for (int i = 0; i < rowCount; i++) {
            for (int j = 0; j < colCount; j++) {
                printf("%d ", matrix[i][j]);
            }
            printf("\n");
        }
    }
    operator double() const {
        double sum = 0;
        for (int i = 0; i < rowCount; i++) {
            for (int j = 0; j < colCount; j++) {
                sum += matrix[i][j];
            }
        }
        return sum / (rowCount * colCount);
    }
};
