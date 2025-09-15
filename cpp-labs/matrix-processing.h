#pragma once

#include <stdio.h>

#define NMAX 10


void input(float matrix[NMAX][NMAX], int& colLen, int& rowLen, FILE* fptr);

float findMean(float matrix[NMAX][NMAX], const int colLen, const int rowLen);

float findProduct(float matrix[NMAX][NMAX], const int colLen, const int rowLen);

void printMatrix(float matrix[NMAX][NMAX], const int colLen, const int rowLen);
