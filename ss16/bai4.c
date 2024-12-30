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

int search(Node* root, int key) {
    if (root == NULL) {
        return 0;
    }

    if (root->data == key) {
        return 1;
    }
    if (key < root->data) {
        return search(root->left, key);
    } else {
        return search(root->right, key);
    }
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
    int key;
    printf("search: ");
    scanf("%d", &key);

    if (search(root, key)) {
        printf("gia trị %d da duoc tim thay trong cay\n", key);
    } else {
        printf("gia trị %d khong ton tai trong cay\n", key);
    }

    return 0;
}
