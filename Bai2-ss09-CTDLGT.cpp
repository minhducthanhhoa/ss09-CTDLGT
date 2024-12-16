#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int adjMatrix[MAX][MAX];

void initAdjMatrix(int vertices) {
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            adjMatrix[i][j] = 0;
        }
    }
}

// Them canh vao do thi (ma tran ke)
void addEdgeMatrix(int src, int dest) {
    adjMatrix[src][dest] = 1;
    adjMatrix[dest][src] = 1;
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

// Kiem tra tinh doi xung cua ma tran ke 
int isSymmetric(int vertices) {
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            if (adjMatrix[i][j] != adjMatrix[j][i]) {
                return 0; // Khong doi xung
            }
        }
    }
    return 1; // Doi xung
}

int main() {
    int vertices, edges, src, dest;

    printf("Nhap so dinh: ");
    scanf("%d", &vertices);

    initAdjMatrix(vertices);

    printf("Nhap so canh: ");
    scanf("%d", &edges);

    printf("Nhap cac canh (dinh1 dinh2):\n");
    for (int i = 0; i < edges; i++) {
        scanf("%d %d", &src, &dest);
        addEdgeMatrix(src, dest);
    }

    printf("\nMa tran ke:\n");
    displayAdjMatrix(vertices);

    if (isSymmetric(vertices)) {
        printf("\nMa tran ke la doi xung.\n");
    } else {
        printf("\nMa tran ke khong doi xung.\n");
    }

    return 0;
}

