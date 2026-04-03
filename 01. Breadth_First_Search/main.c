// Including the standard input-output library for using printf and scanf functions.
#include <stdio.h>

// Define a constant MAX to represent the maximum number of vertices in the graph.
#define MAX 10

// Declare a 2D array 'graph' to represent the adjacency matrix of the graph.
int graph[MAX][MAX];

// Declare an array 'visited' to keep track of visited vertices during BFS.
int visited[MAX];

// Declare an array 'queue' to implement the queue for BFS.
int queue[MAX];

int n;

// Function to perform Breadth-First Search (BFS) starting from a given vertex 'start'.
void bfs(int start) {
    int front = 0, rear = 0;

    // Enqueue the starting vertex and mark it as visited.
    queue[rear++] = start;
    visited[start] = 1;

    // Loop until the queue is empty.
    while (front < rear) {
        int node = queue[front++];
        printf("%d ", node);

        // Explore all adjacent vertices of the current node.
        for (int i = 0; i < n; i++) {
            if (graph[node][i] == 1 && visited[i] == 0) {
                queue[rear++] = i;
                visited[i] = 1;
            }
        }
    }
}

// The main function to execute the BFS algorithm.
int main() {
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    // Read the adjacency matrix from the user input.
    printf("Enter adjacency matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }
    
    // Initialize the visited array to 0 (indicating that no vertices have been visited).
    for (int i = 0; i < n; i++) {
        visited[i] = 0;
    }

    printf("BFS Traversal: ");
    bfs(0);  // start from vertex 0

    return 0;
}