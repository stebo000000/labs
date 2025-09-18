#include <stdio.h>
#include "matrix-processing-d.h"


int main(int argc, const char* argv[])
{
    FILE* fptr;
    fptr = fopen(argv[1], "r");

    float** matrix1;
    float** matrix2;

    int colLen1, colLen2, rowLen1, rowLen2;

    input(matrix1, colLen1, rowLen1, fptr);
    input(matrix2, colLen2, rowLen2, fptr);

    printMatrix(matrix1, colLen1, rowLen1);
    printMatrix(matrix2, colLen2, rowLen2);

    fclose(fptr);

    float mean1 = findMean(matrix1, colLen1, rowLen1);
    float mean2 = findMean(matrix2, colLen2, rowLen2);

    float prod;

    if (mean1 != -1 && mean2 != -1)
    {
        if (mean1 == mean2)
        {
            prod = findProduct(matrix1, colLen1, rowLen1);
            printf("%f\n", prod);
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
    else if (mean1 != -1)
    {
        prod = findProduct(matrix1, colLen1, rowLen1);
        printf("%f", prod);
    }
    else if (mean2 != -1)
    {
        prod = findProduct(matrix2, colLen2, rowLen2);
        printf("%f", prod);
    }
    else
    {
        printf("no right mean");
    }

    freeMem(matrix1, colLen1);
    freeMem(matrix2, colLen2);
    
    return 0;
}
