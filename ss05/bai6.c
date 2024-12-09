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

void replaceValue(Node* head, int oldValue, int newValue) {
    Node* temp = head;
    int found = 0;
    while (temp != NULL) {
        if (temp->data == oldValue) {
            temp->data = newValue;
            found = 1;
            break;
        }
        temp = temp->next;
    }
    if (!found) {
        printf("Không tìm thấy phần tử thay thế\n");
    }
}

void printList(Node* head) {
    if (head == NULL) {
        printf("Danh sách rỗng\n");
        return;
    }
    Node* temp = head;
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    int n, data, oldValue, newValue;
    Node* head = NULL;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &data);
        insertTail(&head, data);
    }

    printf("Giá trị cần thay thế: ");
    scanf("%d", &oldValue);
    printf("Giá trị mới: ");
    scanf("%d", &newValue);
    replaceValue(head, oldValue, newValue);
    printList(head);

    return 0;
}
