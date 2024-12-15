#include<stdio.h>
#include<stdlib.h>

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

Node* insertNode(Node* node, int data) {
    if (node == NULL)
    {
        return createNode(data);
    }
    if (data < node->data)
    {
        node->left = insertNode(node->left, data);
    } else if (data > node->data)
    {
        node->right = insertNode(node->right, data);
    }
    return node;
}

int preOrder(Node* node) {
    if (node == NULL)
    {
        return 0;
    }
    int leftHeight = preOrder(node->left);
    int rightHeight = preOrder(node->right);
    return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}

int main() {
    Node* tree = createNode(1);
    tree->left = createNode(2);
    tree->right = createNode(3);
    tree->left->left = createNode(4);
    tree->left->right = createNode(5);
    tree->right->left = createNode(6); 
    printf("chieu cao cua cay: %d", preOrder(tree));
    return 0;
}