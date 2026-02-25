#include "polynomial.h"
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
    std::cout << current->term.coefficient << "*" << "x^" << current->term.x_pow
              << "*" << "e^" << current->term.e_pow;
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
  while (current != nullptr) {
    Term new_term = Term(current->term.coefficient / (current->term.x_pow + 1) /
                             current->term.e_pow,
                         current->term.e_pow, current->term.x_pow + 1);
    result.add(new_term);
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
