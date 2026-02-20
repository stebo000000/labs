#pragma once

struct Term {
  float coefficient;
  int e_pow;
  int x_pow;

  Term(float coefficient, int e_pow, int x_pow)
      : coefficient(coefficient), e_pow(e_pow), x_pow(x_pow) {}
};

struct Node {
  Term term;
  Node *next;
  Node *prev;

  Node(Term term, Node *next = nullptr, Node *prev = nullptr)
      : term(term), next(next), prev(prev) {}
};

class ExponentialPolynomial {
private:
  Node *head;
  Node *tail;

public:
  ExponentialPolynomial();
  void add(Term term);
  void print();
  float evaluate(float x);
  void fromFile(const char *filename);
  ExponentialPolynomial integrate();
};