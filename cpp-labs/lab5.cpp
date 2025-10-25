#include <stdio.h>
#include <math.h>
#include "lab5-tools.h"

float func(float x) {
    return x / 2;
}


int main(int argc, char const *argv[]) {
    FILE* fptr;
    float *arr1, *arr2, *arr3;
    
    int arrL1, arrL2, arrL3;
    
    fptr = fopen(argv[1], "r");
    input(fptr, arr1, arrL1);
    fclose(fptr);

    fptr = fopen(argv[2], "r");
    input(fptr, arr2, arrL2);
    fclose(fptr);
    
    fptr = fopen(argv[3], "r");
    input(fptr, arr3, arrL3);
    fclose(fptr);

    float min, max;
    
    input(min);
    input(max);

    printf("arrs after func\n");
    
    
    printArray(arr1, arrL1, fabsf);
    printArray(arr2, arrL2, func);
    printArray(arr3, arrL3, [](float x){return x * 2;});
    
    printf("\narrs without func\n");
    printArray(arr1, arrL1, [](float x){return x;});
    printArray(arr2, arrL2, [](float x){return x;});
    printArray(arr3, arrL3, [](float x){return x;});
    printf("\n");
    
    if (min > max)
    {
        printf("min more then max");
    }    

    float prodInArr1 = 1;
    float prodInArr2 = 1;
    float prodInArr3 = 1;

    bool isNull1 = true;
    bool isNull2 = true;
    bool isNull3 = true;

    findProduct(arr1, prodInArr1, isNull1, min, max, arrL1, fabsf);
    findProduct(arr2, prodInArr2, isNull2, min, max, arrL2, func);
    findProduct(arr3, prodInArr3, isNull3, min, max, arrL3, [](float x){return x * 2;});


    if (!isNull1 && !isNull2 && !isNull3)
    {
        if (prodInArr1 == prodInArr2 && prodInArr1 == prodInArr3)
        {
            printf("all same\n");
        }
        else
        {
            if (prodInArr1 == prodInArr2)
            {
                printf("%d, %d same\n", 1, 2);            
            }
            else if (prodInArr3 == prodInArr2)
            {
                printf("%d, %d same\n", 2, 3);            
            }
            else if (prodInArr1 == prodInArr3)
            {
                printf("%d, %d same\n", 1, 3);            
            }

            if (prodInArr1 <= prodInArr2)
            {
                if (prodInArr3 <= prodInArr1)
                {
                    printf("min product in %d array\n", 3);
                }
                else
                {
                    printf("min product in %d array\n", 1);
                }
            }
            else
            {
                if (prodInArr3 <= prodInArr2)
                {
                    printf("min product in %d array\n", 3);
                }
                else
                {
                    printf("min product in %d array\n", 2);
                }
            }
        }
    }
    else if (!isNull1 && !isNull2)
    {
        if (prodInArr1 == prodInArr2)
        {
            printf("%d, %d same\n", 1, 2);            
        }
        else if (prodInArr1 < prodInArr2)
        {
            printf("min product in %d array\n", 1);
        }
        else
        {
            printf("min product in %d array\n", 2);
        }
    }
    else if (!isNull1 && !isNull3)
    {
        if (prodInArr1 == prodInArr3)
        {
            printf("%d, %d same\n", 1, 3);            
        }
        else if (prodInArr1 < prodInArr3)
        {
            printf("min product in %d array\n", 1);
        }
        else
        {
            printf("min product in %d array\n", 3);
        }
    }
    else if (!isNull2 && !isNull3)
    {
        if (prodInArr2 == prodInArr3)
        {
            printf("%d, %d same\n", 2, 3);            
        }
        else if (prodInArr2 < prodInArr3)
        {
            printf("min product in %d array\n", 2);
        }
        else
        {
            printf("min product in %d array\n", 3);
        }
    }
    else if (!isNull1)
    {
        printf("min product in %d array\n", 1);
    }
    
    else if (!isNull2)
    {
        printf("min product in %d array\n", 2);
    }
    
    else if (!isNull3)
    {
        printf("min product in %d array\n", 3);
    }
    
    else
    {
        printf("all array are empty\n");
    }

    freeMem(arr1);
    freeMem(arr2);
    freeMem(arr3);

    return 0;
}