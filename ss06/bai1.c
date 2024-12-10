#include<stdio.h>
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

void push(Stack* stack, int value) {
    if (isFull(stack))
    {
        printf("Ngan xep da day, ko the them phan tu\n");
        return;
    } else {
        stack->arr[++(stack->top)] = value;
    }
    
}

void prinStack(Stack* stack) {
    for (int i = stack->top; i >= 0; i--)
    {
        printf("%d\n", stack->arr[i]);
    }
    
}

int main() {
    int n, value;
    scanf("%d", &n);
    Stack stack;
    inital(&stack);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &value);
        push(&stack, value);
    }
    prinStack(&stack);
    return 0;
}