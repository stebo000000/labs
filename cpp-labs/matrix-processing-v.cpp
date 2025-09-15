#include <stdio.h>

#define NMAX 10

void input(float matrix[NMAX], const int rowLen, FILE* fptr) {
    for (int j = 0; j < rowLen; j++)
    {
        fscanf(fptr, "%f", &matrix[j]);
    }
    
    return;
}


void input(float matrix[NMAX][NMAX], int& colLen, int& rowLen, FILE* fptr) {
    fscanf(fptr, "%d %d", &rowLen, &colLen);
    
    for (int  i = 0; i < colLen; i++)
    {
        input(matrix[i], rowLen, fptr);
    }
    
    return;
}


void findMean(float matrix[NMAX], const int colLen, const int rowLen, float& positiveMean, int& counter) {
        for (int j = 0; j < rowLen; j++)
        {
            if (matrix[j] >= 0)
            {
                positiveMean += matrix[j];
                counter++;
            }
            
        }
    
    return;
}


float findMean(float matrix[NMAX][NMAX], const int colLen, const int rowLen) {
    float positiveMean;
    int counter = 0;

    for (int  i = 0; i < colLen; i++)
    {
        findMean(matrix[i], colLen, rowLen, positiveMean, counter);
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


void findProduct(float matrix[NMAX], const int colLen, const int rowLen, float& product, bool& isAllZeros) {
    for (int j = 0; j < rowLen; j++)
    {
        if (matrix[j] != 0)
        {
            product *= matrix[j];
            isAllZeros = false;
        }
        
    }
    
    return;
}

float findProduct(float matrix[NMAX][NMAX], const int colLen, const int rowLen) {
    bool isAllZeros = true;
    float product = 1;

    for (int  i = 0; i < colLen; i++)
    {
        findProduct(matrix[i], colLen, rowLen, product, isAllZeros);
    }

    // if (isAllZeros)
    // {
    //     product = 0;
    // }

    // return product;
    
    return isAllZeros ? 0 : product;
}
