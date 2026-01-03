#include <stdio.h>
#include <stdlib.h>

struct Element {
    long long value;
    struct Element *nextElem;
    struct Element *prevElem;
};

void displayReverse(struct Element *lastElem) {
    while(lastElem != NULL) {
        printf("%lld ", lastElem->value);
        lastElem = lastElem->prevElem;
    }
    printf("\n");
}

int main() {
    struct Element *node1 = (struct Element*)malloc(sizeof(struct Element));
    struct Element *node2 = (struct Element*)malloc(sizeof(struct Element));
    struct Element *node3 = (struct Element*)malloc(sizeof(struct Element));
    struct Element *node4 = (struct Element*)malloc(sizeof(struct Element));
    struct Element *node5 = (struct Element*)malloc(sizeof(struct Element));

    node1->value = 80;
    node2->value = 20;
    node3->value = 30;
    node4->value = 60;
    node5->value = 10;

    node1->nextElem = node2;
    node2->nextElem = node3;
    node3->nextElem = node4;
    node4->nextElem = node5;

    node5->prevElem = node4;
    node4->prevElem = node3;
    node3->prevElem = node2;
    node2->prevElem = node1;

    displayReverse(node5);

    free(node1);
    free(node2);
    free(node3);
    free(node4);
    free(node5);

    return 0;
}
