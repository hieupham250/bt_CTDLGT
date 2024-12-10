#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAX 100

typedef struct {
    int arr[MAX];
int top;
} Stack;

void inital(Stack* stack) {
    stack->top = -1;
}

int isEmpty(Stack* stack) {
    if(stack->top == -1) {
        return 1;
    }
    return 0;
}

int isFull(Stack* stack) {
     if(stack->top == MAX - 1) {
        return 1;
     }
     return 0;
}

void push(Stack* stack, char value) {
    if (isFull(stack))
    {
        printf("Ngan xep da day, ko the them phan tu\n");
        return;
    } else {
        stack->arr[++(stack->top)] = value;
    }
    
}

char pop(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Ngan xep rong. ko the lay phan tu.\n");
        return '\0';
    }
    return stack->arr[(stack->top)--];
}

int main() {
    char str[100];
    Stack stack;
    inital(&stack);
    fgets(str, MAX, stdin);
    str[strcspn(str, "\n")] = '\0';
    for (int i = 0; i < strlen(str); i++) {
        push(&stack, str[i]);
    }
    while (!isEmpty(&stack)) {
        printf("%c", pop(&stack));
    }
    printf("\n");
    return 0;
}