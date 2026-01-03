#include <stdio.h>

#include <stdlib.h>



struct Node {
    int data;

    struct Node* next;
};

struct Stack {

    struct Node* top;
};

void initStack(struct Stack* stack) {

    stack->top = NULL;

}

void push(struct Stack* stack, int val) {

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {


        printf("Memory allocation failed!\n");
        return;
    }
    newNode->data = val;
    newNode->next = stack->top;


    stack->top = newNode;
    printf("%d pushed to stack.\n", val);



}

void pop(struct Stack* stack) {
    if (stack->top == NULL) {
        printf("Stack Underflow! Cannot pop from empty stack.\n");
        return;
    }
    struct Node* temp6 = stack->top;


    printf("%d popped from stack.\n", temp6->data);

    stack->top = stack->top->next;
    free(temp6);
}

int peek(struct Stack* stack) {
    if (stack->top == NULL) {
        printf("Stack is empty.\n");
        return -1;
    }
    return stack->top->data;
}

int isEmpty(struct Stack* stack) {
    return stack->top == NULL;
}

void display(struct Stack* stack) {
    if (stack->top == NULL) {
        printf("Stack is empty.\n");
        return;
    }
    struct Node* temp9 = stack->top;
    printf("Stack elements: ");
    while (temp9 != NULL) {
        printf("%d ", temp9->data);
        temp9 = temp9->next;
    }
    printf("\n");
}

int main() {
    struct Stack stack;
    initStack(&stack);

    push(&stack, 990);
    push(&stack, 64);
    push(&stack, 87);

    display(&stack);

    pop(&stack);
    display(&stack);

    printf("Top element: %d\n", peek(&stack));

    pop(&stack);
    pop(&stack);
    pop(&stack);

    return 0;
}
