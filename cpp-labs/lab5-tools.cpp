#include <stdio.h>
#include "lab5-tools.h"
#define NMAX 10

void findProduct(float *array, float& prod, bool& isNull, float min, float max, int arrL, functional f) {
    for (int i = 0; i < arrL; i++) {
        if (f(array[i]) >= min && f(array[i]) <= max)
        {
            prod = prod * f(array[i]);
            isNull = false;
        }
    }

    return;
}

void input(FILE* fptr, float*& arr, int& arrL) {
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

    arr = new float[arrL];
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

void printArray(float *arr, int arrLen, functional f) {
    for (int i = 0; i < arrLen; i++)
    {
        printf("%f ", f(arr[i]));
    }
    printf("\n");
    return;
}


void freeMem(float*& arr) {
    delete[] arr;
    return;
}
