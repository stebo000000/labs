#include "lab12-deque.h"
#include "lab12-list.h"
#include <cstdio>

int main(int argc, char **argv) {
    IntList list;
    FloatList list1;
    CharDeque deque;
    CharDeque dequeLitle;
    CharDeque dequeBig;
    IntDeque deque1;
    IntDeque dequeLitle1;
    IntDeque dequeBig1;

    printf("\ndeque of char: \n");
    deque << argv[2];
    deque >> nullptr;
    CharDeque d = deque.sort(deque);
    d >> nullptr;

    printf("\ndeque of int: \n");
    deque1 << argv[1];
    deque1 >> nullptr;
    IntDeque d1 = deque1.sort(deque1);
    d1 >> nullptr;
    

    // char temp;
    // while (!deque.is_empty()) {
    //     temp = deque.pop_back();
    //     if ('A' <= temp && 'Z' >= temp) {
    //         dequeBig.add_front(temp);
    //     } else {
    //         dequeLitle.add_back(temp);
    //     }
    // }
    // dequeBig >> nullptr;
    // dequeLitle >> nullptr;
    //
    // deque1 << argv[1];
    //
    // int num1;
    // printf("num1: ");
    // scanf("%d", &num1);
    // int temp1;
    // while (!deque1.is_empty()) {
    //     temp1 = deque1.pop_back();
    //     if (temp1 % num1 == 0) {
    //         dequeBig1.add_front(temp1);
    //     } else {
    //         dequeLitle1.add_back(temp1);
    //     }
    // }
    // dequeBig1 >> nullptr;
    // dequeLitle1 >> nullptr;
    //
    printf("\nlist of int: \n");
    list << argv[1];
    list >> nullptr;
    
    list.sort(list.head);
    list >> nullptr;
    
    printf("\nlist of float: \n");
    list1 << argv[1];
    list1 >> nullptr;
    list1.sort(list1.head);
    list1 >> nullptr;

    // if (list.isConteinsOdd()) {
    //     int num;
    //     printf("num: ");
    //     scanf("%d", &num);
    //     list.deleteByCondition(num);
    //     list >> nullptr;
    // } else {
    //     printf("no odd element\n");
    // }
    //
    // list1 << argv[1];
    // list1 >> nullptr;
    //
    // float min, max;
    // printf("min max: ");
    // scanf("%f %f", &min, &max);
    // float listMax = list1.findBiggest();
    // if (listMax >= min && listMax <= max) {
    //     float num;
    //     printf("num: ");
    //     scanf("%f", &num);
    //     list1.deleteByCondition(num);
    //     list1 >> nullptr;
    // } else {
    //     printf("not in range\n");
    // }

    return 0;
}
