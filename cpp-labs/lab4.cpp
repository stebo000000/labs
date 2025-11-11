#include <stdio.h>
#include <stdlib.h>
bool isCorrectChar(unsigned char chr) {return chr >= '0' && chr <= '9' || chr >= 'a' && chr <= 'z' || chr >= 'A' && chr <= 'Z';}
void readGarbage(FILE* fptr, char*& str, unsigned char& chr){
    chr = fgetc(fptr);
    if (!isCorrectChar(chr) && chr != 255) readGarbage(fptr, str, chr);
    return;
}
void readLetter(FILE* fptr, char*& str, int& wasRead, unsigned char& chr) {
    if (isCorrectChar(chr) && chr != 255) {
        str[wasRead++] = chr;
        str = (char*)realloc(str, sizeof(char) * wasRead + 1);
        chr = fgetc(fptr);
        readLetter(fptr, str, wasRead, chr);}
    return;
}
void readWord(FILE* fptr, char*& str, int& wasRead, unsigned char& chr) {
    str = (char*)malloc(sizeof(char));
    readGarbage(fptr, str, chr);
    readLetter(fptr, str, wasRead, chr);
    return;
}
void readWords(FILE* fptr, char**& strs, int*& wordsLens, int& wordsCount) {
    unsigned char chr = ' ';
    int wasRead;
    if (chr != 255) {
        wasRead = 0;
        readWord(fptr, strs[wordsCount], wasRead, chr);
        if (wasRead > 0) {
            wordsLens[wordsCount++] = wasRead;
            wordsLens = (int*)realloc(wordsLens, sizeof(int) * wordsCount + 1);
            strs = (char**)realloc(strs, sizeof(char*) * wordsCount + 1);
            readWords(fptr, strs, wordsLens, wordsCount);}}
    return;
}
void sort(int* wordsLens, int& wordsCount, char** strs, int i, int j) {
    int buffer;
    char* buf;
    if (i < wordsCount - 1) {
        if (j < wordsCount) {
            // printf("%d, %d\n", i, j);
            if (wordsLens[i] < wordsLens[j]) {
                buffer = wordsLens[i];
                wordsLens[i] = wordsLens[j];
                wordsLens[j] = buffer;
                buf = strs[i];
                strs[i] = strs[j];
                strs[j] = buf;}
            sort(wordsLens, wordsCount, strs, i, ++j);}
        sort(wordsLens, wordsCount, strs, ++i, i + 1);}
    return;
}
int main(int argc, char const *argv[]) {
    char** strs = (char**)malloc(sizeof(char*));
    int* wordsLens = (int*)malloc(sizeof(int));
    int wordsCount = 0;
    FILE* fptr = fopen(argv[1], "r");
    readWords(fptr, strs, wordsLens, wordsCount);
    fclose(fptr);
    printf("%d\n", wordsCount);
    sort(wordsLens, wordsCount, strs, 0, 1);
    for (int i = 0; i < wordsCount; i++) {
        for (int j = 0; j < wordsLens[i]; j++) printf("%c", strs[i][j]);
        printf("\n");}
    for (int i = 0; i < wordsCount; i++) free(strs[i]);
    free(wordsLens);
    return 0;
}
