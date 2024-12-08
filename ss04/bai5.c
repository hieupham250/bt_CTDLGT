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

void insertAtPosition(Node** head, int value, int position) {
    if (position < 0) {
        printf("Vị trí không hợp lệ!\n");
        return;
    }

    Node* newNode = createNode(value);

    if (position == 0) {
        newNode->next = *head;
        *head = newNode;
        return;
    }

    Node* temp = *head;
    int index = 0;

    while (temp != NULL && index < position - 1) {
        temp = temp->next;
        index++;
    }

    if (temp == NULL) {
        printf("Vị trí vượt quá chiều dài danh sách!\n");
        free(newNode);
        return;
    }

    // Chèn phần tử vào vị trí xác định
    newNode->next = temp->next;
    temp->next = newNode;
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
    int n, value, insertValue, position;
    scanf("%d", &n);
    Node* head = NULL;
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        insertToTail(&head, value);
    }
    printf("gia tri can chen: ");
    scanf("%d", &insertValue);
    printf("vị tri: ");
    scanf("%d", &position);
    insertAtPosition(&head, insertValue, position);
    printList(head);
    freeList(head);

    return 0;
}
