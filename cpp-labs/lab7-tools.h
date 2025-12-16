#include <stdio.h>
extern "C" void sort(int *wordsLens, int &wordsCount, char **strs, int i,
                     int j);
extern "C" void readWords(FILE *fptr, char **&strs, int *&wordsLens,
                          int &wordsCount, unsigned char chr = ' ',
                          int wasRead = 0);
extern "C" void printRes(int i, int j, int wordsCount, int *wordsLens,
                         char **strs);

extern "C" void run(const char *filename);
