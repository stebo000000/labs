#include <stdio.h>
#include <stdlib.h>
bool isCorrectChar(unsigned char chr) {return chr >= '0' && chr <= '9' || chr >= 'a' && chr <= 'z' || chr >= 'A' && chr <= 'Z';}
void readGarbage(FILE* fptr, char*& str, unsigned char& chr) {
    chr = fgetc(fptr);
    if (!isCorrectChar(chr) && chr != 255) readGarbage(fptr, str, chr);
    return;}
void readLetter(FILE* fptr, char*& str, int& wasRead, unsigned char& chr) {
    if (isCorrectChar(chr) && chr != 255) {
        str[wasRead++] = chr;
        str = (char*)realloc(str, sizeof(char) * wasRead + 1);
        chr = fgetc(fptr);
        readLetter(fptr, str, wasRead, chr);}
    return;}
void readWord(FILE* fptr, char*& str, int& wasRead, unsigned char& chr) {
    str = (char*)malloc(sizeof(char));
    readGarbage(fptr, str, chr);
    readLetter(fptr, str, wasRead, chr);
    return;}
void readWords(FILE* fptr, char**& strs, int*& wordsLens, int& wordsCount, unsigned char chr = ' ') {
    if (chr != 255) {
        int wasRead = 0;
        readWord(fptr, strs[wordsCount], wasRead, chr);
        if (wasRead > 0) {
            wordsLens[wordsCount++] = wasRead;
            wordsLens = (int*)realloc(wordsLens, sizeof(int) * wordsCount + 1);
            strs = (char**)realloc(strs, sizeof(char*) * wordsCount + 1);
            readWords(fptr, strs, wordsLens, wordsCount);}}
    return;}
void sort(int* wordsLens, int& wordsCount, char** strs, int i, int j) {
    if (i < wordsCount - 1) {
        if (j < wordsCount) {
            if (wordsLens[i] < wordsLens[j]) {
                int buffer = wordsLens[i];
                wordsLens[i] = wordsLens[j];
                wordsLens[j] = buffer;
                char* buf = strs[i];
                strs[i] = strs[j];
                strs[j] = buf;}
            sort(wordsLens, wordsCount, strs, i, ++j);}
        sort(wordsLens, wordsCount, strs, ++i, i + 1);}
    return;}
void printRes(int i, int j, int wordsCount, int* wordsLens, char** strs) {
    if (i < wordsCount) {
        if (j < wordsLens[i]) {
            printf("%c", strs[i][j]);
            printRes(i, j++, wordsCount, wordsLens, strs);}
        printf("\n");
        printRes(i++, 0, wordsCount, wordsLens, strs);
        free(strs[i]);}
    return;}
int main(int argc, char const *argv[]) {
    char** strs = (char**)malloc(sizeof(char*));
    int* wordsLens = (int*)malloc(sizeof(int));
    int wordsCount = 0;
    FILE* fptr = fopen(argv[1], "r");
    readWords(fptr, strs, wordsLens, wordsCount);
    fclose(fptr);
    sort(wordsLens, wordsCount, strs, 0, 1);
    printRes(0, 0, wordsCount, wordsLens, strs);
    free(wordsLens);
    return 0;}
