#include <stdio.h>
#include "matrix-processing-d.h"


int main(int argc, const char* argv[])
{
    FILE* fptr;
    fptr = fopen(argv[1], "r");

    float** matrix1;
    float** matrix2;

    int colLen1, colLen2, rowLen1, rowLen2;

    input(fptr, colLen1, colLen2);
    input(fptr, rowLen1, rowLen2);

    printMatrix(matrix1, colLen1, rowLen1);
    printMatrix(matrix2, colLen2, rowLen2);

    fclose(fptr);

    float mean1 = findMean(matrix1, colLen1, rowLen1);
    float mean2 = findMean(matrix2, colLen2, rowLen2);

    float prod;

    if (mean1 && mean2)
    {
        if (mean1 == mean2)
        {
            prod = findProduct(matrix1, colLen1, rowLen1);
            printf("%f", prod);
            prod = findProduct(matrix2, colLen2, rowLen2);
            printf("%f", prod);
        }
        else if (mean1 < mean2)
        {
            prod = findProduct(matrix1, colLen1, rowLen1);
            printf("%f", prod);
        }
        else
        {
            prod = findProduct(matrix2, colLen2, rowLen2);
            printf("%f", prod);
        }
    }
    else if (mean1)
    {
        prod = findProduct(matrix1, colLen1, rowLen1);
        printf("%f", prod);
    }
    else if (mean2)
    {
        prod = findProduct(matrix2, colLen2, rowLen2);
        printf("%f", prod);
    }
    else
    {
        printf("no right mean");
    }

    freeMem(matrix1, colLen1, rowLen1);
    freeMem(matrix2, colLen2, rowLen2);
    
    return 0;
}
