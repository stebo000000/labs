#include <stdio.h>


int main(int argc, char const *argv[]) {
    unsigned int x, n, p;

    printf("x n p\n");

    scanf("%d %d %d", &x, &n, &p);

    unsigned int mask = ~(1 << n) << p; // ~0

    unsigned int result = x | mask;

    printf("", result);

    return 0;
}
