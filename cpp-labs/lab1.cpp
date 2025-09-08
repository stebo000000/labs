#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include "addfuncs.h"

using namespace std;

int main() {
    float* arr1 = inputArray();
    float* arr2 = inputArray();
    float* arr3 = inputArray();

    float min = inputNum();
    float max = inputNum();

    float minsArr[3];

    minsArr[0] = findProduct(arr1, min, max);
    minsArr[1] = findProduct(arr1, min, max);
    minsArr[2] = findProduct(arr1, min, max);

    printf("min product in %d array", compare(minsArr));

    return 0;
}