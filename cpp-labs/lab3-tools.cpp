#define SEQ_LEN 5

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

void readNum(FILE* fptr, char* temp, int& wasRead, unsigned char& chr) {
    bool isNegative = false;
    int stopWasRead = 0;
    
    while (!isdigit(chr) && chr != '-' && chr != 255 && chr != '\n')
    {
        chr = fgetc(fptr);
    }

    if (chr == '-')
    {
        temp[wasRead++] = chr;
        temp = (char*)realloc(temp, sizeof(char) * wasRead + 1);
        isNegative = true;
        chr = fgetc(fptr);

    }
    
    

    while ((isdigit(chr) || chr == '.') && chr != 255 && chr != '\n' && stopWasRead < 2)
    {
        if (chr == '.')
        {
            stopWasRead++;
        }
        
        if (stopWasRead < 2)
        {
            temp[wasRead++] = chr;
            temp = (char*)realloc(temp, sizeof(char) * wasRead + 1);
            chr = fgetc(fptr);
        }
    }
    temp[wasRead] = ' ';
    wasRead = isNegative ? wasRead - 1 : wasRead;
    return;
}

void copyToBin(const char* fileName, const char* binFileName) {
    FILE* fptr1;
    FILE* fptr2;
    float buffer[SEQ_LEN];
    char* temp = (char*)malloc(sizeof(char) * 1);
    unsigned char chr;
    chr = ' ';

    int wasRead, counter;

    fptr1 = fopen(fileName, "r");
    fptr2 = fopen(binFileName, "wb");

    while (chr != 255)
    {
        counter = 0;
        chr = ' ';
        while (chr != '\n' && counter < 5 && chr != 255)
        {
            wasRead = 0;
            chr = ' ';
            readNum(fptr1, temp, wasRead, chr);
            if (wasRead != 0)
            {
                buffer[counter++] = atof(temp);
            }
        }
        if (counter == 5)
        {
            fwrite(buffer, sizeof(float), SEQ_LEN, fptr2);
        }
    }

    free(temp);

    fclose(fptr1);
    fclose(fptr2);
    return;
}

void swap(FILE* fptr, int swapPos1, int swapPos2) {
    float seq1[SEQ_LEN], seq2[SEQ_LEN];

    fseek(fptr, swapPos1 * SEQ_LEN * sizeof(float), SEEK_SET);
    fread(seq1, sizeof(float), SEQ_LEN, fptr);

    fseek(fptr, swapPos2 * SEQ_LEN * sizeof(float), SEEK_SET);
    fread(seq2, sizeof(float), SEQ_LEN, fptr);

    fseek(fptr, swapPos1 * SEQ_LEN * sizeof(float), SEEK_SET);
    fwrite(seq2, sizeof(float), SEQ_LEN, fptr);

    fseek(fptr, swapPos2 * SEQ_LEN * sizeof(float), SEEK_SET);
    fwrite(seq1, sizeof(float), SEQ_LEN, fptr);

    return;
}

void printBinFile(FILE* fptr) {
    fseek(fptr, 0, SEEK_SET);

    float buffer;

    int i = 0;
    while (fread(&buffer, sizeof(float), 1, fptr) != 0)
    {
        if (!(i % 5))
        {
            printf("\n");
        }
        printf("%f ", buffer);
        i++;
    }
    printf("\n");
    return;
    
}