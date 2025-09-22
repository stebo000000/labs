#include <stdio.h>

#define NMAX 10


void input(float matrix[NMAX][NMAX], int& colLen, int& rowLen, FILE* fptr) {
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
        for (int j = 0; j < rowLen; j++)
        {
            fscanf(fptr, "%f", &matrix[i][j]);
        }
        
    }
    
    return;
}


float findMean(float matrix[NMAX][NMAX], const int colLen, const int rowLen) {
    float positiveMean = 0;
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

float findProduct(float matrix[NMAX][NMAX], const int colLen, const int rowLen) {
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


void printMatrix(float matrix[NMAX][NMAX], const int colLen, const int rowLen) {
    for (int  i = 0; i < colLen; i++)
    {
        for (int j = 0; j < rowLen; j++)
        {
            printf("%f ", matrix[i][j]);
        }
        printf("\n");
        
    }
}
