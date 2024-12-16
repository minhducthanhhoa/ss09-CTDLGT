#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

#define MAX 100

int graph[MAX][MAX];
int dist[MAX];
bool visited[MAX];

// Ham tim dinh co khoang cach ngan nhat chua duoc tham
int minDistance(int vertices) {
    int min = INT_MAX, minIndex;

    for (int v = 0; v < vertices; v++) {
        if (!visited[v] && dist[v] <= min) {
            min = dist[v];
            minIndex = v;
        }
    }
    return minIndex;
}

// Ham thuat toan Dijkstra
void dijkstra(int vertices, int startVertex) {
    for (int i = 0; i < vertices; i++) {
        dist[i] = INT_MAX;
        visited[i] = false;
    }
    dist[startVertex] = 0;

    for (int count = 0; count < vertices - 1; count++) {
        int u = minDistance(vertices);
        visited[u] = true;

        for (int v = 0; v < vertices; v++) {
            if (!visited[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    // In khoang cach ngan nhat tu dinh nguon
    printf("\nKhoang cach ngan nhat tu dinh %d:\n", startVertex);
    for (int i = 0; i < vertices; i++) {
        printf("Dinh %d: %d\n", i, dist[i]);
    }
}

int main() {
    int vertices, edges, src, dest, weight, startVertex;

    printf("Nhap so dinh: ");
    scanf("%d", &vertices);

    printf("Nhap so canh: ");
    scanf("%d", &edges);

    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            graph[i][j] = 0;
        }
    }

    printf("Nhap cac canh (dinh1 dinh2 trong so):\n");
    for (int i = 0; i < edges; i++) {
        scanf("%d %d %d", &src, &dest, &weight);
        graph[src][dest] = weight;
        graph[dest][src] = weight; 
    }

    printf("Nhap dinh nguon: ");
    scanf("%d", &startVertex);

    dijkstra(vertices, startVertex);

    return 0;
}

