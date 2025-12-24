#pragma once
template <typename T> struct Node1 {
    T data;
    int next;
    int prev;
    Node1(T data, int next = 0, int prev = 0)
        : data(data), next(next), prev(prev) {}
};

template <typename T> class Deque {
  public:
    Node1<T> *deque;
    int arrSize;
    int front;
    int back;

    Deque();
    ~Deque();
    bool is_empty();
    void add_back(T data);
    void add_front(T data);
    T pop_back();
    T pop_front();
    void print();
};
