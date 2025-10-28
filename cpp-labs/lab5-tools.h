#pragma once

#include <stdio.h>

#define NMAX 10

typedef float (*functional)(float);

void findProduct(float* array, float& prod, bool& isNull, float min, float max, int arrL, functional);

void input(FILE* fptr, float*& arr, int& arrL);

void input(float& num);

void printArray(float *arr, int arrLen, functional);

void freeMem(float*& arr);

