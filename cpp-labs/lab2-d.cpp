#include <stdio.h>
#include "matrix-processing-d.h"


int main(int argc, const char* argv[])
{
    FILE* fptr;
    
    float** matrix1;
    float** matrix2;
    
    int colLen1, colLen2, rowLen1, rowLen2;
    
    fptr = fopen(argv[1], "r");
    input(matrix1, colLen1, rowLen1, fptr);
    fclose(fptr);
    
    fptr = fopen(argv[2], "r");
    input(matrix2, colLen2, rowLen2, fptr);
    fclose(fptr);

    printMatrix(matrix1, colLen1, rowLen1);
    printMatrix(matrix2, colLen2, rowLen2);


    float mean1 = findMean(matrix1, colLen1, rowLen1);
    float mean2 = findMean(matrix2, colLen2, rowLen2);

    float prod;

    float* result1 = new float[colLen1];
    float* result2 = new float[colLen2];

    if (mean1 != -1 && mean2 != -1)
    {
        if (mean1 == mean2)
        {
            findProduct(matrix1, colLen1, rowLen1, result1);
            print(result1, colLen1);
            findProduct(matrix2, colLen2, rowLen2, result2);
            print(result2, colLen2);
        }
        else if (mean1 < mean2)
        {
            findProduct(matrix1, colLen1, rowLen1, result1);
            print(result1, colLen1);
            
        }
        else
        {
            findProduct(matrix2, colLen2, rowLen2, result2);
            print(result2, colLen2);
            
        }
    }
    else if (mean1 != -1)
    {
        findProduct(matrix1, colLen1, rowLen1, result1);
        print(result1, colLen1);
        
    }
    else if (mean2 != -1)
    {
        findProduct(matrix2, colLen2, rowLen2, result2);
        print(result2, colLen2);
        
    }
    else
    {
        printf("no right mean");
    }

    freeMem(matrix1, colLen1);
    freeMem(matrix2, colLen2);
    freeMem(result1);
    freeMem(result2);
    
    return 0;
}
