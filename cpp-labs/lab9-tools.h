#pragma once
class IntMatrix {
  private:
    int **matrix;
    const int rowCount, colCount;

  public:
    IntMatrix(double element);
    IntMatrix(int rowC = 0, int colC = 0);
    IntMatrix(const IntMatrix &other, int delta = 0);
    IntMatrix(IntMatrix &&other);
    ~IntMatrix();
    void changeElement(int row, int col, int value);
    int element(int row, int col) const;
    operator double() const;
    void print() const;
};
