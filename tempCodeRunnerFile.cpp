#include <stdio.h>
#include <stdlib.h>

struct Element {
    int data;
    struct Element* nextElement;
    struct Element* prevElement;
};

int main() {
    struct Element* item1 = (struct Element*)malloc(sizeof(struct Element));
    struct Element* item2 = (struct Element*)malloc(sizeof(struct Element));
    struct Element* item3 = (struct Element*)malloc(sizeof(struct Element));
    struct Element* item4 = (struct Element*)malloc(sizeof(struct Element));
    struct Element* item5 = (struct Element*)malloc(sizeof(struct Element));
    struct Element* item6 = (struct Element*)malloc(sizeof(struct Element));

    item1->data = 99;
    item2->data = 87;
    item3->data = 43;
    item4->data = 43;
    item5->data = 87;
    item6->data = 99;

    item1->nextElement = item2;
    item1->prevElement = NULL;

    item2->nextElement = item3;
    item2->prevElement = item1;

    item3->nextElement = item4;
    item3->prevElement = item2;

    item4->nextElement = item5;
    item4->prevElement = item3;

    item5->nextElement = item6;
    item5->prevElement = item4;

    item6->nextElement = NULL;
    item6->prevElement = item5;

    struct Element* head = item1;
    struct Element* tail = item1;
    int count = 0;
    int size = 0;

    while (tail->nextElement != NULL) {
        tail = tail->nextElement;
        size++;
    }

    int isEqual = 1;
    while (count <= size) {
        if (head->data != tail->data) {
            isEqual = 0;
            break;
        }
        head = head->nextElement;
        tail = tail->prevElement;
        count++;
        size--;
    }

    if (isEqual)
        printf("Yes, it is a palindrome.\n");
    else
        printf("No it is not\n");

    free(item1);
    free(item2);
    free(item3);
    free(item4);
    free(item5);
    free(item6);

    return 0;
}
