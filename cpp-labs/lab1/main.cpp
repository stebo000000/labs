#include "polynomial.h"
#include <iostream>

int main() {
  ExponentialPolynomial polynomial;
  char userInput;
  std::cout << "h - help\na - add\np - print\ni - integrate\nq - quit\nf - "
               "from file\n";
  while (true) {
    std::cin >> userInput;
    switch (userInput) {
    case 'a': {
      float coefficient, e_pow, x_pow;
      std::cout << "k " << "e_pow " << "x_pow\n";
      std::cin >> coefficient >> e_pow >> x_pow;
      polynomial.add(Term(coefficient, e_pow, x_pow));
      break;
    }
    case 'p': {
      polynomial.print();
      break;
    }
    case 'i': {
      polynomial = polynomial.integrate();
      break;
    }
    case 'q': {
      return 0;
      break;
    }
    case 'f': {
      polynomial.fromFile("cpp-labs/lab1/input.1000-7");
      break;
    }
    case 'h': {
      std::cout << "h - help\na - add\np - print\ni - integrate\nq - quit\nf - "
                   "from file\n";
      break;
    }
    default: {
      std::cout << "Unknown command\n h - for help\n";
      break;
    }
    }
  }

  return 0;
}
