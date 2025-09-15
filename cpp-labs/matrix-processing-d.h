#pragma once

#include <stdio.h>


float** input(float** matrix, int& colLen, int& rowLen, FILE* fptr);

float findMean(float **matrix, const int colLen, const int rowLen);

float findProduct(float **matrix, const int colLen, const int rowLen);

void printMatrix(float** matrix, const int colLen, const int rowLen);

void freeMem(float** matrix, const int colLen);