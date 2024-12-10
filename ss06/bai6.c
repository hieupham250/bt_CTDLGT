#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

typedef struct {
    char arr[MAX];
    int top;
} Stack;

void inital(Stack* stack) {
    stack->top = -1;
}

int isEmpty(Stack* stack) {
    return stack->top == -1;
}

int isFull(Stack* stack) {
    return stack->top == MAX - 1;
}

void push(Stack* stack, char value) {
    if (isFull(stack)) {
        printf("Ngan xep da day, ko the them phan tu.\n");
        return;
    }
    stack->arr[++(stack->top)] = value;
}

char pop(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Ngan xep rong. ko the lay phan tu.\n");
        return '\0';
    }
    return stack->arr[(stack->top)--];
}

int isMatchingPair(char open, char close) {
    return (open == '(' && close == ')') ||
           (open == '{' && close == '}') ||
           (open == '[' && close == ']');
}

int checkBrackets(char* expr) {
    Stack stack;
    inital(&stack);

    for (int i = 0; i < strlen(expr); i++) {
        char ch = expr[i];
        if (ch == '(' || ch == '{' || ch == '[') {
            push(&stack, ch);
        } else if (ch == ')' || ch == '}' || ch == ']') {
            if (isEmpty(&stack)) {
                return 0;
            }
            char top = pop(&stack);
            if (!isMatchingPair(top, ch)) {
                return 0;
            }
        }
    }
    return isEmpty(&stack);
}

int main() {
    char expr[MAX];
    fgets(expr, MAX, stdin);
    expr[strcspn(expr, "\n")] = '\0';

    if (checkBrackets(expr)) {
        printf("Bieu thuc hop le\n");
    } else {
        printf("Bieu thuc ko hop le\n");
    }

    return 0;
}
