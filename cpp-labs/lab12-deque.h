#pragma once
#include <type_traits>
template <typename T> struct Node {
    T data;
    int next;
    int prev;
    Node(T data, int next = 0, int prev = 0)
        : data(data), next(next), prev(prev) {}
};

template <typename T> class Deque {
  private:
    Node<T> *deque;
    int arrSize;
    int front;
    int back;

  public:
    Deque();
    ~Deque();
    bool is_empty();
    void add_back(T data);
    void add_front(T data);
    T pop_back();
    T pop_front();
    void print();
};
