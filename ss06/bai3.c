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
    if(!isEmpty(stack)) {
        printf("ngan xep ko rong\n");
    }
}

int main() {
    int n, value;
    scanf("%d", &n);
    Stack stack;
    inital(&stack);
     if (n > MAX) {
        printf("so luong phan tu vuot qua kich thuoc toi da cua ngan xep (%d).\n", MAX);
        return 1;
    }

    if (n == 0) {
        printf("ngan xep rong\n");
        return 0;
    }
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &value);
        push(&stack, value);
    }
    prinStack(&stack);
    return 0;
}