#include <stdio.h>
#include <stdlib.h>

struct Node {
    long long val;
    struct Node *next;
};

int removeCycle(struct Node *head) {
    if (head == NULL || head->next == NULL) {
        return 0; 
    }
    
    struct Node *slow = head;
    struct Node *fast = head;
    int cycle = 0;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {
            cycle = 1;
            break;
        }
    }

    if (cycle == 0) {
        return 0;
    }

    slow = head;
    struct Node *temp1 = fast;
    while (slow != fast) {
        temp1 = fast;
        slow = slow->next;
        fast = fast->next;
    }
    temp1->next = NULL;

    return 1;
}

void printList(struct Node *head) {
    struct Node *temp = head;
    while (temp != NULL) {
        printf("%lld", temp->val);
        if (temp->next != NULL) {
            printf("->");
        }
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    struct Node *a = (struct Node*)malloc(sizeof(struct Node));
    struct Node *b = (struct Node*)malloc(sizeof(struct Node));
    struct Node *c = (struct Node*)malloc(sizeof(struct Node));
    struct Node *d = (struct Node*)malloc(sizeof(struct Node));
    struct Node *e = (struct Node*)malloc(sizeof(struct Node));

    a->val = 80;
    b->val = 20;
    c->val = 30;
    d->val = 60;
    e->val = 10;

    a->next = b;
    b->next = c;
    c->next = d;
    d->next = b;

    if (removeCycle(a)) {
        printf("Cycle is detected and removed.\n");
    } else {
        printf("No cycle detected.\n");
    }

    struct Node *temp = a;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = e;

    printList(a);

    free(a);
    free(b);
    free(c);
    free(d);
    free(e);

    return 0;
}
