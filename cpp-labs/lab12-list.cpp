#include "lab12-list.h"
#include <cstdio>
//  IntList
void IntList::operator>>(const char *filename) {
    if (filename == nullptr) {
        Node<int> *current = head;
        while (current != nullptr) {
            printf("%d ", current->data);
            current = next(current);
        }
        printf("\n");
    } else {
        FILE *file = fopen(filename, "w");
        Node<int> *current = head;
        while (current != nullptr) {
            fprintf(file, "%d ", current->data);
            current = next(current);
        }
        fprintf(file, "\n");
        fclose(file);
    }
}

void IntList::operator<<(const char *filename) {
    FILE *file = fopen(filename, "r");
    int data;
    while (fscanf(file, "%d", &data) != EOF) {
        append(data);
    }
    fclose(file);
}

bool IntList::isConteinsOdd() {
    Node<int> *current = head;
    bool isOdd = false;
    while (current != nullptr && !isOdd) {
        if (data(current) % 2 != 0) {
            isOdd = true;
        }
        current = next(current);
    }
    return isOdd;
}

void IntList::deleteByCondition(int num) {
    Node<int> *current = head;
    Node<int> *temp = nullptr;
    while (current != nullptr) {
        if (data(current) > num) {
            temp = next(current);
            remove(current);
            current = temp;
        } else
            current = next(current);
    }
}

// FloatList

void FloatList::operator>>(const char *filename) {
    if (filename == nullptr) {
        Node<float> *current = head;
        while (current != nullptr) {
            printf("%f ", data(current));
            current = next(current);
        }
        printf("\n");
    } else {
        FILE *file = fopen(filename, "w");
        Node<float> *current = head;
        while (current != nullptr) {
            fprintf(file, "%f ", data(current));
            current = next(current);
        }
        fprintf(file, "\n");
        fclose(file);
    }
}

void FloatList::operator<<(const char *filename) {
    FILE *file = fopen(filename, "r");
    float data;
    while (fscanf(file, "%f", &data) != EOF) {
        append(data);
    }
    fclose(file);
}

float FloatList::findBiggest() {
    Node<float> *current = head;
    float max = data(current);
    while (current != nullptr) {
        if (data(current) > max) {
            max = data(current);
        }
        current = next(current);
    }
    return max;
}

bool FloatList::isInRange() {
    Node<float> *current = head;
    bool isInRange = false;
    while (current != nullptr && !isInRange) {
        if (data(current) > 0 && data(current) < 1) {
            isInRange = true;
        }
        current = next(current);
    }
    return isInRange;
}

void FloatList::deleteByCondition(float num) {
    Node<float> *current = head;
    Node<float> *temp = nullptr;
    while (current != nullptr) {
        if (data(current) > num) {
            temp = next(current);
            remove(current);
            current = temp;
        } else
            current = next(current);
    }
}
