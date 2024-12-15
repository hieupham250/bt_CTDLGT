#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
} Node;

Node* createNode(int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node* insertNode(Node *node, int data)
{
    if (node == NULL)
    {
        return createNode(data);
    }
    if (data < node->data)
    {
        node->left = insertNode(node->left, data);
    }
    else if (data > node->data)
    {
        node->right = insertNode(node->right, data);
    }
    return node;
}

int isBST(Node* node, int min, int max) {
    if (node == NULL)
    {
        return 1;
    }
    if (node->data <= min || node->data >= max)
    {
       return 0;
    }
    return isBST(node->left, min, max) && isBST(node->right, node->data, max);
}

int main() {
    Node* tree = createNode(10);
    tree->left = createNode(5);
    tree->right = createNode(15);
    tree->left->left = createNode(3);
    tree->left->right = createNode(7);
    tree->right->left = createNode(12);
    tree->right->right = createNode(20);
    if (isBST(tree, -10000, 10000))
    {
        printf("Cay nhi phan tim kiem (BST)\n");
    } else {
        printf("Khong phai cây nhi phan tim kiem (BST)\n");
    }
    return 0;
}