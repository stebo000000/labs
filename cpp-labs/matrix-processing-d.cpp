#include <stdio.h>


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

    matrix = new float*[rowLen];

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


float findMean(float **matrix, int colLen, int rowLen) {
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

void findProduct(float** matrix, int colLen, int rowLen, float*& result) {
    
    for (int  i = 0; i < colLen; i++)
    {
        bool isAllZeros = true;
        float product = 1;
        for (int j = 0; j < rowLen; j++)
        {
            if (matrix[i][j] != 0)
            {
                product *= matrix[i][j];
                isAllZeros = false;
            }
            
        }
        result[i] = isAllZeros ? 0 : product;
    }    
    return;
}


void freeMem(float**& matrix, int colLen) {
    for (int i = 0; i < colLen; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
    
    return;
}

void freeMem(float*& arr) {
    delete[] arr;
    
    return;
}

void print(float* arr, int colLen) {
    for (int i = 0; i < colLen; i++)
    {
        if (!arr[i])
        {
            printf("%d: all zeros in row\n", i);
        }
        else
        {
            printf("%d: %f\n", i, arr[i]);
        }
    }
    
    return;
}


void printMatrix(float** matrix, int colLen, int rowLen) {
    for (int  i = 0; i < colLen; i++)
    {
        for (int j = 0; j < rowLen; j++)
        {
            printf("%f ", matrix[i][j]);
        }
        printf("\n");
        
    }
    printf("\n");
    return;
}
