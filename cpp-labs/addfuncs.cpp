#include <stdio.h>

#define NMAX 10

void findProduct(float array[NMAX], float& prod, bool& isNull, const float min, const float max, const int arrL) {
    for (int i = 0; i < arrL; i++) {
        if (array[i] >= min && array[i] <= max)
        {
            prod = prod * array[i];
            isNull = false;
        }
    }

    return;
}

void input(FILE* fptr, float arr[NMAX], int& arrL) {
    do
    {
        scanf("%d", &arrL);
        if (arrL <= 0)
        {
            printf("%d less then 0\n", arrL);
        }
        if (arrL > NMAX)
        {
            printf("%d more then %d 0\n", arrL, NMAX);
        }
        
    }
    while (arrL < 0 || arrL > NMAX);
    for (int i = 0; i < arrL; i++)
    {
        fscanf(fptr, "%f", &arr[i]);
    }

    return;
}

void input(float& num) {
    scanf("%f", &num);
    return;
}