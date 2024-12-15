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

void preOrderTraversal(Node *node)
{
    if (node != NULL)
    {
        printf("%d ", node->data);
        preOrderTraversal(node->left);
        preOrderTraversal(node->right);
    }
    return;
}

void inOrderTraversal(Node *node){
    if (node != NULL)
    {
        inOrderTraversal(node->left);
        printf("%d ", node->data);
        inOrderTraversal(node->right);
    }
    return;
}

void postOrderTraversal(Node* node) {
    if (node != NULL)
    {
        inOrderTraversal(node->left);
        inOrderTraversal(node->right);
        printf("%d ", node->data);
    }
    return;
}

int main() {
    int n, data;
    scanf("%d", &n);
    Node* tree = NULL;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &data);
        tree = insertNode(tree, data);
    }
    printf("duyet tien thu tu\n");
    preOrderTraversal(tree);
    printf("duyet trung thu tu\n");
    inOrderTraversal(tree);
    printf("duyet hau thu tu\n");
    postOrderTraversal(tree);
    return 0;
}