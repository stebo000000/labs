#include <stdio.h>
#include <stdlib.h>
bool isCorrectChar(unsigned char chr) {return chr >= '0' && chr <= '9' || chr >= 'a' && chr <= 'z' || chr >= 'A' && chr <= 'Z';}
void readWord(FILE* fptr, char*& str, int& wasRead, unsigned char& chr) {
    str = (char*)malloc(sizeof(char));
    do {chr = fgetc(fptr);} while (!isCorrectChar(chr) && chr != 255);
    while (isCorrectChar(chr) && chr != 255) {
        str[wasRead++] = chr;
        str = (char*)realloc(str, sizeof(char) * wasRead + 1);
        chr = fgetc(fptr);
    }
    return;
}
void readWords(const char* fileName, char**& strs, int*& wordsLens, int& wordsCount) {
    FILE* fptr1 = fopen(fileName, "r");
    unsigned char chr = ' ';
    int wasRead;
    while (chr != 255) {
        while (chr != 255) {
            wasRead = 0;
            readWord(fptr1, strs[wordsCount], wasRead, chr);
            if (wasRead > 0) {
                wordsLens[wordsCount++] = wasRead;
                wordsLens = (int*)realloc(wordsLens, sizeof(int) * wordsCount + 1);
                strs = (char**)realloc(strs, sizeof(char*) * wordsCount + 1);
            }}}
    fclose(fptr1);
    return;
}
void sort(int* wordsLens, int& wordsCount, int* wordIndexes) {
    int buffer;
    for (int i = 0; i < wordsCount - 1; i++) {
        for (int j = i + 1; j < wordsCount; j++) {
            if (wordsLens[i] < wordsLens[j]) {
                buffer = wordsLens[i];
                wordsLens[i] = wordsLens[j];
                wordsLens[j] = buffer;
                buffer = wordIndexes[i];
                wordIndexes[i] = wordIndexes[j];
                wordIndexes[j] = buffer;
            }}}
    return;
}
int main(int argc, char const *argv[]) {  
    char** strs = (char**)malloc(sizeof(char*));
    int* wordsLens = (int*)malloc(sizeof(int));
    int wordsCount = 0;
    readWords(argv[1], strs, wordsLens, wordsCount);
    int* wordIndexes = (int*)malloc(sizeof(int) * wordsCount);
    for (int i = 0; i < wordsCount; i++) wordIndexes[i] = i;
    sort(wordsLens, wordsCount, wordIndexes);
    for (int i = 0; i < wordsCount; i++) {
        for (int j = 0; j < wordsLens[i]; j++) printf("%c", strs[wordIndexes[i]][j]);
        printf("\n");
    }
    for (int i = 0; i < wordsCount; i++) free(strs[i]);
    free(wordIndexes);
    free(wordsLens);
    return 0;
}
