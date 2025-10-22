#pragma once
#include <stdio.h>

void copyToBin(const char* fileName, const char* binFileName);

void swap(FILE* fptr, int swapPos1, int swapPos2);

void printBinFile(FILE* fptr);

void addTask(FILE* fptr, FILE* fptr2, float min, float max);
