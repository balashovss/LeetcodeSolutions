#include <stdio.h>
#include <stdlib.h>
struct ListNode {
    int val;
    struct ListNode* next;
};
struct ListNode* list_init(int val) {
    struct ListNode* tmp = (struct ListNode*)malloc(sizeof(struct ListNode));
    tmp->val = val;
    tmp->next = NULL;
    return tmp;
}
void list_add(struct ListNode* list, int val) {
    struct ListNode* last = list;
    while (last->next) last = last->next;
    last->next = (struct ListNode*)malloc(sizeof(struct ListNode));
    last = last->next;
    last->val = val;
    last->next = NULL;
}
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    // if (l1 -> val + l2 -> val > 9) {
    //     cf = 1;
    // }
    int cf = (l1->val + l2->val)/10;
    struct ListNode* result = list_init((l1->val + l2->val)%10);
    while ((l1) || (l2)) {
        if (l1) l1 = l1 -> next;
        if (l2) l2 = l2 -> next;
        int sum = cf;
        if (l1) sum+=l1->val;
        if (l2) sum+=l2->val;
        if ((sum != 0) || (l1) || (l2)) list_add(result,sum%10);
        cf = sum/10;   
    }
    return result;
}
void freeList(struct ListNode* list) {
    while (list->next != NULL) {
        struct ListNode* temp = list->next;
        free(list);
        list = temp;
    }
    free(list);
}
int main() {
    int digit;
    char tmp;
    scanf("%d%c", &digit, &tmp);
    struct ListNode* l1 = list_init(digit);
    if (tmp != '\n') {
        while (scanf("%d%c", &digit, &tmp) && tmp != '\n') {
            list_add(l1, digit);
        }
    }
    scanf("%d%c", &digit, &tmp);
    struct ListNode* l2 = list_init(digit);
    if (tmp != '\n') {
        while (scanf("%d%c", &digit, &tmp) && tmp != '\n') {
            list_add(l2, digit);
        }
    }
    struct ListNode* result = addTwoNumbers(l1, l2);
    while (l1->next != NULL) {
        struct ListNode* temp = l1->next;
        free(l1);
        l1 = temp;
    }
    free(l1);
    while (l2->next != NULL) {
        struct ListNode* temp = l2->next;
        free(l2);
        l2 = temp;
    }
    free(l2);
    while (result->next) {
        printf("%d ", result->val);
        struct ListNode* temp = result->next;
        free(result);
        result = temp;
    }
    printf("%d", result->val);
    free(result);
    // freeList(l2);
}