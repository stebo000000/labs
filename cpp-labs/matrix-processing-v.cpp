#include <stdio.h>

#define NMAX 10


void input(float matrix[], int rowLen, FILE* fptr) {
    for (int j = 0; j < rowLen; j++)
    {
        fscanf(fptr, "%f", &matrix[j]);
    }
    
    return;
}

void input(float matrix[][NMAX], int& colLen, int& rowLen, FILE* fptr) {
    do
    {
        scanf("%d %d", &rowLen, &colLen);
        if (rowLen <= 0 || colLen <= 0)
        {
            printf("len less then 0\n");
        }
        if (rowLen > NMAX || colLen > NMAX)
        {
            printf("len more then %d 0\n", NMAX);
        }
        
    }
    while (rowLen <= 0 || colLen <= 0 || rowLen > NMAX || colLen > NMAX);
    
    for (int  i = 0; i < colLen; i++)
    {
        input(matrix[i], rowLen, fptr);
    }
    
    return;
}


void findMean(float matrix[], int colLen, int rowLen, float& positiveMean, int& counter) {
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

float findMean(float matrix[][NMAX], int colLen, int rowLen) {
    float positiveMean = 0;
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


void findProduct(float matrix[], int colLen, int rowLen, float& product, bool& isAllZeros) {
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

void findProduct(float matrix[][NMAX], int colLen, int rowLen) {
    bool isAllZeros = true;
    float product = 1;

    for (int  i = 0; i < colLen; i++)
    {
        isAllZeros = true;
        product = 1;
        findProduct(matrix[i], colLen, rowLen, product, isAllZeros);
        if (isAllZeros)
        {
            printf("%d: all zeros in row\n", i);
        }
        else
        {
            printf("%d: %f\n", i, product);
        }
    }    
    return;
}


void printMatrix(float matrix[], int rowLen) {
    for (int j = 0; j < rowLen; j++)
    {
        printf("%f ", matrix[j]);
    }
    return;
}

void printMatrix(float matrix[][NMAX], int colLen, int rowLen) {
    for (int  i = 0; i < colLen; i++)
    {
        printMatrix(matrix[i], rowLen);
        printf("\n");
        
    }
    printf("\n");
    return;
}
