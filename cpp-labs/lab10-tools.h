#pragma once
#include <stdio.h>
class IntMatrix {
  private:
    int **matrix;
    int rowCount, colCount;

  public:
    IntMatrix(double element);
    IntMatrix(int rowC = 0, int colC = 0);
    IntMatrix(int rowC, int colC, char const *filename);
    IntMatrix(const IntMatrix &other, int delta = 0);
    IntMatrix(IntMatrix &&other);
    ~IntMatrix();
    void changeElement(int row, int col, int value);
    int element(int row, int col) const;
    double toDouble() const;
    void print() const;

    IntMatrix &operator=(const IntMatrix &other);
    IntMatrix &operator=(IntMatrix &&other);
    bool operator==(const IntMatrix &other) const;
    bool operator!=(const IntMatrix &other) const;
    IntMatrix operator+(const IntMatrix &other) const;
    IntMatrix operator-(const IntMatrix &other) const;
    int *operator[](int index);
    const int *operator[](int index) const;
    IntMatrix &operator+=(int &value);
};
