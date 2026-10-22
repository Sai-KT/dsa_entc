/**
 * Practical 09: Graph Traversals (BFS and DFS) using Adjacency Matrix
 * Student: Pushpak Bagade | Roll No: SEA 13 (SE A)
 * Academic Year: 2026-27
 */

#include <stdio.h>
#include <stdbool.h>

#define MAX_VERTICES 30

/**
 * Breadth-First Search (BFS) using an explicit queue.
 */
void BFS(int vertices, int adjMatrix[MAX_VERTICES][MAX_VERTICES], int startVertex) {
    bool visited[MAX_VERTICES] = {false};
    int queue[MAX_VERTICES];
    int front = 0, rear = -1;

    visited[startVertex] = true;
    queue[++rear] = startVertex;

    printf("BFS Traversal Order: ");

    while (front <= rear) {
        int current = queue[front++];
        printf("%d ", current);

        for (int neighbor = 0; neighbor < vertices; neighbor++) {
            if (adjMatrix[current][neighbor] == 1 && !visited[neighbor]) {
                visited[neighbor] = true;
                queue[++rear] = neighbor;
            }
        }
    }
    printf("\n");
}

/**
 * Depth-First Search (DFS) recursive helper function.
 */
void DFSRecursive(int vertices, int adjMatrix[MAX_VERTICES][MAX_VERTICES], bool visited[], int current) {
    visited[current] = true;
    printf("%d ", current);

    for (int neighbor = 0; neighbor < vertices; neighbor++) {
        if (adjMatrix[current][neighbor] == 1 && !visited[neighbor]) {
            DFSRecursive(vertices, adjMatrix, visited, neighbor);
        }
    }
}

/**
 * Initiates Depth-First Search (DFS) from starting vertex.
 */
void DFS(int vertices, int adjMatrix[MAX_VERTICES][MAX_VERTICES], int startVertex) {
    bool visited[MAX_VERTICES] = {false};
    printf("DFS Traversal Order: ");
    DFSRecursive(vertices, adjMatrix, visited, startVertex);
    printf("\n");
}

/**
 * Prints the Adjacency Matrix.
 */
void displayAdjacencyMatrix(int vertices, int adjMatrix[MAX_VERTICES][MAX_VERTICES]) {
    printf("\nAdjacency Matrix (%d x %d):\n", vertices, vertices);
    printf("    ");
    for (int i = 0; i < vertices; i++) {
        printf("%3d", i);
    }
    printf("\n    ");
    for (int i = 0; i < vertices; i++) {
        printf("---");
    }
    printf("\n");

    for (int i = 0; i < vertices; i++) {
        printf("%2d |", i);
        for (int j = 0; j < vertices; j++) {
            printf("%3d", adjMatrix[i][j]);
        }
        printf("\n");
    }
}

int main(void) {
    int vertices, edges;
    int adjMatrix[MAX_VERTICES][MAX_VERTICES] = {0};

    printf("============================================================\n");
    printf("  PRACTICAL 09: GRAPH REPRESENTATION & TRAVERSALS (BFS/DFS)\n");
    printf("============================================================\n");

    printf("Enter number of buildings / locations (Vertices, max %d): ", MAX_VERTICES);
    if (scanf("%d", &vertices) != 1 || vertices <= 0 || vertices > MAX_VERTICES) {
        printf("Error: Invalid vertex count.\n");
        return 1;
    }

    printf("Enter number of paths / connections (Edges): ");
    if (scanf("%d", &edges) != 1 || edges < 0) {
        printf("Error: Invalid edge count.\n");
        return 1;
    }

    printf("\nEnter path endpoints as (u v) with indices 0 to %d:\n", vertices - 1);
    for (int i = 1; i <= edges; i++) {
        int u, v;
        printf("Path %d (u v): ", i);
        if (scanf("%d %d", &u, &v) == 2) {
            if (u >= 0 && u < vertices && v >= 0 && v < vertices) {
                adjMatrix[u][v] = 1;
                adjMatrix[v][u] = 1; // Undirected graph
            } else {
                printf("Error: Vertex indices out of bounds! Skipping path.\n");
            }
        }
    }

    displayAdjacencyMatrix(vertices, adjMatrix);

    int start;
    printf("\nEnter starting building / vertex (0 to %d): ", vertices - 1);
    if (scanf("%d", &start) == 1 && start >= 0 && start < vertices) {
        printf("\n------------------------------------------------------------\n");
        BFS(vertices, adjMatrix, start);
        DFS(vertices, adjMatrix, start);
        printf("------------------------------------------------------------\n");
    } else {
        printf("Error: Invalid starting vertex.\n");
    }

    return 0;
}
