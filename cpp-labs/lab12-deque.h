#pragma once
#include <cstdio>
template <typename T> class Deque {
  protected:
    T *deque;
    int arrSize;
    int front;
    int back;

  public:
    T data(int index) { return deque[index]; }
    Deque();
    ~Deque();
    bool is_empty();
    void add_back(T data);
    void add_front(T data);
    T pop_back();
    T pop_front();
};

class CharDeque : public Deque<char> {
  public:
    CharDeque() : Deque<char>() {}
    ~CharDeque() {}
    void operator<<(const char *filename);
    void operator>>(const char *filename);
};

class IntDeque : public Deque<int> {
  public:
    IntDeque() : Deque<int>() {}
    ~IntDeque() {}
    void operator<<(const char *filename);
    void operator>>(const char *filename);
};

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
        T *newDeque = new T[arrSize * 2 + 1];
        for (int i = 0; i < arrSize; i++) {
            newDeque[i] = deque[i];
        }
        if (front != back)
            delete[] deque;
        deque = newDeque;
    }
    arrSize = arrSize * 2 + 1;
    deque[back] = data;
    back++;
    return;
}

template <typename T> void Deque<T>::add_front(T data) {
    if (front == 0) {
        T *newDeque = new T[arrSize * 2 + 1];
        for (int i = 0; i < arrSize; i++) {
            newDeque[i + 1] = deque[i];
        }
        delete[] deque;
        deque = newDeque;
        front = 1;
    }
    arrSize = arrSize * 2 + 1;

    deque[front - 1] = data;
    front--;
    back++;
    return;
}

template <typename T> T Deque<T>::pop_back() {
    back--;
    return deque[back];
}

template <typename T> T Deque<T>::pop_front() { return deque[front++]; }
