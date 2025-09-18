#include <stdio.h>
#include "addfuncs.h"

#define NMAX 10


int main() {
    float arr1[NMAX], arr2[NMAX], arr3[NMAX];

    int arrL1, arrL2, arrL3;

    while (arrL1 < 0 || arrL1 > NMAX)
    {
        scanf("%d", &arrL1);
        if (arrL1 <= 0)
        {
            printf("%d less then 0\n", arrL1);
        }
        if (arrL1 > NMAX)
        {
            printf("%d more then %d\n", arrL1, NMAX);
        }
        
    }
    for (int i = 0; i < arrL1; i++)
    {
        scanf("%f", &arr1[i]);
    }

    while (arrL2 < 0 || arrL2 > NMAX)
    {
        scanf("%d", &arrL2);
        if (arrL2 <= 0)
        {
            printf("%d less then 0\n", arrL2);
        }
        if (arrL2 > NMAX)
        {
            printf("%d more then %d\n", arrL2, NMAX);
        }
        
    }
    for (int i = 0; i < arrL2; i++)
    {
        scanf("%f", &arr2[i]);
    }
    
    while (arrL3 < 0 || arrL3 > NMAX)
    {
        scanf("%d", &arrL3);
        if (arrL3 <= 0)
        {
            printf("%d less then 0\n", arrL3);
        }
        if (arrL3 > NMAX)
        {
            printf("%d more then %d\n", arrL3, NMAX);
        }
        
    }
    for (int i = 0; i < arrL3; i++)
    {
        scanf("%f", &arr3[i]);
    }


    float min, max;
    
    scanf("%f", &min);
    scanf("%f", &max);

    float prodInArr1 = 1;
    float prodInArr2 = 1;
    float prodInArr3 = 1;

    bool isNull1 = true;
    bool isNull2 = true;
    bool isNull3 = true;

    for (int i = 0; i < arrL1; i++) {
        if (arr1[i] >= min && arr1[i] <= max)
        {
            prodInArr1 = prodInArr1 * arr1[i];
            isNull1 = false;
        }
    }
    for (int i = 0; i < arrL2; i++) {
        if (arr2[i] >= min && arr2[i] <= max)
        {
            prodInArr2 = prodInArr2 * arr2[i];
            isNull2 = false;
        }
    }
    for (int i = 0; i < arrL3; i++) {
        if (arr3[i] >= min && arr3[i] <= max)
        {
            prodInArr3 = prodInArr3 * arr3[i];
            isNull3 = false;
        }
    }


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

    return 0;
}