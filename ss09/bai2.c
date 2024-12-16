#include <stdio.h>
#include <stdlib.h>

void addEdge(int matrix[][10], int i, int j) {
    matrix[i][j] = 1;
    matrix[j][i] = 1;
}

void printMatrix(int matrix[][10], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int checkMatrix(int matrix[][10], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] != matrix[j][i]) {
                return 0;
            }
        }
    }
    return 1;
}

int main() {
    int n, e;
    printf("nhap so luong dinh cua do thi: ");
    scanf("%d", &n);
    printf("nhap so luong canh cua do thi: ");
    scanf("%d", &e);
    int matrix[10][10] = {0};
    printf("nhap cac canh (u v):\n");
    for (int i = 0; i < e; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(matrix, u, v);
    }
    printf("\nma tran ke:\n");
    printMatrix(matrix, n);
    if (checkMatrix(matrix, n) == 1) {
        printf("do thi doi xung\n");
    } else {
        printf("do thi ko doi xung\n");
    }

    return 0;
}
