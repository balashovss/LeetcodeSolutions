#include <stdio.h>
#include <stdlib.h>
typedef struct linkedList {
    int value;
    linkedList* next;
}linkedList;
linkedList* list_init(int value) {
    linkedList* tmp = (linkedList*)malloc(sizeof(linkedList));
    tmp->value = value;
    tmp->next = NULL;
    return tmp;
}
void list_add(linkedList* list, int value) {
    list->next = (linkedList*)malloc(sizeof(linkedList));
    list = list->next;
    list->value = value;
    list->next = NULL;
}
void checkingcf(int num1, int num2, int* cf) {
    if (num1 + num2 + *cf > 9) *cf = 1;
    else *cf = 0;
}
linkedList* addTwoNumbers(linkedList* l1, linkedList* l2) {
    int cf = 0;
    checkingcf(l1->value, l2->value, &cf);
    // if (l1 -> value + l2 -> value > 9) {
    //     cf = 1;
    // }
    linkedList* result = list_init((l1->value + l2->value)%10);
    while ((l1->next != NULL) && (l2->next != NULL)) {
        int sum = 0;
        sum = l1->value + l2->value + cf;
        if (sum > 9) cf = 1;
        l1 = l1 -> next;
        l2 = l2 -> next;
        list_add(result,sum);
    }
    if (l1 -> value + l2 -> value > 9) {
        cf = 1;
    }
    list_add(result, (l1 -> value + l2 -> value + cf)%10);
    if (l1->next == NULL) {
        while (l2->next != NULL) {

        }
    }
}