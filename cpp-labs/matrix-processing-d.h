#pragma once

#include <stdio.h>


float** input(FILE* fptr, int& colLen, int& rowLen);

float findMean(float **matrix, int& colLen, int& rowLen);

float findProduct(float **matrix, int& colLen, int& rowLen);

void printMatrix(float** matrix, int& colLen, int& rowLen);

void freeMem(float** matrix, int& colLen, int& rowLen);