#include "lab12-deque.h"
#include "lab12-list.h"
#include <stdio.h>

void fillList(List<int> &list) {
    int num;
    for (int i = 0; i < 0; i++) {
        list.append(i);
    }
}

bool isConteinsOdd(List<int> &list) {
    Node<int> *current = list.head;

    while (current != nullptr) {
        if (current->data % 2 != 0) {
            return true;
        }
        current = current->next;
    }
    return false;
}

bool isBigger(Node<int> *element, int num) { return element->data > num; }

void deleteByCondition(List<int> &list, int num) {
    Node<int> *current = list.head;
    Node<int> *temp = nullptr;
    while (current != nullptr) {
        if (isBigger(current, num)) {
            temp = current->next;
            list.remove(current);
            current = temp;
        } else
            current = current->next;
    }
}

void printList(List<int> &list) {
    Node<int> *current = list.head;
    while (current != nullptr) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

void printDeque(Deque<char> &deque) {
    int current = deque.front;
    while (current != deque.back) {
        printf("%c ", deque.deque[current].data);
        current++;
    }
    printf("\n");
}

void fillDeque(Deque<char> &deque) {
    deque.add_back('a');
    deque.add_back('b');
    deque.add_back('C');
    deque.add_back('d');
    deque.add_back('E');
}

void separateByCaps(Deque<char> &deque, Deque<char> &dequeLitle,
                    Deque<char> &dequeBig) {
    while (!deque.is_empty()) {
        char current = deque.pop_front();
        if (current >= 'A' && current <= 'Z') {
            dequeBig.add_back(current);
        } else {
            dequeLitle.add_front(current);
        }
    }
}

int main(int argc, char **argv) {
    List<int> list;
    Deque<char> deque;
    Deque<char> dequeLitle;
    Deque<char> dequeBig;
    fillDeque(deque);
    printDeque(deque);
    separateByCaps(deque, dequeLitle, dequeBig);
    printDeque(dequeLitle);
    printDeque(dequeBig);

    fillList(list);
    if (isConteinsOdd(list)) {
        int num;
        scanf("%d", &num);
        deleteByCondition(list, num);
    }
    printList(list);

    return 0;
}
