#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

typedef struct {
    int priority;
    char data[50];
} Element;

typedef struct {
    Element arr[MAX];
    int size;
} PriorityQueue;

void initializeQueue(PriorityQueue* queue) {
    queue->size = 0;
}

int isEmpty(PriorityQueue* queue) {
    return queue->size == 0;
}

int isFull(PriorityQueue* queue) {
    return queue->size == MAX;
}

void enqueue(PriorityQueue* queue, int priority, const char* data) {
    if (isFull(queue)) {
        printf("hang doi day.\n");
        return;
    }

    int i;
    for (i = queue->size - 1; i >= 0 && queue->arr[i].priority > priority; i--) {
        queue->arr[i + 1] = queue->arr[i];
    }

    queue->arr[i + 1].priority = priority;
    strcpy(queue->arr[i + 1].data, data);
    queue->size++;

    printf("them phan tu (%d, \"%s\"): hang do ko rong\n", priority, data);
}

void dequeue(PriorityQueue* queue) {
    if (isEmpty(queue)) {
        printf("hang doi rong ko the lay phan tu.\n");
        return;
    }

    Element highestPriority = queue->arr[0];

    for (int i = 1; i < queue->size; i++) {
        queue->arr[i - 1] = queue->arr[i];
    }
    queue->size--;

    printf("phan tu uu tien cao nhat: \"%s\" (uu tien %d)\n", highestPriority.data, highestPriority.priority);
    printf("lay ra phan tu: \"%s\"\n", highestPriority.data);
}

int main() {
    PriorityQueue queue;
    initializeQueue(&queue);

    enqueue(&queue, 2, "Task A");
    enqueue(&queue, 1, "Task B");
    enqueue(&queue, 3, "Task C");
    dequeue(&queue);
    dequeue(&queue);
    return 0;
}
