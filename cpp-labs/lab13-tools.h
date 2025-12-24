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

class IntMatrix : IntVector {
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
    friend bool operator==(const IntMatrix &other, const IntMatrix &another);
    friend bool operator!=(const IntMatrix &other, const IntMatrix &another);
    friend IntMatrix operator+(const IntMatrix &other,
                               const IntMatrix &another);
    friend IntMatrix operator-(const IntMatrix &other,
                               const IntMatrix &another);
    IntVector &operator[](int index);
    const IntVector &operator[](int index) const;
    friend IntMatrix &operator+=(const int &value, IntMatrix &other);
    friend IntMatrix &operator+=(IntMatrix &other, const int &value);
    friend IntMatrix operator*(const IntMatrix &other, const int &value);
    friend IntMatrix operator*(const IntMatrix &other,
                               const IntMatrix &another);
};
