#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

Node* createNode(int v) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

typedef struct Graph {
    int numVertices;
    int isDirected; // 0: Vo huong, 1: Co huong
    Node* adjLists[MAX];
} Graph;

Graph* createGraph(int vertices, int isDirected) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->numVertices = vertices;
    graph->isDirected = isDirected;

    for (int i = 0; i < vertices; i++) {
        graph->adjLists[i] = NULL;
    }

    return graph;
}

// Them canh vao do thi (danh sach ke)
void addEdgeList(Graph* graph, int src, int dest) {
    Node* newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;

    if (!graph->isDirected) { // Neu do thi vo huong
        newNode = createNode(src);
        newNode->next = graph->adjLists[dest];
        graph->adjLists[dest] = newNode;
    }
}

// Hien thi do thi duoi dang danh sach ke 
void displayAdjList(Graph* graph) {
    for (int i = 0; i < graph->numVertices; i++) {
        printf("%d:", i);
        Node* temp = graph->adjLists[i];
        while (temp) {
            printf(" %d ->", temp->vertex);
            temp = temp->next;
        }
        printf(" NULL\n");
    }
}

int adjMatrix[MAX][MAX];

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

int main() {
    int choice, vertices, edges, src, dest, isDirected;

    printf("Nhap so dinh: ");
    scanf("%d", &vertices);

    printf("Do thi co huong (1) hay vo huong (0)? ");
    scanf("%d", &isDirected);

    Graph* graph = createGraph(vertices, isDirected);

    initAdjMatrix(vertices);

    printf("Nhap so canh: ");
    scanf("%d", &edges);

    printf("Nhap cac canh (dinh1 dinh2):\n");
    for (int i = 0; i < edges; i++) {
        scanf("%d %d", &src, &dest);
        addEdgeList(graph, src, dest);
        addEdgeMatrix(src, dest, isDirected);
    }

    printf("\nDanh sach ke:\n");
    displayAdjList(graph);

    printf("\nMa tran ke:\n");
    displayAdjMatrix(vertices);

    return 0;
}

