#pragma once
template <typename T> struct Node1 {
    T data;
    int next;
    int prev;
    Node1(T data = 0, int next = 0, int prev = 0)
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

#include "lab12-deque.h"

template <typename T> Deque<T>::Deque() {
    deque = nullptr;
    arrSize = 0;
    front = 0;
    back = 0;
}

template <typename T> Deque<T>::~Deque() {

    if (deque != nullptr)
        delete[] deque;
}

template <typename T> bool Deque<T>::is_empty() { return front == back; }

template <typename T> void Deque<T>::add_back(T data) {
    if (back == arrSize) {
        Node1<T> *newDeque = new Node1<T>[arrSize * 2 + 1];
        for (int i = 0; i < arrSize; i++) {
            newDeque[i] = deque[i];
        }
        if (deque != nullptr)
            delete[] deque;
        deque = newDeque;
    }
    arrSize *= 2 + 1;
    deque[back] = data;
    back++;
    return;
}

template <typename T> void Deque<T>::add_front(T data) {
    if (front == 0) {
        Node1<T> *newDeque = new Node1<T>[arrSize * 2 + 1];
        for (int i = 0; i < arrSize; i++) {
            newDeque[i] = deque[i];
        }
        if (deque != nullptr)
            delete[] deque;
        deque = newDeque;
        front = 1;
    }
    arrSize *= 2 + 1;
    deque[front - 1] = data;
    front--;
    return;
}

template <typename T> T Deque<T>::pop_back() {
    back--;
    return deque[back].data;
}

template <typename T> T Deque<T>::pop_front() {
    return deque[front].data;
    front++;
}
