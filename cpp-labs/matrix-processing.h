#pragma once

#include <stdio.h>

#define NMAX 10


void input(float matrix[][NMAX], int& colLen, int& rowLen, FILE* fptr);

float findMean(float matrix[][NMAX], int colLen, int rowLen);

void findProduct(float matrix[][NMAX], int colLen, int rowLen, float results[]);

void printMatrix(float matrix[][NMAX], int colLen, int rowLen);

void print(float arr[], int colLen);

bool isValidToTask(float matrix[][NMAX], int colLen, int rowLen);

void addTask(float matrix[][NMAX], int colLen, int rowLen);