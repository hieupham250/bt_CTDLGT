#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

void insertTail(Node** head, int data) {
    Node* newNode = createNode(data);
    if (*head == NULL) {  
        *head = newNode; 
        return;
    }
    Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
}

void printList(Node* head) {
Node* temp = head;
while (temp->next != NULL){
    temp = temp->next;
}
while (temp != NULL)
{
    printf("%d <-> ", temp->data);
    temp = temp->prev;
}
printf("NULL");
}

int main() {
    int n, data;
    Node* head = NULL;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &data);
        insertTail(&head, data);
    }
    printList(head);
    return 0;
}