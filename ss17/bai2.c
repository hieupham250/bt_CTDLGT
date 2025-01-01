#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node* insertNode(Node* root, int data) {
    if(root == NULL) {
        return createNode(data);
    }
    if(data < root->data) {
        root->left = insertNode(root->left, data);
    } else if(data > root->data) {
        root->right = insertNode(root->right, data);
    }
    return root;
}

void preOrderTraversal(Node* root) {
    if(root != NULL) {
        printf("%d ", root->data);
        preOrderTraversal(root->left);
        preOrderTraversal(root->right);
    }
    return;
}

void inOrderTraversal(Node* root) {
    if(root != NULL) {
        inOrderTraversal(root->left);
        printf("%d ", root->data);
        inOrderTraversal(root->right);
    }
    return;
}

void postOrderTraversal(Node* root) {
    if(root != NULL) {
        postOrderTraversal(root->left);
        postOrderTraversal(root->right);
        printf("%d ", root->data);
    }
    return;
}

int main() {
    int n, data;
    scanf("%d", &n);
    Node* tree = NULL;
    for (int i = 0; i < n; i++) {
        scanf("%d", &data);
        tree = insertNode(tree, data);
    }
    printf("duyet tien thu tu: ");
    preOrderTraversal(tree);
    printf("\n");
    printf("duyet trung thu tu: ");
    inOrderTraversal(tree);
    printf("\n");
    printf("duyet hau thu tu: ");
    postOrderTraversal(tree);   
    return 0;
}