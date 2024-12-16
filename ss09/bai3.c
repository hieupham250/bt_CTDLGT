#include <stdio.h>

#define MAX_VERTICES 100

// ma tran ke
int graph[MAX_VERTICES][MAX_VERTICES];
int visited[MAX_VERTICES];  // 0: chua tham, 1: da tham
int inStack[MAX_VERTICES];  // 0: ko trong ngan xep, 1: co trong ngan xep

int dfs(int v, int n) {
    visited[v] = 1;
    inStack[v] = 1;

    for (int i = 0; i < n; i++) {
        if (graph[v][i]) { // co canh tu v den i
            if (!visited[i] && dfs(i, n)) {
                return 1; // tìm thay chu ky
            } else if (inStack[i]) {
                return 1; // tim thay chu ky trong qua trinh duyet
            }
        }
    }

    inStack[v] = 0; // quay lai, bo dinh v khoi ngan xep
    return 0;
}

// ham kiem tra do thi co chu ky ko
int hasCycle(int n) {
    for (int i = 0; i < n; i++) {
        visited[i] = 0;
        inStack[i] = 0;
    }
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            if (dfs(i, n)) {
                return 1;
            }
        }
    }
    return 0;
}

int main() {
    int n, e;
    printf("nhap so luong dinh: ");
    scanf("%d", &n);
    printf("nhap so luong canh: ");
    scanf("%d", &e);
    printf("nhap cac canh (u, v)\n");
    for (int i = 0; i < e; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        graph[u-1][v-1] = 1; // cap nhat ma tran ke
        // doi voi do thi co hung bo dong duoi
        // graph[v-1][u-1] = 1; //do thi vo huong
    }

    if (hasCycle(n)) {
        printf("do thi co chu ky\n");
    } else {
        printf("do thi ko co chu ky\n");
    }

    return 0;
}
