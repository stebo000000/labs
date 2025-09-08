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
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (minInArr[i] == minInArr[j])
                {
                    printf("%d, %d same", i+1, j+1);
                }
            
            }
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
    
    return res;
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