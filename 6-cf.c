#include <stdio.h>
#include <stdlib.h>

struct Element {
    int value;
    struct Element* nextElement;
};

struct Element* createElement(int val) {
    struct Element* newElement = (struct Element*)malloc(sizeof(struct Element));
    if (newElement == NULL) {
        printf("failed!\n");
        return NULL;
    }
    newElement->value = val;
    newElement->nextElement = newElement;
    return newElement;
}

void appendElement(struct Element** head, int val) {
    struct Element* newElement = createElement(val);

    if (*head == NULL) {
        *head = newElement;
        return;
    }

    struct Element* current = *head;
    while (current->nextElement != *head) {
        current = current->nextElement;
    }

    current->nextElement = newElement;
    newElement->nextElement = *head;
}

void deleteLastElement(struct Element** head) {
    if (*head == NULL) {
        printf("List is empty, nothing to delete.\n");
        return;
    }

    if ((*head)->nextElement == *head) {
        free(*head);
        *head = NULL;
        return;
    }

    struct Element* current = *head;

    while (current->nextElement->nextElement != *head) {
        current = current->nextElement;
    }

    struct Element* lastElement = current->nextElement;
    current->nextElement = *head;
    free(lastElement);
}

void showList(struct Element* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Element* current = head;
    do {
        printf("%d ", current->value);
        current = current->nextElement;
    } while (current != head);
    printf("\n");
}

int main() {
    struct Element* head = NULL;

    appendElement(&head, 45);
    appendElement(&head, 22);
    appendElement(&head, 698);
    appendElement(&head, 34);

    printf("Original list ");
    showList(head);

    deleteLastElement(&head);

    printf("After deletion ");
    showList(head);

    return 0;
}
