#include <stdio.h>


void input(float* matrix, const int rowLen, FILE* fptr) {
    for (int j = 0; j < rowLen; j++)
    {
        fscanf(fptr, "%f", &matrix[j]);
    }
    
    return;
}


float** input(FILE* fptr) {
    int rowLen, colLen;

    fscanf(fptr, "%d %d", &rowLen, &colLen);

    float** matrix = new float* [colLen];
    
    for (int  i = 0; i < colLen; i++)
    {
        matrix[i] = new float[rowLen];
        input(matrix[i], rowLen, fptr);
        
    }
    
    return matrix;
}


void findMean(float* matrix, float& positiveMean, int& counter) {
        for (int j = 0; j < sizeof(matrix) / sizeof(float); j++)
        {
            if (matrix[j] >= 0)
            {
                positiveMean += matrix[j];
                counter++;
            }
            
        }
    
    return;
}


float findMean(float** matrix) {
    float positiveMean;
    int counter = 0;

    for (int  i = 0; i < sizeof(matrix) / sizeof(float*); i++)
    {
        findMean(matrix[i], positiveMean, counter);
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


void findProduct(float* matrix, float& product, bool& isAllZeros) {
    for (int j = 0; j < sizeof(matrix) / sizeof(float); j++)
    {
        if (matrix[j] != 0)
        {
            product *= matrix[j];
            isAllZeros = false;
        }
        
    }
    
    return;
}

float findProduct(float** matrix) {
    bool isAllZeros = true;
    float product = 1;

    for (int  i = 0; i < sizeof(matrix) / sizeof(float*); i++)
    {
        findProduct(matrix[i], product, isAllZeros);
    }

    // if (isAllZeros)
    // {
    //     product = 0;
    // }

    // return product;
    
    return isAllZeros ? 0 : product;
}


void printMatrix(float* matrix) {
    for (int j = 0; j < sizeof(matrix) / sizeof(float); j++)
    {
        printf("%f ", matrix[j]);
    }
}

void printMatrix(float** matrix) {
    for (int  i = 0; i < sizeof(matrix) / sizeof(float*); i++)
    {
        printMatrix(matrix[i]);
        printf("\n");
        
    }
}
