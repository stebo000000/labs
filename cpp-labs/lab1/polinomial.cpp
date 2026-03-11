#include "polynomial.h"
#include <cmath>
#include <fstream>
#include <iostream>

ExponentialPolynomial::ExponentialPolynomial() : head(nullptr), tail(nullptr) {}

void ExponentialPolynomial::add(Term term) {
  if (head == nullptr) {
    head = new Node(term);
    tail = head;

  } else {
    tail->next = new Node(term);
    tail->next->prev = tail;
    tail = tail->next;
  }
}

void ExponentialPolynomial::print() {
  Node *current = head;
  while (current != nullptr) {
    std::cout << current->term.coefficient;
    if (current->term.x_pow != 0)
      std::cout << "*" << "x^" << current->term.x_pow;
    if (current->term.e_pow != 0)
      std::cout << "*" << "e^" << current->term.e_pow << "x";
    current = current->next;
    if (current != nullptr) {
      std::cout << " + ";
    }
  }
  std::cout << "\n";
}

ExponentialPolynomial ExponentialPolynomial::integrate() {
  ExponentialPolynomial result;
  Node *current = head;
  Term new_term;
  while (current != nullptr) {
    Term temp = current->term;
    if (temp.e_pow == 0) {
      result.add(Term(temp.coefficient / (temp.x_pow + 1), temp.e_pow,
                      temp.x_pow + 1));
    } else {
      for (int i = 0; temp.x_pow != 0; [&]() {
             temp.coefficient = temp.coefficient * temp.x_pow /
                                (temp.e_pow != 0 ? temp.e_pow : 1) *
                                std::pow(-1, i + 1);
             temp.x_pow--;
             i++;
           }()) {

        new_term = Term(current->term.coefficient / current->term.e_pow != 0
                            ? current->term.e_pow
                            : 1,
                        temp.e_pow, temp.x_pow);
        result.add(new_term);
      }
      result.add(Term(temp.coefficient / (temp.e_pow != 0 ? temp.e_pow : 1),
                      temp.e_pow, 0));
    }
    current = current->next;
  }
  return result;
}

void ExponentialPolynomial::fromFile(const char *filename) {
  std::ifstream file(filename);
  float coefficient;
  int e_pow, x_pow;
  while (file >> coefficient >> e_pow >> x_pow) {
    Term term(coefficient, e_pow, x_pow);
    add(term);
  }
  file.close();
}
