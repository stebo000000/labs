#include <stdio.h>

void findProduct(float* array, float& prod, bool& isNotNull, float min, float max, int arrL) {
    for (int i = 0; i < arrL; i++) {
        if (array[i] >= min && array[i <= max])
        {
            prod = prod * array[i];
            isNotNull = true;
        }
    }

    return;
}

int input(FILE* fptr, float* arr, int& arrL) {
    fscanf(fptr, "%d", &arrL);
    // scanf("%d", &arrLen);
    for (int i = 0; i < arrL; i++)
    {
        fscanf(fptr, "%f", &arr[i]);
        // scanf("%f", &arr[i]);
    }

    return 0;
}

int input(FILE* fptr, float &num) {
    fscanf(fptr, "%f", &num);
    return 0;
}