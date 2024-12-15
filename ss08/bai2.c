#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void printLevel2(Node* node) {
    int found = 0;
    if (node == NULL) {
        printf("Cay rong.\n");
        return;
    }
    if (node->left != NULL) {
        if (node->left->left != NULL) {
            printf("%d ", node->left->left->data);
            found = 1;
        }
        if (node->left->right != NULL) {
            printf("%d ", node->left->right->data);
            found = 1;
        }
    }
    if (node->right != NULL) {
        if (node->right->left != NULL) {
            printf("%d ", node->right->left->data);
            found = 1;
        }
        if (node->right->right != NULL) {
            printf("%d ", node->right->right->data);
            found = 1;
        }
    }
    if (!found) {
        printf("Khong co dinh nao o lop 2.");
    }
    printf("\n");
}

int main() {
    Node* tree = createNode(1);
    tree->left = createNode(2);
    tree->right = createNode(3);
    tree->left->left = createNode(4);
    tree->left->right = createNode(5);
    tree->right->left = createNode(6);
    tree->right->right = createNode(7);

    printf("Cac dinh o lop 2: ");
    printLevel2(tree);

    return 0;
}
