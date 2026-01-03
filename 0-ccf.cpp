#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int val;
    struct Node *next;
}Node;

typedef struct stack{
    Node *head;
    int size;
}stack;

void init(stack *st){
    st->head = NULL;
    st->size = 0;
}

void push(stack *st,int val){
    Node *temp = (Node *)malloc(sizeof(Node));
    temp->next = st->head;
    st->head = temp;
    st->size++;
}

void pop(stack *st){
    Node *temp = st->head;
    st->head = st->head->next;
    free(temp);
    st->size--;
}

int top(stack *st){
    return st->head->val;
}

void print(Node *temp){
    if(temp==NULL) return;
    print(temp->next);
    printf("%d",temp->val);

}

void display(stack *st){
    print(st->head);
}



int main(){
    stack st;
    init(&st);
}