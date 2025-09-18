#pragma once

#define NMAX 10

void findProduct(float array[NMAX], float& prod, bool& isNull, float min, float max, int arrL);

void input(FILE* fptr, float arr[NMAX], int& arrL);

void input(float& num);