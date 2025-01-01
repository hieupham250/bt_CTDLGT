#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

Node* adjList[MAX];
int visited[MAX];

Node* createNode(int vertex) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = vertex;
    newNode->next = NULL;
    return newNode;
}

void addEdge(int src, int dest) {
    Node* newNode = createNode(dest);
    newNode->next = adjList[src];
    adjList[src] = newNode;
    newNode = createNode(src);
    newNode->next = adjList[dest];
    adjList[dest] = newNode;
}

void DFS(int v) {
    printf("%d ", v);
    visited[v] = 1;

    Node* temp = adjList[v];
    while (temp != NULL) {
        int adjVertex = temp->vertex;
        if (!visited[adjVertex]) {
            DFS(adjVertex);
        }
        temp = temp->next;
    }
}

void BFS(int start) {
    int queue[MAX], front = 0, rear = 0;

    printf("%d ", start);
    visited[start] = 1;
    queue[rear++] = start;

    while (front < rear) {
        int currentVertex = queue[front++];

        Node* temp = adjList[currentVertex];
        while (temp != NULL) {
            int adjVertex = temp->vertex;
            if (!visited[adjVertex]) {
                printf("%d ", adjVertex);
                visited[adjVertex] = 1;
                queue[rear++] = adjVertex;
            }
            temp = temp->next;
        }
    }
}

int main() {
    int vertices, edges, start;
    printf("nhap so dinh: ");
    scanf("%d", &vertices);
    printf("nhap so canh: ");
    scanf("%d", &edges);

    for (int i = 0; i < vertices; i++) {
        adjList[i] = NULL;
    }

    printf("nhap danh sach cac canh:\n");
    for (int i = 0; i < edges; i++) {
        int src, dest;
        scanf("%d %d", &src, &dest);
        addEdge(src, dest);
    }
    printf("nhap dinh bat dau duyet: ");
    scanf("%d", &start);
    printf("duyet DFS: ");
    for (int i = 0; i < vertices; i++) {
        visited[i] = 0;
    }
    DFS(start);
    printf("\n");
    printf("duyet BFS: ");
    for (int i = 0; i < vertices; i++) {
        visited[i] = 0;
    }
    BFS(start);
    printf("\n");

    return 0;
}
