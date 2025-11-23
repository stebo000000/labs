#include <stdio.h>
#define INT_SIZE 8

#if INT_SIZE == 8
typedef unsigned char MYINT;
#endif
#if INT_SIZE == 16
typedef unsigned short MYINT;
#endif
#if INT_SIZE == 32
typedef unsigned int MYINT;

#endif
#if INT_SIZE == 64
typedef unsigned long MYINT;
#endif

void printBin(MYINT x) {
    printf("bin: ");
    for (int i = sizeof(MYINT) * 8 - 1; i >= 0; i--) {
        printf("%d", (x >> i) & 1);
    }
    printf("\n");
    return;
}

void printHex(MYINT x) {
    char hexDigits[] = "0123456789ABCDEF";
    char buffer[INT_SIZE / 4];
    int i = 0;
    printf("hex: ");

    while (x >= 1) {
        buffer[i] = hexDigits[x % 16];
        x /= 16;
        i++;
    }

    while (i > 0) {
        printf("%c", buffer[--i]);
    }
    printf("\n");

    return;
}

void printDec(MYINT x) {
    printf("dec: ");
    printf("%d\n", x);
    return;
}

int main() {
    MYINT x;
    int n, p;

    printf("x n p\n");

    scanf("%ld %ld %ld", &x, &n, &p);

    if (INT_SIZE <= n + p) {
        printf("incorrect params");
    } else {
        MYINT mask = ~(~0 << n) << p << 1;

        // printBin(x);
        // printBin(mask);

        int result = x | mask;

        printDec(result);
        printHex(result);
        printBin(result);
    }

    return 0;
}
