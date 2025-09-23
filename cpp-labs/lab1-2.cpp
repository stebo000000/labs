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

void input(FILE* fptr, float arr[], int& arrL) {
    do    
    {
        scanf("%d", &arrL);
        if (arrL <= 0)
        {
            printf("%d less then 0\n", arrL);
        }
        if (arrL > NMAX)
        {
            printf("%d more then %d\n", arrL, NMAX);
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


int main(int argc, char const *argv[]) {
    FILE* fptr;
    float arr1[NMAX], arr2[NMAX], arr3[NMAX];
    
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

    findProduct(arr1, prodInArr1, isNull1, min, max, arrL1);
    findProduct(arr2, prodInArr2, isNull2, min, max, arrL2);
    findProduct(arr3, prodInArr3, isNull3, min, max, arrL3);


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