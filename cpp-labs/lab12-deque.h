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
    Deque(const Deque<T> &other);
    ~Deque();
    bool is_empty();
    void add_back(T data);
    void add_front(T data);
    T pop_back();
    T pop_front();
    void btf(Deque<T> &deque);
    void btb(Deque<T> &deque);
    void ftf(Deque<T> &deque);
    void ftb(Deque<T> &deque);

    // Deque<T> sort(Deque<T> &deque);
    // Deque<T> merge(Deque<T> &left, Deque<T> &right);
};

// template <typename T> Deque<T> merge(Deque<T> &left, Deque<T> &right) {
//     Deque<T> result;
//     T leftE = left.pop_front();
//     T rightE = right.pop_front();
//     while (!left.is_empty() && !right.is_empty()) {
//         if (left < right) {
//             result.add_back(leftE);
//             leftE = left.pop_front();
//         } else {
//             result.add_back(rightE);
//             rightE = right.pop_front();
//         }
//     }
//     while (!left.is_empty()) {
//         result.add_back(left.pop_front());
//     }
//     while (!right.is_empty()) {
//         result.add_back(right.pop_front());
//     }
//     return result;
// }
//
// template <typename T> Deque<T> sort(Deque<T> &deque) {
//     Deque<T> left;
//     Deque<T> right;
//     while (!deque.is_empty()) {
//         deque.btb(left);
//         if (!deque.is_empty()) {
//             deque.btb(right);
//         }
//     }
//     Deque<T> left1 = sort(left);
//     Deque<T> right1 = sort(right);
//     return merge(left1, right1);
// }

class CharDeque : public Deque<char> {
  public:
    CharDeque() : Deque<char>() {}
    ~CharDeque() {}
    void operator<<(const char *filename);
    void operator>>(const char *filename);

    CharDeque sort(CharDeque &deque);
    CharDeque merge(CharDeque &left, CharDeque &right);
};

class IntDeque : public Deque<int> {
  public:
    IntDeque() : Deque<int>() {}
    ~IntDeque() {}
    void operator<<(const char *filename);
    void operator>>(const char *filename);

    IntDeque sort(IntDeque &deque);
    IntDeque merge(IntDeque &left, IntDeque &right);
};

template <typename T> Deque<T>::Deque(const Deque<T> &other) {
    arrSize = other.arrSize;
    front = other.front;
    back = other.back;
    deque = new T[arrSize];
    for (int i = 0; i < arrSize; i++) {
        deque[i] = other.deque[i];
    }
}
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

template <typename T> void Deque<T>::btf(Deque<T> &deque) {
    deque.add_front(pop_back());
}

template <typename T> void Deque<T>::btb(Deque<T> &deque) {
    deque.add_back(pop_back());
}

template <typename T> void Deque<T>::ftf(Deque<T> &deque) {
    deque.add_front(pop_front());
}

template <typename T> void Deque<T>::ftb(Deque<T> &deque) {
    deque.add_back(pop_front());
}

template <typename T> bool Deque<T>::is_empty() { return front >= back; }

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
        back++;
    }
    arrSize = arrSize * 2 + 1;

    deque[front - 1] = data;
    front--;
    return;
}

template <typename T> T Deque<T>::pop_back() {
    back--;
    return deque[back];
}

template <typename T> T Deque<T>::pop_front() { return deque[front++]; }
