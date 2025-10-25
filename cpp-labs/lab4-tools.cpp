#define SEQ_LEN 5

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

bool isCorrectChar(unsigned char& chr) {
    return chr >= '0' && chr <= '9' || chr >= 'a' && chr <= 'z' || chr >= 'A' && chr <= 'Z';
}

void readWord(FILE* fptr, char* str, int& wasRead, unsigned char& chr) {
    do
    {
        chr = fgetc(fptr);
    } while (!isCorrectChar(chr) && chr != 255);
    

    while (isCorrectChar(chr) && chr != 255)
    {
        str[wasRead++] = chr;
        str = (char*)realloc(str, sizeof(char) * wasRead + 1);
        chr = fgetc(fptr);
    }

    str[wasRead++] = ' ';
    str = (char*)realloc(str, sizeof(char) * wasRead + 1);
    return;
}

void readWords(const char* fileName, char* str, int& wasRead) {
    FILE* fptr1;
    unsigned char chr;
    chr = ' ';

    int wasRead;

    fptr1 = fopen(fileName, "r");

    while (chr != 255)
    {
        while (chr != 255)
        {
            wasRead = 0;
            readWord(fptr1, str, wasRead, chr);
        }
    }

    fclose(fptr1);
    return;
}

void getWordsLen(char* str, int strLen, int*& letterCounts) {
    int counter = 0;
    int i = 0;

    while (counter < strLen)
    {
        if (str[i++] == ' ')
        {
            letterCounts[counter++] = i;
            i = 0;
        }
        
    }
    
    return;
}

void getWordsIndexes(int strLen, int*& wordIndexes) {
    for (int i = 0; i < strLen; i++)
    {
        wordIndexes[i] = i;
    }
    return;
}

void sort(char* str, int strLen) {
    int* letterCounts = new int[strLen];
    int* wordIndexes = new int[strLen];
    int buffer;

    getWordsLen(str, strLen, letterCounts);
    getWordsIndexes(strLen, wordIndexes);

    for (int i = 0; i < strLen - 1; i++)
    {
        for (int j = i + 1; j < strLen; j++)
        {
            if (letterCounts[i] < letterCounts[j])
            {
                buffer = letterCounts[i];
                letterCounts[i] = letterCounts[j];
                letterCounts[j] = buffer;

                buffer = wordIndexes[i];
                wordIndexes[i] = wordIndexes[j];
                wordIndexes[j] = buffer;
            }
        }

        
    }
    


    delete[] letterCounts;
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