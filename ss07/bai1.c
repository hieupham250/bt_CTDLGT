#include<stdio.h>
#include<stdlib.h>

#define MAX 100

typedef struct {
    int arr[MAX];
    int front;
    int rear;
} Queue;

void initalQueue(Queue* queue) {
    queue->front = -1;
    queue->rear = -1;
}

int isEmpty(Queue* queue) {
    if (queue->front == -1)
    {
        return 1;
    }
    return 0;
}

int isFull(Queue* queue) {
    if (queue->rear == MAX - 1)
    {
        return 1;
    }
    return 0;
}

void enqueue(Queue* queue, int value) {
    if (isFull(queue))
    {
        printf("hang doi day\n");
        return;
    }
    if (isEmpty(queue))
    {
        queue->front = 0;
    }
    queue->rear++;
    queue->arr[queue->rear] = value;
}

void displayQueue(Queue* queue) {
    for(int i = queue->front; i <= queue->rear; i++) {
        printf("%d", queue->arr[i]);
    }
}

int main() {
    int n, value;
    scanf("%d", &n);
    if (n > MAX)
    {
        printf("so phan tu phai nho hon 100\n");
        return 0;
    }
    Queue queue;
    initalQueue(&queue);
    for (int  i = 0; i < n; i++)
    {
        scanf("%d", &value);
        enqueue(&queue, value);
    }
    displayQueue(&queue);
    return 0;
}