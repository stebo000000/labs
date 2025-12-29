#pragma once
#include <algorithm>
#include <cstdio>
template <typename T> struct Node {
    Node *next;
    T data;
    Node(T data, Node *next = nullptr) : data(data), next(next) {}
};

template <typename T> class List {
  public:
    bool isLast(Node<T> *current) { return current->next == nullptr; }
    T data(Node<T> *current) { return current->data; }
    Node<T> *head;
    bool is_empty();
    Node<T> *next(Node<T> *current);
    List();
    ~List();
    void append(T data);
    void add_first(T data);
    void insert_after(T data, Node<T> *&current);
    void remove(Node<T> *current);
    void remove_first();
    void remove_last();
    Node<T> *sort(Node<T> *&current);
    void merge(Node<T> *&left, Node<T> *&right);
    bool isEnd(Node<T> *current) { return current == nullptr; }
    void nullfyNext(Node<T> *current) { current->next = nullptr; }
};

template <typename T> void List<T>::merge(Node<T> *&left, Node<T> *&right) {
    List<T> *result = new List<T>();
    while (!isEnd(left) && !isEnd(right)) {
        if (data(left) < data(right)) {
            result->append(data(left));
            left = next(left);
        } else {
            result->append(data(right));
            right = next(right);
        }
    }
    while (!isEnd(left)) {
        result->append(data(left));
        left = next(left);
    }
    while (!isEnd(right)) {
        result->append(data(right));
        right = next(right);
    }
    left = result->head;
    return;
}

template <typename T> Node<T> *List<T>::sort(Node<T> *&current) {
    if (isEnd(current) || isLast(current)) {
        return current;
    }

    Node<T> *slow = current;
    Node<T> *fast = next(current);
    while (!isEnd(fast) && !isLast(fast)) {
        slow = next(slow);
        fast = next(next(fast));
    }

    Node<T> *mid = next(slow);
    nullfyNext(slow);

    Node<T> *left = sort(current);
    Node<T> *right = sort(mid);

    merge(left, right);
    head = left;

    return left;
}

class IntList : public List<int> {
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
        while (!isLast(current)) {
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

template <typename T> void List<T>::insert_after(T data, Node<T> *&current) {
    if (isEnd(current)) {
        current = new Node<T>(data);
    } else
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

template <typename T> void List<T>::remove_first() {
    Node<T> *current = head;
    head = current->next;
    delete current;
    return;
}

template <typename T> void List<T>::remove_last() {
    Node<T> *current = head;
    while (!isLast(current->next)) {
        current = current->next;
    }
    delete current->next;
    current->next = nullptr;
    return;
}
