#define SEQ_LEN 5

#include <stdio.h>

void copyToBin(const char* fileName, const char* binFileName) {
    FILE* fptr1;
    FILE* fptr2;
    float buffer[SEQ_LEN];

    int wasRead;

    fptr1 = fopen(fileName, "r");
    fptr2 = fopen(binFileName, "wb");

    while (!feof(fptr1))
    {
        wasRead = fscanf(fptr1, "%f %f %f %f %f", &buffer[0], &buffer[1], &buffer[2], &buffer[3], &buffer[4]);
        if ( wasRead == 5)
        {
            fwrite(buffer, sizeof(float), SEQ_LEN, fptr2);
        }
        else
        {
            while (fgetc(fptr1) != (int)'\n');
        }
    }

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