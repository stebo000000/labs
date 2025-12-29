#include "lab12-deque.h"
#include <cstdio>
// Ch\CharDeque

void CharDeque::operator>>(const char *filename) {
    if (filename == nullptr) {
        int current = front;
        while (current != back) {
            printf("%c ", data(current));
            current++;
        }
        printf("\n");
    } else {
        FILE *file = fopen(filename, "w");
        int current = front;
        while (current != back) {
            fprintf(file, "%c ", data(current));
            current++;
        }
        fprintf(file, "\n");
        fclose(file);
    }
}

void CharDeque::operator<<(const char *filename) {
    FILE *file = fopen(filename, "r");
    char data;
    while (fscanf(file, "%c ", &data) != EOF) {
        add_back(data);
    }
    fclose(file);
}

// IntDeque

void IntDeque::operator>>(const char *filename) {
    if (filename == nullptr) {
        int current = front;
        while (current != back) {
            printf("%d ", data(current));
            current++;
        }
        printf("\n");
    } else {
        FILE *file = fopen(filename, "w");
        int current = front;
        while (current != back) {
            fprintf(file, "%d ", data(current));
            current++;
        }
        fprintf(file, "\n");
        fclose(file);
    }
}

void IntDeque::operator<<(const char *filename) {
    FILE *file = fopen(filename, "r");
    int data;
    while (fscanf(file, "%d", &data) != EOF) {
        add_back(data);
    }
    fclose(file);
}

CharDeque CharDeque::merge(CharDeque &left, CharDeque &right) {
    CharDeque result;
    char leftE = left.pop_back();
    char rightE = right.pop_back();
    while (!left.is_empty() && !right.is_empty()) {
        if (leftE > rightE) {
            result.add_front(leftE);
            leftE = left.pop_back();
        } else {
            result.add_front(rightE);
            rightE = right.pop_back();
        }
    }
    if (leftE > rightE) {
        result.add_front(leftE);
        result.add_front(rightE);
    } else {
        result.add_front(rightE);
        result.add_front(leftE);
    }
    while (!left.is_empty()) {
        result.add_front(left.pop_back());
    }
    while (!right.is_empty()) {
        result.add_front(right.pop_back());
    }

    while (!result.is_empty()) {
        result.btf(left);
    }
    return left;
}

CharDeque CharDeque::sort(CharDeque &deque) {
    CharDeque left;
    CharDeque right;
    while (!deque.is_empty()) {
        deque.btf(left);
        if (!deque.is_empty()) {
            deque.btf(right);
        }
    }
    if (right.is_empty()) {
        while (!left.is_empty()) {
            left.btf(deque);
        }
        return deque;
    }
    // printf("ww\n");
    CharDeque left1 = sort(left);
    CharDeque right1 = sort(right);
    merge(left1, right1);
    // left1 >> nullptr;
    while (!left1.is_empty()) {
        left1.btf(deque);
    }
    // deque >> nullptr;
    return deque;
}
