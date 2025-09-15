#include <stdio.h>


float** input(FILE* fptr) {
    int rowLen, colLen;

    fscanf(fptr, "%d %d", &rowLen, &colLen);

    float** matrix = new float* [colLen];
    
    for (int  i = 0; i < colLen; i++)
    {
        matrix[i] = new float[rowLen];
        for (int j = 0; j < rowLen; j++)
        {
            fscanf(fptr, "%f", &matrix[i][j]);
        }
        
    }
    
    return matrix;
}


float findMean(float **matrix) {
    float positiveMean;
    int counter = 0;

    for (int  i = 0; i < sizeof(matrix) / sizeof(float*); i++)
    {
        for (int j = 0; j < sizeof(matrix[i]) / sizeof(float); j++)
        {
            if (matrix[i][j] >= 0)
            {
                positiveMean += matrix[i][j];
                counter++;
            }
            
        }
        
    }

    // if (counter)
    // {
    //     positiveMean /= counter;
    // }
    // else 
    // {
    //     positiveMean = -1;
    // }
    
    positiveMean = counter ? positiveMean /= counter : -1;
    
    return positiveMean;
}

float findProduct(float **matrix) {
    bool isAllZeros = true;
    float product = 1;

    for (int  i = 0; i < sizeof(matrix) / sizeof(float*); i++)
    {
        for (int j = 0; j < sizeof(matrix[i]) / sizeof(float); j++)
        {
            if (matrix[i][j] != 0)
            {
                product *= matrix[i][j];
                isAllZeros = false;
            }
            
        }
        
    }

    // if (isAllZeros)
    // {
    //     product = 0;
    // }

    // return product;
    
    return isAllZeros ? 0 : product;
}
