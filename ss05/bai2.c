#include <stdio.h>
#include <stdlib.h>

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

void insertAtPosition(Node** head, int data, int position) {
    if (position < 0) {
        printf("Vị trí không hợp lệ!\n");
        return;
    }
    
    Node* newNode = createNode(data);
    
    if (position == 0) {
        newNode->next = *head;
        if (*head != NULL) {
            (*head)->prev = newNode;
        }
        *head = newNode;
        return;
    }

    Node* temp = *head;
    int index = 0;
    while (temp != NULL && index < position) {
        temp = temp->next;
        index++;
    }
    
    if (temp == NULL && index < position) {
        printf("Lỗi vị trí không hợp lệ\n");
        free(newNode);
        return;
    }
    
    if (temp != NULL) {
        newNode->next = temp;
        newNode->prev = temp->prev;
        if (temp->prev != NULL) {
            temp->prev->next = newNode;
        }
        temp->prev = newNode;
    }
}

void printList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    int n, data, pos;
    Node* head = NULL;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &data);
        insertTail(&head, data);
    }
    
    printf("Giá trị cần chèn: ");
    scanf("%d", &data);
    printf("Vị trí cần chèn: ");
    scanf("%d", &pos);
    insertAtPosition(&head, data, pos);
    printf("Danh sách sau khi chèn: ");
    printList(head);
    
    return 0;
}
