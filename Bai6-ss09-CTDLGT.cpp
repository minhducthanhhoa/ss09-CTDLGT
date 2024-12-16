#include <stdio.h>
#define MAX_VERTICES 100;

void find_highest_degree(int n, int graph[n][n], int is_directed) {
    int degree[n];
    for (int i = 0; i < n; i++) {
        degree[i] = 0;  
    }

    // Tinh toan bac cua tung dinh
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (graph[i][j] == 1) {
                degree[i]++;  
                if (!is_directed) {
                    degree[j]++;  
                }
            }
        }
    }

    // Tim dinh co bac cao nhat
    int max_degree = degree[0];
    int vertex = 0;
    for (int i = 1; i < n; i++) {
        if (degree[i] > max_degree) {
            max_degree = degree[i];
            vertex = i;
        }
    }

    printf("Ðinh co bac cao nhat là: %d\n", vertex);
}

int main() {
    int n, m, is_directed;
    printf("Nhap so luong dinh: ");
    scanf("%d", &n);
    printf("Nhap so luong canh: ");
    scanf("%d", &m);

    printf("Nhap 1 neu do thi co huong, 0 neu do thi vo huong: ");
    scanf("%d", &is_directed);

    int graph[n][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            graph[i][j] = 0;  
        }
    }

    printf("Nhap cac canh (dinh bat dau tu 0):\n");
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        graph[u][v] = 1;
        if (!is_directed) {
            graph[v][u] = 1;  
        }
    }

    find_highest_degree(n, graph, is_directed);
    return 0;
}

