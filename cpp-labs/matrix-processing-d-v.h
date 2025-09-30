#pragma once

#include <stdio.h>


float** input(float**& matrix, int& colLen, int& rowLen, FILE* fptr);

float findMean(float **matrix, int colLen, int rowLen);

void findProduct(float **matrix, int colLen, int rowLen);

void printMatrix(float** matrix, int colLen, int rowLen);

void freeMem(float**& matrix, int colLen);

void freeMem(float*& arr);
