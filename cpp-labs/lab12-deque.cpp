#include "lab12-deque.h"
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
    while (fscanf(file, "%c", &data) != EOF) {
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
