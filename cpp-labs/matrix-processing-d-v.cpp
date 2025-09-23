#include <stdio.h>


void input(float*& matrix, int rowLen, FILE* fptr) {
    matrix = new float[rowLen];
    for (int j = 0; j < rowLen; j++)
    {
        fscanf(fptr, "%f", &matrix[j]);
    }
    
    return;
}


void input(float**& matrix, int& colLen, int& rowLen, FILE* fptr) {
    do
    {
        scanf("%d %d", &rowLen, &colLen);
        if (rowLen <= 0 || colLen <= 0)
        {
            printf("len less then 0\n");
        }
    }
    while (rowLen <= 0 || colLen <= 0);

    matrix = new float* [colLen];
    
    for (int  i = 0; i < colLen; i++)
    {
        input(matrix[i], rowLen, fptr);
        
    }
    
    return;
}


void findMean(float* matrix, float& positiveMean, int& counter, int rowLen) {
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


float findMean(float** matrix, int colLen, int rowLen) {
    float positiveMean = 0;
    int counter = 0;

    for (int  i = 0; i < colLen; i++)
    {
        findMean(matrix[i], positiveMean, counter, rowLen);
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


void findProduct(float* matrix, float& product, bool& isAllZeros, int rowLen) {
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

float findProduct(float** matrix, int colLen, int rowLen) {
    bool isAllZeros = true;
    float product = 1;

    for (int  i = 0; i < colLen; i++)
    {
        findProduct(matrix[i], product, isAllZeros, rowLen);
    }

    // if (isAllZeros)
    // {
    //     product = 0;
    // }

    // return product;
    
    return isAllZeros ? 0 : product;
}


void freeMem(float**& matrix, int colLen) {
    for (int i = 0; i < colLen; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
    
    return;
}


void printMatrix(float* matrix, int rowLen) {
    for (int j = 0; j < rowLen; j++)
    {
        printf("%f ", matrix[j]);
    }
    return;
}

void printMatrix(float** matrix, int colLen, int rowLen) {
    for (int  i = 0; i < colLen; i++)
    {
        printMatrix(matrix[i], rowLen);
        printf("\n");
        
    }
    printf("\n");
    return;
}
