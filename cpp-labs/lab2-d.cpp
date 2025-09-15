#include <stdio.h>
#include "matrix-processing-d.h"

#define NMAX 10

int main(int argc, const char* argv[])
{
    FILE* fptr;
    fptr = fopen(argv[1], "r");

    float** matrix1 = input(fptr);
    float** matrix2 = input(fptr);

    fclose(fptr);

    float mean1 = findMean(matrix1);
    float mean2 = findMean(matrix2);

    float prod;

    if (mean1 && mean2)
    {
        if (mean1 == mean2)
        {
            prod = findProduct(matrix1);
            printf("%f", prod);
            prod = findProduct(matrix2);
            printf("%f", prod);
        }
        else if (mean1 < mean2)
        {
            prod = findProduct(matrix1);
            printf("%f", prod);
        }
        else
        {
            prod = findProduct(matrix2);
            printf("%f", prod);
        }
    }
    else if (mean1)
    {
        prod = findProduct(matrix1);
        printf("%f", prod);
    }
    else if (mean2)
    {
        prod = findProduct(matrix2);
        printf("%f", prod);
    }
    else
    {
        printf("no right mean");
    }
    
    return 0;
}
