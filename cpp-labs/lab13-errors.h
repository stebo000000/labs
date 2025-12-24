#pragma once
#include <stdio.h>

class BaseError {
  public:
    virtual void print() = 0;
};

class IndexError : public BaseError {
  private:
    int index;

  public:
    IndexError(int index);
    void print() override;
};

class DiffrentMatrixSizeError : public BaseError {
  private:
    int rowsA;
    int rowsB;
    int colsA;
    int colsB;

  public:
    DiffrentMatrixSizeError(int rowsA, int rowsB, int colsA, int colsB);
    void print() override;
};
