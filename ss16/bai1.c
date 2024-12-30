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

int calculateHeight(struct Node *root)
{
    if (root == NULL)
    {
        return 0;
    }

    int leftHeight = calculateHeight(root->left);
    int rightHeight = calculateHeight(root->right);

    return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}

int main() {
    Node* tree = createNode(1);
    tree->left = createNode(2);
    tree->right = createNode(3);
    tree->left->left = createNode(4);
    tree->left->right = createNode(5);
    tree->right = createNode(6);
    int height = calculateHeight(tree);
    printf("chieu cao cua cay: %d", height);
    return 0;
}