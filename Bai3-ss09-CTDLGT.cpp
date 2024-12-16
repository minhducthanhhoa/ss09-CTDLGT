#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 100

int adjMatrix[MAX][MAX];
int visited[MAX];
int recStack[MAX];

void initAdjMatrix(int vertices) {
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            adjMatrix[i][j] = 0;
        }
    }
}

// Them canh vao do thi (ma tran ke)
void addEdgeMatrix(int src, int dest, int isDirected) {
    adjMatrix[src][dest] = 1;
    if (!isDirected) {
        adjMatrix[dest][src] = 1;
    }
}

// Hien thi do thi duoi dang ma tran ke 
void displayAdjMatrix(int vertices) {
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            printf("%d ", adjMatrix[i][j]);
        }
        printf("\n");
    }
}

// Ham kiem tra chu ki cho do thi co huong su dung DFS
bool isCyclicDirectedDFS(int v, int vertices) {
    if (!visited[v]) {
        visited[v] = 1;
        recStack[v] = 1;

        for (int i = 0; i < vertices; i++) {
            if (adjMatrix[v][i]) { 
                if (!visited[i] && isCyclicDirectedDFS(i, vertices)) {
                    return true;
                } else if (recStack[i]) {
                    return true;
                }
            }
        }
    }

    recStack[v] = 0; 
    return false;
}

// Ham kiem tra chu ki cho do thi vo huong su dung DFS
bool isCyclicUndirectedDFS(int v, int parent, int vertices) {
    visited[v] = 1;

    for (int i = 0; i < vertices; i++) {
        if (adjMatrix[v][i]) {
            if (!visited[i]) {
                if (isCyclicUndirectedDFS(i, v, vertices)) {
                    return true;
                }
            } else if (i != parent) {
                return true;
            }
        }
    }

    return false;
}

int main() {
    int vertices, edges, src, dest, isDirected;

    printf("Nhap so dinh: ");
    scanf("%d", &vertices);

    printf("Do thi co huong (1) hay vo huong (0)? ");
    scanf("%d", &isDirected);

    initAdjMatrix(vertices);

    printf("Nhap so canh: ");
    scanf("%d", &edges);

    printf("Nhap cac canh (dinh1 dinh2):\n");
    for (int i = 0; i < edges; i++) {
        scanf("%d %d", &src, &dest);
        addEdgeMatrix(src, dest, isDirected);
    }

    printf("\nMa tran ke:\n");
    displayAdjMatrix(vertices);

    // Kh?i t?o visited và recStack
    for (int i = 0; i < vertices; i++) {
        visited[i] = 0;
        recStack[i] = 0;
    }

    bool hasCycle = false;
    if (isDirected) {
        for (int i = 0; i < vertices; i++) {
            if (!visited[i] && isCyclicDirectedDFS(i, vertices)) {
                hasCycle = true;
                break;
            }
        }
    } else {
        for (int i = 0; i < vertices; i++) {
            if (!visited[i] && isCyclicUndirectedDFS(i, -1, vertices)) {
                hasCycle = true;
                break;
            }
        }
    }

    if (hasCycle) {
        printf("\nDo thi co chu ky.\n");
    } else {
        printf("\nDo thi khong co chu ky.\n");
    }

    return 0;
}

