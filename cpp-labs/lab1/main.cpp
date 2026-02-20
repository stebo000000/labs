#include "polynomial.h"
#include <iostream>

int main() {
  ExponentialPolynomial polynomial;
  polynomial.fromFile("input.1000-7");
  polynomial.print();
  polynomial.integrate();
  polynomial.print();
  return 0;
}
