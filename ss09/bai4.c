#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 100

typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

Node* createNode(int vertex) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = vertex;
    newNode->next = NULL;
    return newNode;
}

typedef struct Queue {
    int items[MAX];
    int front;
    int rear;
} Queue;

Queue* createQueue() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->front = -1;
    q->rear = -1;
    return q;
}

bool isEmpty(Queue* q) {
    return q->rear == -1;
}

void enqueue(Queue* q, int value) {
    if (q->rear == MAX - 1) {
        printf("hang doi day\n");
        return;
    }
    if (q->front == -1)
        q->front = 0;
    q->rear++;
    q->items[q->rear] = value;
}

int dequeue(Queue* q) {
    if (isEmpty(q)) {
        printf("hangdoi rong\n");
        return -1;
    }
    int item = q->items[q->front];
    q->front++;
    if (q->front > q->rear) {
        q->front = q->rear = -1;
    }
    return item;
}

void addEdge(Node* adjList[], int src, int dest) {
    Node* newNode = createNode(dest);
    newNode->next = adjList[src];
    adjList[src] = newNode;
    newNode = createNode(src);
    newNode->next = adjList[dest];
    adjList[dest] = newNode;
}

// Hàm duyệt BFS
void bfs(Node* adjList[], int startVertex, int numVertices) {
    bool visited[MAX] = {false};
    Queue* q = createQueue();
    visited[startVertex] = true;
    enqueue(q, startVertex);

    printf("thu tu duyet BFS: ");

    while (!isEmpty(q)) {
        int currentVertex = dequeue(q);
        printf("%d ", currentVertex);
        Node* temp = adjList[currentVertex];
        while (temp) {
            int adjVertex = temp->vertex;
            if (!visited[adjVertex]) {
                visited[adjVertex] = true;
                enqueue(q, adjVertex);
            }
            temp = temp->next;
        }
    }

    printf("\n");
}

int main() {
    int numVertices, numEdges;
    printf("nhap so luong dinh: ");
    scanf("%d", &numVertices);
    printf("nhap so luong canh: ");
    scanf("%d", &numEdges);
    Node* adjList[MAX] = {NULL};
    printf("nhap danh sach cac canh (đinh1 đinh2):\n");
    for (int i = 0; i < numEdges; i++) {
        int src, dest;
        scanf("%d %d", &src, &dest);
        addEdge(adjList, src, dest);
    }
    int startVertex;
    printf("nhap dinh bat dau duyet BFS: ");
    scanf("%d", &startVertex);
    bfs(adjList, startVertex, numVertices);
    return 0;
}
