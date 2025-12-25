#include "lab12-deque.h"
#include "lab12-list.h"
#include <cstdio>

int main(int argc, char **argv) {
    IntList list;
    FloatList list1;
    Deque<char> deque;
    Deque<char> dequeLitle;
    Deque<char> dequeBig;

    list << argv[1];
    list >> nullptr;

    if (list.isConteinsOdd()) {
        int num;
        printf("num: ");
        scanf("%d", &num);
        list.deleteByCondition(num);
        list >> nullptr;
    } else {
        printf("no odd element\n");
    }

    list1 << argv[1];
    list1 >> nullptr;

    float min, max;
    printf("min max: ");
    scanf("%f %f", &min, &max);
    float listMax = list1.findBiggest();
    if (listMax >= min && listMax <= max) {
        float num;
        printf("num: ");
        scanf("%f", &num);
        list1.deleteByCondition(num);
        list1 >> nullptr;
    } else {
        printf("not in range\n");
    }

    return 0;
}
