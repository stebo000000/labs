#pragma once
class IntMatrix {
  private:
    int *const *const matrix;
    const int rowCount, colCount;

  public:
    IntMatrix(int rows = 0, int cols = 0);
    IntMatrix(const IntMatrix &other);
    IntMatrix(IntMatrix &&other);
    ~IntMatrix();
    void changeElement(int row, int col, int value);
    int elemen(int row, int col) const;
    operator double() const;
    void print() const;
};
