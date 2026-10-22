# Practical 09: Graph Representation and Traversals (BFS and DFS)

## 1. Practical Number
Practical 09

## 2. Practical Title / Aim
Represent a network of buildings and paths as an undirected graph using an Adjacency Matrix in C, and implement Breadth-First Search (BFS) and Depth-First Search (DFS) graph traversal algorithms.

## 3. Objective
- Understand graph representations using sequential Adjacency Matrix data structures.
- Implement Breadth-First Search (BFS) traversal using an auxiliary FIFO queue.
- Implement Depth-First Search (DFS) traversal using recursive backtracking (call stack).
- Compare traversal behaviors, execution orders, and performance complexities of BFS and DFS.

## 4. Algorithm / Logic Used

### A. Graph Representation (Adjacency Matrix)
1. Initialize a $V \times V$ matrix with all zeros.
2. For each edge connecting vertex $u$ and $v$:
   - Set `adjMatrix[u][v] = 1`.
   - Set `adjMatrix[v][u] = 1` (since the graph is undirected).

### B. Breadth-First Search (`BFS`)
1. **Start**
2. Initialize `visited` boolean array to `false` and an empty queue `Q`.
3. Mark `startVertex` as visited and enqueue it into `Q`.
4. While `Q` is not empty:
   1. Dequeue vertex `current` and print it.
   2. For each neighbor from `0` to `V - 1`:
      - If `adjMatrix[current][neighbor] == 1` and `neighbor` is NOT visited:
        - Mark `neighbor` as visited.
        - Enqueue `neighbor` into `Q`.
5. **End**

### C. Depth-First Search (`DFS`)
1. **Start**
2. Mark `current` vertex as visited and print it.
3. For each neighbor from `0` to `V - 1`:
   - If `adjMatrix[current][neighbor] == 1` and `neighbor` is NOT visited:
     - Recursively invoke `DFSRecursive(vertices, adjMatrix, visited, neighbor)`.
4. **End**

## 5. Code Implementation
Source code: [practical-09.c](practical-09.c)

```c
void BFS(int vertices, int adjMatrix[MAX_VERTICES][MAX_VERTICES], int startVertex) {
    bool visited[MAX_VERTICES] = {false};
    int queue[MAX_VERTICES], front = 0, rear = -1;
    visited[startVertex] = true;
    queue[++rear] = startVertex;

    while (front <= rear) {
        int current = queue[front++];
        printf("%d ", current);
        for (int i = 0; i < vertices; i++) {
            if (adjMatrix[current][i] == 1 && !visited[i]) {
                visited[i] = true;
                queue[++rear] = i;
            }
        }
    }
}
```

## 6. Complexity Analysis

| Metric | Adjacency Matrix Representation |
| :--- | :---: |
| **Space Complexity (Storage)** | $\Theta(V^2)$ where $V$ is the number of vertices |
| **BFS Time Complexity** | $O(V^2)$ (scanning row of length $V$ for each vertex) |
| **DFS Time Complexity** | $O(V^2)$ (scanning row of length $V$ for each vertex) |
| **BFS Auxiliary Space** | $O(V)$ for queue and visited array |
| **DFS Auxiliary Space** | $O(V)$ for recursion stack and visited array |

## 7. Input / Output & Test Cases

### Test Case 1: Campus Building Network (4 Buildings, 4 Paths)
**Input:**
```text
Enter number of buildings / locations (Vertices): 4
Enter number of paths / connections (Edges): 4
Path 1 (u v): 0 1
Path 2 (u v): 0 2
Path 3 (u v): 1 2
Path 4 (u v): 2 3
Starting building: 0
```

**Output:**
```text
Adjacency Matrix (4 x 4):
      0  1  2  3
    ------------
 0 |  0  1  1  0
 1 |  1  0  1  0
 2 |  1  1  0  1
 3 |  0  0  1  0

------------------------------------------------------------
BFS Traversal Order: 0 1 2 3 
DFS Traversal Order: 0 1 2 3 
------------------------------------------------------------
```

### Test Case 2: Linear Path Network (3 Buildings)
**Input:**
```text
Vertices: 3, Edges: 2
Paths: (0 1), (1 2)
Start Vertex: 0
```
**Output:**
```text
BFS Traversal Order: 0 1 2 
DFS Traversal Order: 0 1 2 
```

## 8. Conclusion
Successfully modeled a spatial building network using an Adjacency Matrix in C. Implemented level-by-level exploration using Breadth-First Search (Queue) and depth-prioritized exploration using Depth-First Search (Recursion), validating their $O(V^2)$ matrix traversal performance.
