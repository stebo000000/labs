#include <stdio.h>
#include <stdlib.h>

bool isCorrectChar(unsigned char chr) {
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
    //! probably wasRead--;
    return;
}

void readWords(const char* fileName, char** strs, int* wordsLens, int& wordsCount) {
    FILE* fptr1;
    unsigned char chr = ' ';
    int wasRead;
    wordsLens = (int*)malloc(sizeof(int));

    fptr1 = fopen(fileName, "r");

    while (chr != 255)
    {
        while (chr != 255)
        {
            wasRead = 0;
            readWord(fptr1, strs[wordsCount++], wasRead, chr);
            wordsLens = (int*)realloc(wordsLens, sizeof(int) * wordsCount + 1);

        }
    }
    //! probably wordsCount--;

    fclose(fptr1);
    return;
}


void getWordsIndexes(int strLen, int* wordIndexes) {
    for (int i = 0; i < strLen; i++)
    {
        wordIndexes[i] = i;
    }
    return;
}

void sort(int* wordsLens, int& wordsCount, int* wordIndexes) {
    int buffer;

    for (int i = 0; i < wordsCount - 1; i++)
    {
        for (int j = i + 1; j < wordsCount; j++)
        {
            if (wordsLens[i] < wordsLens[j])
            {
                buffer = wordsLens[i];
                wordsLens[i] = wordsLens[j];
                wordsLens[j] = buffer;

                buffer = wordIndexes[i];
                wordIndexes[i] = wordIndexes[j];
                wordIndexes[j] = buffer;
            }
        }
    }
    
    return;
}

void printByRule(char** strs, int* wordsLens, int& wordsCount, int* wordIndexes) {
    for (int i = 0; i < wordsCount; i++)
    {
        for (int j = 0; j < wordsLens[i]; j++)
        {
            printf("%c", strs[i][j]);
        }
        printf("\n");
    }
    return;
}