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

int findIndex(Node** head, int value) {
    Node* temp = *head;
    int index = 0;
    while (temp != NULL) {
        if (temp->data == value) {
            return index;
        }
        temp = temp->next;
        index++;
    }
    return -1;
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
    int n, value, searchValue;
    scanf("%d", &n);
    if (n <= 0) {
        printf("Danh sách trống\n");
        return 1;
    }
    Node* head = NULL;
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        insertToTail(&head, value);
    }
    printf("search=");
    scanf("%d", &searchValue);
    int result = findIndex(&head, searchValue);
    printf("%d\n", result);
    freeList(head);

    return 0;
}
