#include <stdio.h>

#define MAX 100
#define INF 1000000

// ham tim dinh co khoang cach nho nhat chua duoc duyet
int minDistance(int dist[], int visited[], int n) {
    int min = INF, min_index = -1;
    for (int i = 0; i < n; i++) {
        if (!visited[i] && dist[i] < min) {
            min = dist[i];
            min_index = i;
        }
    }
    return min_index;
}

// thhuat toan Dijkstra
void dijkstra(int graph[MAX][MAX], int n, int src) {
    int dist[MAX], visited[MAX];

    // khoi tao khoang cach va mang danh dau
    for (int i = 0; i < n; i++) {
        dist[i] = INF;
        visited[i] = 0;
    }
    dist[src] = 0;

    // lap de tim duong di ngan nhat
    for (int count = 0; count < n - 1; count++) {
        int u = minDistance(dist, visited, n);
        if (u == -1) { // neu ko co dinh de duyet
            break;
        }

        visited[u] = 1;

        for (int v = 0; v < n; v++) {
            if (!visited[v] && graph[u][v] && dist[u] != INF && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    printf("\nkhoang cach ngan nhat tu dinh %d:\n", src);
    for (int i = 0; i < n; i++) {
        printf("dinh %d: %d\n", i, dist[i]);
    }
}

int main() {
    int n, e;
    int graph[MAX][MAX] = {0};

    printf("nhap so dinh: ");
    scanf("%d", &n);
    printf("nhap so canh: ");
    scanf("%d", &e);

    printf("nhap cac canh (u v w):\n");
    for (int i = 0; i < e; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        graph[u][v] = w;
        graph[v][u] = w;
    }

    int src;
    printf("nhap dinh nguon: ");
    scanf("%d", &src);

    dijkstra(graph, n, src);

    return 0;
}
