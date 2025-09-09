#include <iostream>

float findProduct(float* array, float min, float max) {
    float prod = 1;
    for (int i = 0; i < sizeof(array) / sizeof(array[0]); i++) {
        if (array[i] >= min && array[i <= max])
        {
            prod = prod * array[i];
        }
    }

    return prod;
}

int compare(float* minInArr) {

    if (minInArr[0] == minInArr[1] && minInArr[0] == minInArr[2])
    {
        printf("all same");
    }
    else
    {
        if (minInArr[0] == minInArr[1])
        {
            printf("%d, %d same", 1, 2);            
        }
        else if (minInArr[3] == minInArr[1])
        {
            printf("%d, %d same", 1, 3);            
        }
        else if (minInArr[3] == minInArr[2])
        {
            printf("%d, %d same", 2, 3);            
        }
        
    }

    float tempMin = minInArr[0];
    int res;
    for (int i = 1; i < 3; i++)
    {
        if (tempMin > minInArr[i])
        {
            tempMin = minInArr[i];
            res = i + 1;
        }   
    }
    
    printf("min product in %d array", res);

    return 0;
}

float* inputArray() {
    int arrLen;
    scanf("%d", &arrLen);
    float arr[arrLen];
    for (int i = 0; i < arrLen; i++)
    {
        scanf("%f", &arr[i]);
    }

    return arr;
}

float inputNum() {
    float num;
    scanf("%f", &num);
    return num;
}