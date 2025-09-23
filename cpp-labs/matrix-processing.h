#pragma once

#include <stdio.h>

#define NMAX 10


void input(float matrix[][NMAX], int& colLen, int& rowLen, FILE* fptr);

float findMean(float matrix[][NMAX], int colLen, int rowLen);

float findProduct(float matrix[][NMAX], int colLen, int rowLen);

void printMatrix(float matrix[][NMAX], int colLen, int rowLen);
