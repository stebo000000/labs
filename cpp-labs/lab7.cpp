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


void input(MYINT& x, int& n, int& p) {
    printf("x n p\n");
    do
    {
        scanf("%d %d %d", &x, &n, &p);
        if (INT_SIZE <= n + p)
        {
            printf("incorrect params\n");
        }
        
    } while (INT_SIZE <= n + p);
    
    return;
}

MYINT formMask(int n, int p) {
    return ~(~0 << n) << p;
}
// цикл сдвиг влево на k бит

MYINT applyMask(MYINT x, MYINT mask) {
    return x | mask;
}

MYINT leftShift(MYINT x, int k) {
    return (x << k);
}

MYINT rightShift(MYINT x, int k) {
    return (x >> (sizeof(MYINT) * 8 - k));
}

MYINT left_shift(MYINT x, int k) {
    return leftShift(x, k) | rightShift(x, k);
} 

void inputk(int& k) {
    printf("input k: ");
    do
    {
        scanf("%d", &k);
        if (k > 8 * sizeof(MYINT))
        {
            printf("incorrect k\n");
        }
        
    } while (k > 8 * sizeof(MYINT));
}

int main() {
    MYINT x;
    int n, p;

    input(x, n, p);

    MYINT mask = formMask(n, p);

<<<<<<< HEAD
    printBin(x);
    // printBin(mask);
=======
    if (INT_SIZE <= n + p) {
        printf("incorrect params");
    } else {
        MYINT mask = ~(~0 << n) << p << 1;
>>>>>>> 496e9ad42787f31b3f296bb65a6e977460117c84

    MYINT result = applyMask(x, mask);

    int k;
    inputk(k);
    printBin(left_shift(x, k));

    // printDec(result);
    // printHex(result);
    // printBin(result);

    return 0;
}
