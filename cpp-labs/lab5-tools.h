#pragma once

#include <stdio.h>

#define NMAX 10

void findProduct(float* array, float& prod, bool& isNull, float min, float max, int arrL, float (*f)(float));

void input(FILE* fptr, float*& arr, int& arrL);

void input(float& num);

void printArray(float *arr, int arrLen, float (*f)(float));

void freeMem(float*& arr);