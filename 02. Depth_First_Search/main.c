// Include the standard input-output library
#include <stdio.h>

// Define a constant MAX to represent the maximum number of vertices in the graph
#define MAX 10

// Declare a 2D array 'graph' to represent the adjacency matrix of the graph
int graph[MAX][MAX];   
int visited[MAX];
int n;  // number of vertices

// Function to perform Depth-First Search (DFS) starting from a given vertex 'node'
void dfs(int node) {
    printf("%d ", node);
    visited[node] = 1;

    // Explore all adjacent vertices of the current node
    for (int i = 0; i < n; i++) {
        // If there is an edge from 'node' to 'i' and 'i' has not been visited, recursively call dfs on 'i'
        if (graph[node][i] == 1 && visited[i] == 0) {
            dfs(i);
        }
    }
}

// The main function to execute the DFS algorithm
int main() {
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    // Read the adjacency matrix from the user input
    printf("Enter adjacency matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    // Initialize the visited array to 0 (indicating that no vertices have been visited)
    for (int i = 0; i < n; i++) {
        visited[i] = 0;
    }

    printf("DFS Traversal: ");
    dfs(0);  // start from vertex 0

    return 0;
}