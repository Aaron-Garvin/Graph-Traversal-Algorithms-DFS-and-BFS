# 🔍 Depth-First Search (DFS) in C

A clean and simple implementation of the **Depth-First Search (DFS)** graph traversal algorithm in C, using an adjacency matrix and recursion.

---

## 📌 What is DFS?

**Depth-First Search (DFS)** is a graph traversal algorithm that explores as far as possible along each branch before backtracking.

Think of it like exploring a maze 🧩 — you keep moving deeper into one path until you cannot go any further, then you return and try another path.

---

## 📊 Properties

| Property | Value |
|----------|--------|
| Data Structure Used | Stack (Recursion) |
| Time Complexity | O(V + E) |
| Space Complexity | O(V) |
| Graph Representation | Adjacency Matrix |
| Use Cases | Path finding, cycle detection, maze solving, topological sorting |

---

## 🧠 How DFS Works

1. Start from a vertex (usually vertex `0`)
2. Mark it as visited
3. Print or process the vertex
4. Move to the first unvisited neighbour
5. Repeat until there are no more unvisited neighbours
6. Backtrack and continue exploring

---

## 📊 Visual Example

Consider the following graph:

```text
    0
   / \
  1   2
   \ /
    3
```

### Adjacency Matrix

```text
   0  1  2  3
0 [0, 1, 1, 0]
1 [1, 0, 0, 1]
2 [1, 0, 0, 1]
3 [0, 1, 1, 0]
```

### DFS Traversal from Vertex 0

```text
0 → 1 → 3 → 2
```

---

## 🔁 Step-by-Step DFS Traversal

| Step | Current Node | Visited Nodes |
|------|--------------|----------------|
| 1 | 0 | {0} |
| 2 | 1 | {0,1} |
| 3 | 3 | {0,1,3} |
| 4 | 2 | {0,1,2,3} |

✅ Final DFS Traversal:

```text
0 1 3 2
```

---

## 📁 Project Structure

```text
Graph-Traversal-Algorithms-DFS-and-BFS/
├── src/
│   └── dfs.c
├── docs/
│   └── algorithm_notes.md
├── examples/
│   └── sample_input.txt
├── .gitignore
├── LICENSE
└── README.md
```

---

## 🚀 How to Run

### ✅ Prerequisites

You need a C compiler installed, such as GCC.

Check if GCC is installed:

```bash
gcc --version
```

---

### ⚙️ Compile the Program

```bash
gcc src/dfs.c -o dfs
```

---

### ▶️ Run the Program

```bash
./dfs
```

For Windows:

```bash
dfs.exe
```

---

## 🧪 Example Input and Output

### Input

```text
Enter number of vertices: 4
Enter adjacency matrix:
0 1 1 0
1 0 0 1
1 0 0 1
0 1 1 0
```

### Output

```text
DFS Traversal: 0 1 3 2
```

---

## 💻 Full Source Code

```c
#include <stdio.h>

#define MAX 10

// Adjacency matrix to store the graph
int graph[MAX][MAX];

// Array to keep track of visited vertices
int visited[MAX];

// Number of vertices
int n;

// Function to perform DFS
void dfs(int node) {
    printf("%d ", node);
    visited[node] = 1;

    // Visit all adjacent vertices
    for (int i = 0; i < n; i++) {
        if (graph[node][i] == 1 && visited[i] == 0) {
            dfs(i);
        }
    }
}

int main() {
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    // Initialize all vertices as not visited
    for (int i = 0; i < n; i++) {
        visited[i] = 0;
    }

    printf("DFS Traversal: ");
    dfs(0);

    return 0;
}
```

---

## 🔎 Code Explanation

### `graph[MAX][MAX]`

Stores the graph in the form of an adjacency matrix.

Example:

```text
graph[0][1] = 1
```

means there is an edge between vertex `0` and vertex `1`.

---

### `visited[MAX]`

Stores whether a node has already been visited.

| Value | Meaning |
|--------|----------|
| 0 | Not visited |
| 1 | Visited |

---

### `dfs(int node)`

This function:

- Prints the current node
- Marks it as visited
- Recursively visits all connected, unvisited nodes

```c
if (graph[node][i] == 1 && visited[i] == 0)
```

This condition means:

- There is an edge from `node` to `i`
- Node `i` has not been visited yet

Then DFS continues deeper 🔄

---

## ⚠️ Limitations

| Limitation | Description |
|------------|-------------|
| Starts from vertex 0 only | The program always starts DFS from node `0` |
| Maximum 10 vertices | Because of `#define MAX 10` |
| No disconnected graph support | Only connected vertices from `0` are visited |
| Recursive implementation | Large graphs may cause stack overflow |
| Uses adjacency matrix | Less memory efficient for sparse graphs |

---

## 💡 DFS vs BFS

| Feature | DFS | BFS |
|----------|-----|-----|
| Data Structure | Stack / Recursion | Queue |
| Traversal Style | Deep first | Level by level |
| Shortest Path | ❌ Not guaranteed | ✅ Guaranteed in unweighted graphs |
| Memory Usage | Lower | Higher |
| Best Used For | Cycle detection, maze solving | Shortest path, networking |

---

## 🛠️ Possible Improvements

You can improve this project by adding:

- User-chosen starting vertex
- Support for disconnected graphs
- Iterative DFS using a stack
- Graph input using adjacency list
- Better formatting and error handling

---

## 📚 Further Reading

- Breadth-First Search (BFS)
- Recursion in C
- Graph Theory Basics
- Applications of DFS in Real Life

---

## 🤝 Contributing

Contributions are welcome 🎉

1. Fork this repository
2. Create a new branch

```bash
git checkout -b feature/improve-dfs
```

3. Commit your changes

```bash
git commit -m "feat: improve dfs implementation"
```

4. Push to your branch

```bash
git push origin feature/improve-dfs
```

5. Open a Pull Request 🚀

---

## 📄 License

This project is licensed under the MIT License.

See the `LICENSE` file for more details.