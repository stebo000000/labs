#pragma once

#include <stdio.h>

#define NMAX 10

void findProduct(float* array, float& prod, bool& isNull, float min, float max, int arrL);

void input(FILE* fptr, float*& arr, int& arrL);

void input(float& num);

void printArray(float* arr, int arrLen);

void freeMem(float*& arr);

bool isInRange(float* arr, int arrL, int min, int max);

void sort(float*& arr, int arrL);
