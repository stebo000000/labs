#pragma once
#include <cstdio>
template <typename T> struct Node {
    Node *next;
    T data;
    Node(T data, Node *next = nullptr) : data(data), next(next) {}
};

template <typename T> class List {
  public:
    T data(Node<T> *current) { return current->data; }
    Node<T> *head;
    bool is_empty();
    Node<T> *next(Node<T> *current);
    List();
    ~List();
    void append(T data);
    void add_first(T data);
    void insert_after(T data, Node<T> *current);
    void remove(Node<T> *current);
};

class IntList : List<int> {
  private:
    bool isBigger(Node<int> *element, int num);

  public:
    IntList() : List<int>() {}
    ~IntList() {}
    void operator>>(const char *filename);
    void operator<<(const char *filename);
    bool isConteinsOdd();
    void deleteByCondition(int num);
};

class FloatList : List<float> {
  public:
    FloatList() : List<float>() {}
    ~FloatList() {}
    void operator>>(const char *filename);
    void operator<<(const char *filename);
    float findBiggest();
    bool isInRange();
    bool isBigger(Node<float> *element, float num);
    void deleteByCondition(float num);
};

template <typename T> List<T>::List() : head(nullptr) {}

template <typename T> List<T>::~List() {
    Node<T> *current = head;
    delete[] current;
}

template <typename T> bool List<T>::is_empty() { return head == nullptr; }

template <typename T> void List<T>::append(T data) {
    if (is_empty()) {
        head = new Node<T>(data);
    } else {
        Node<T> *current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = new Node<T>(data);
    }
    return;
}

template <typename T> Node<T> *List<T>::next(Node<T> *current) {
    return current->next;
}

template <typename T> void List<T>::add_first(T data) {
    head = new Node<T>(data, head);
    return;
}

template <typename T> void List<T>::insert_after(T data, Node<T> *current) {

    current->next = new Node<T>(data, current->next);
    return;
}

template <typename T> void List<T>::remove(Node<T> *current) {
    if (current == head) {
        head = current->next;
    } else {
        Node<T> *prev = head;
        while (prev->next != current) {
            prev = prev->next;
        }
        prev->next = current->next;
    }
    delete current;
    return;
}
