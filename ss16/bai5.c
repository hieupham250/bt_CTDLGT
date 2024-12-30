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

Node* insert(Node* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }
    if (data < root->data) {
        root->left = insert(root->left, data);
    } else if (data > root->data) {
        root->right = insert(root->right, data);
    }
    return root;
}

int findMax(Node* root) {
    if (root == NULL) {
        return -1;
    }
    int leftMax = findMax(root->left);
    int rightMax = findMax(root->right);

    int max = root->data;
    if (leftMax > max) {
        max = leftMax;
    }
    if (rightMax > max) {
        max = rightMax;
    }
    return max;
}

int main() {
    Node* root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 70);
    insert(root, 20);
    insert(root, 40);
    insert(root, 60);
    insert(root, 80);

    int maxValue = findMax(root);
    if (maxValue != -1) {
        printf("gia tri lon nhat trong cay: %d\n", maxValue);
    }

    return 0;
}
