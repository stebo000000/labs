#include <stdlib.h>
#include <stdio.h>
#include "addfuncs.h"

using namespace std;

int main(int argc, char *argv[]) {
    FILE* fptr;
    fptr = fopen(argv[1], "r");
    float arr1[10];
    float arr2[10];
    float arr3[10];

    int arrL1;
    int arrL2;
    int arrL3;

    input(fptr, arr1, arrL1);
    input(fptr, arr2, arrL2);
    input(fptr, arr3, arrL3);

    float min;
    float max;

    input(fptr, min);
    input(fptr, max);

    fclose(fptr);
    float prodInArr1 = 1;
    float prodInArr2 = 1;
    float prodInArr3 = 1;

    bool isNotNull1 = false;
    bool isNotNull2 = false;
    bool isNotNull3 = false;

    findProduct(arr1, prodInArr1, isNotNull1, min, max, arrL1);
    findProduct(arr2, prodInArr1, isNotNull2, min, max, arrL2);
    findProduct(arr3, prodInArr1, isNotNull3, min, max, arrL3);


    if (isNotNull1 && isNotNull2 && isNotNull3)
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
    else if (isNotNull1 && isNotNull2)
    {

    }
    else if (isNotNull1 && isNotNull3)
    {

    }
    else if (isNotNull2 && isNotNull3)
    {

    }
    else
    {
        printf("empty array\n");
    }

    return 0;
}