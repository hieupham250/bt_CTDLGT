#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

void insertToTail(Node** head, int value) {
    Node* newNode = createNode(value);
    if(*head == NULL) {
        *head = newNode;
        return;
    }
    Node* temp = *head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
}

int findMax(Node* head) {
    if (head == NULL) {
        printf("Danh sách trống\n");
        return -1;
    }

    int max = head->data;
    Node* temp = head->next;

    while (temp != NULL) {
        if (temp->data > max) {
            max = temp->data;
        }
        temp = temp->next;
    }

    return max;
}

void printList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void freeList(Node* head) {
    Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    int n, value, max;
    scanf("%d", &n);
    Node* head = NULL;
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        insertToTail(&head, value);
    }
   if (head != NULL) {
        int max = findMax(head);
        printf("%d\n", max);
    } else {
        printf("Danh sách trống\n");
    }
    freeList(head);

    return 0;
}
