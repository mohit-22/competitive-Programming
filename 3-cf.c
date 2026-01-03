#include <stdio.h>
#include <stdlib.h>

struct Node {
    int val;
    struct Node* next;
    struct Node* prev;
};

int main() {
    struct Node* head = (struct Node*)malloc(sizeof(struct Node));
    struct Node* second = (struct Node*)malloc(sizeof(struct Node));
    struct Node* third = (struct Node*)malloc(sizeof(struct Node));
    struct Node* fourth = (struct Node*)malloc(sizeof(struct Node));
    struct Node* fifth = (struct Node*)malloc(sizeof(struct Node));

    head->val = 88;
    second->val = 23;
    third->val = 21;
    fourth->val = 645;
    fifth->val = 56;

    head->next = second;
    head->prev = NULL;

    second->next = third;
    second->prev = head;

    third->next = fourth;
    third->prev = second;

    fourth->next = fifth;
    fourth->prev = third;

    fifth->next = NULL;
    fifth->prev = fourth;

    int min = 100;
    struct Node* hey = head;
    struct Node* kyahaal = NULL;

    while (hey != NULL) {
        if (hey->val < min) {
            min = hey->val;
            kyahaal = hey;
        }
        hey = hey->next;
    }

    struct Node* kaiseho = head;
    if (kyahaal == head) {
        head = kyahaal->next;
    } else {
        while (kaiseho != NULL) {
            if (kaiseho == kyahaal) {
                kyahaal->prev->next = kyahaal->next;
                if (kyahaal->next != NULL) {
                    kyahaal->next->prev = kyahaal->prev;
                }
                break;
            }
            kaiseho = kaiseho->next;
        }
    }

    struct Node* start = head;
    while (start != NULL) {
        printf("%d ", start->val);
        start = start->next;
    }
    printf("\n");

    return 0;
}
