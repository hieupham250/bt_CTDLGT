#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

int createNode(int data) {
    struct Node* newNode = (Node*)malloc(sizeof(Node));
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
    } else if(data > node->data) {
        node->right = insertNode(node->right, data);
    }
    return node;
}

int findData(Node* node, int data) {
    if (node == NULL)
    {
        return 1;
    }
    if (node ->data == data)
    {
        return 1;
    }
    return findData(node->left, data) || findData(node->right, data);
}

int main() {
    Node* tree = NULL;
    tree = insertNode(tree, 20);
    tree = insertNode(tree, 10);
    tree = insertNode(tree, 30);
    tree = insertNode(tree, 5);
    tree = insertNode(tree, 15);
    tree = insertNode(tree, 25);
    tree = insertNode(tree, 35);

    int search;
    printf("sreach = ");
    scanf("%d", &search);
    if (findData(tree, search))
    {
        printf("FOUND\n");
    } else {
        printf("NOT FOUND\n");
    }
    
    return 0;
}