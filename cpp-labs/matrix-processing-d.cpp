#include <stdio.h>


void input(float** matrix, int& colLen, int& rowLen, FILE* fptr) {
    fscanf(fptr, "%d %d", &rowLen, &colLen);
    
    for (int  i = 0; i < colLen; i++)
    {
        matrix[i] = new float[rowLen];
        for (int j = 0; j < rowLen; j++)
        {
            fscanf(fptr, "%f", &matrix[i][j]);
        }
        
    }
    
    return;
}


float findMean(float **matrix, const int colLen, const int rowLen) {
    float positiveMean;
    int counter = 0;

    for (int  i = 0; i < colLen; i++)
    {
        for (int j = 0; j < rowLen; j++)
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

float findProduct(float** matrix, const int colLen, const int rowLen) {
    bool isAllZeros = true;
    float product = 1;

    for (int  i = 0; i < colLen; i++)
    {
        for (int j = 0; j < rowLen; j++)
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


void freeMem(float** matrix, int& colLen, int& rowLen) {
    for (int i = 0; i < colLen; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
    
    return;
}


void printMatrix(float** matrix, int& colLen, int& rowLen) {
    for (int  i = 0; i < colLen; i++)
    {
        for (int j = 0; j < rowLen; j++)
        {
            printf("%f ", matrix[i][j]);
        }
        printf("\n");
        
    }
    return;
}
