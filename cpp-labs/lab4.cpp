#include <stdio.h>
#include <stdlib.h>
#include "lab4-tools.h"

#define SEQ_LEN 5

int main(int argc, char const *argv[])
{  
    char* str = (char*)malloc(sizeof(char) * 1);
    int strLen;
    readWords(argv[1], str, strLen);

    int swapPos1, swapPos2;
    scanf("%d %d", &swapPos1, &swapPos2);

    FILE* fptr;
    fptr = fopen(argv[2], "rb+");

    fseek(fptr, 0, SEEK_END);
    long fileSize = ftell(fptr);

    if (fileSize < swapPos1 * SEQ_LEN * sizeof(float) || fileSize < swapPos2 * SEQ_LEN * sizeof(float))
    {
        printf("can't swap: bad position");
    }
    else
    {
        printBinFile(fptr);
        swap(fptr, swapPos1, swapPos2);
        printBinFile(fptr);
    }

    fclose(fptr);
    
    return 0;
}
