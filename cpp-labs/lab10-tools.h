#pragma once
#include <stdio.h>

class IntVector {
  private:
    int *vector;
    int size;

  public:
    IntVector();
    IntVector(int size);
    IntVector(const IntVector &other);
    ~IntVector();

    int len() const;

    int &operator[](int index);
    const int &operator[](int index) const;
    IntVector &operator=(const IntVector &other);
    IntVector &operator=(IntVector &&other);
};

class IntMatrix : protected IntVector {
  private:
    IntVector *matrix;
    int rowCount;

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
    IntVector &operator[](int index);
    const IntVector &operator[](int index) const;
    IntMatrix &operator+=(const int &value);
    IntMatrix operator*(const int &value);
    IntMatrix operator*(const IntMatrix &other);
};
