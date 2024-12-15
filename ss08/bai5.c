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

void inOrderTraversal(Node *node){
    if (node != NULL)
    {
        inOrderTraversal(node->left);
        printf("%d ", node->data);
        inOrderTraversal(node->right);
    }
    return;
}

int findData(Node* node, int data) {
    if (node == NULL) {
        return 0; 
    }
    if (node->data == data) {
        return 1; 
    }
    return findData(node->left, data) || findData(node->right, data);
}

int main() {
int n, data, search;
    scanf("%d", &n);
    Node* tree = NULL;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &data);
        tree = insertNode(tree, data);
    }
    printf("duyet theo inorder:\n");
    inOrderTraversal(tree);
    printf("\nsreach = ");
    scanf("%d", &search);
    if (findData(tree, search))
    {
        printf("Gia tri %d co ton tai trong cay\n",search);
    }
    else
    {
        printf("Gia tri %d khong ton tai trong cay\n",search);
    }
    
    return 0;
}