#include "lab7-tools.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]) {
    char **strs = (char **)malloc(sizeof(char *));
    int *wordsLens = (int *)malloc(sizeof(int));
    int wordsCount = 0;
    FILE *fptr = fopen(argv[1], "r");
    readWords(fptr, strs, wordsLens, wordsCount);
    fclose(fptr);
    sort(wordsLens, wordsCount, strs, 0, 1);
    printRes(0, 0, wordsCount, wordsLens, strs);
    free(strs);
    free(wordsLens);
    return 0;
}
