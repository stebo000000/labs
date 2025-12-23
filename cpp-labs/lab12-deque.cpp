#include "lab12-deque.h"

template <typename T> Deque<T>::Deque() {
    deque = nullptr;
    arrSize = 0;
    front = 0;
    back = 0;
}

template <typename T> Deque<T>::~Deque() { delete[] deque; }

template <typename T> bool Deque<T>::is_empty() { return front == back; }

template <typename T> void Deque<T>::add_back(T data) {
    if (back == arrSize) {
        T *newDeque = new T[arrSize * 2];
        for (int i = 0; i < arrSize; i++) {
            newDeque[i] = deque[i];
        }
        delete[] deque;
        deque = newDeque;
    }
    arrSize *= 2;
    deque[back] = data;
    back++;
    return;
}

template <typename T> void Deque<T>::add_front(T data) {
    if (front == 0) {
        T *newDeque = new T[arrSize * 2];
        for (int i = 0; i < arrSize; i++) {
            newDeque[i] = deque[i];
        }
        delete[] deque;
        deque = newDeque;
        front = 1;
    }
    arrSize *= 2;
    deque[front - 1] = data;
    front--;
    return;
}

template <typename T> T Deque<T>::pop_back() {
    back--;
    return deque[back];
}

template <typename T> T Deque<T>::pop_front() {
    return deque[front];
    front++;
}
