# 🔍 Breadth-First Search (BFS) in C

> A clean implementation of the BFS graph traversal algorithm in C, using an adjacency matrix and a manual queue array.

---

## 📌 What is BFS?

**Breadth-First Search (BFS)** is a graph traversal algorithm that visits all vertices of a graph **level by level** — starting from a source vertex and exploring all its neighbours before moving deeper.

Think of it like ripples spreading outward in a pond — the closest nodes are visited first, then the next layer, and so on.

| Property | Value |
|---|---|
| **Data Structure Used** | Queue (FIFO) |
| **Time Complexity** | O(V + E) where V = vertices, E = edges |
| **Space Complexity** | O(V) |
| **Graph Representation** | Adjacency Matrix |
| **Use Cases** | Shortest path, level-order traversal, connected components |

---

## 🧠 How BFS Works (Concept)

```
1. Start at a given vertex (e.g., vertex 0)
2. Enqueue it and mark it as visited
3. While queue is NOT empty:
   a. Dequeue the front node
   b. Print / process it
   c. For every neighbour of this node:
      - If not visited → enqueue it + mark visited
4. Repeat until queue is empty
```

### Visual Example

Given this graph (4 vertices):

```
    0
   / \
  1   2
   \ /
    3
```

Adjacency matrix:
```
   0  1  2  3
0 [0, 1, 1, 0]
1 [1, 0, 0, 1]
2 [1, 0, 0, 1]
3 [0, 1, 1, 0]
```

BFS from vertex **0** → visits: `0 → 1 → 2 → 3`

### Queue State Step-by-Step

| Step | Action | Queue (front→rear) | Visited |
|---|---|---|---|
| Init | Enqueue 0, mark visited | [0] | {0} |
| Step 1 | Dequeue 0, print 0, enqueue 1, 2 | [1, 2] | {0, 1, 2} |
| Step 2 | Dequeue 1, print 1, enqueue 3 | [2, 3] | {0, 1, 2, 3} |
| Step 3 | Dequeue 2, print 2 (3 already visited) | [3] | {0, 1, 2, 3} |
| Step 4 | Dequeue 3, print 3, queue empty → done | [] | {0, 1, 2, 3} |

**Final output:** `BFS Traversal: 0 1 2 3`

---

## 📁 Project Structure

```
GRAPH-TRAVERSAL-ALGORITHMS-DFS-AND-BFS/
├── 01. Breadth_First_Search/
│   ├── main.c          ←  Main BFS code
│   └── README.md       ← BFS-specific README 
│
├── 02. Depth_First_Search/     
│   ├── main.c                  ← Main DFS code
│   └── README.md               ← BFS-specific README 
│
├── .gitignore
├── LICENSE
└── README.md           ← root README (project overview only)
```

---

## 🚀 How to Run

### Prerequisites
- A C compiler — GCC recommended (`gcc --version` to check)

### Compile
```bash
gcc src/bfs.c -o bfs
```

### Run
```bash
./bfs
```

### Example Input & Output
```
Enter number of vertices: 4
Enter adjacency matrix:
0 1 1 0
1 0 0 1
1 0 0 1
0 1 1 0

BFS Traversal: 0 1 2 3
```

---

## 🔎 Code Walkthrough

### Global Variables

```c
#define MAX 10          // Maximum vertices supported
int graph[MAX][MAX];    // Adjacency matrix — graph[i][j] = 1 means edge between i and j
int visited[MAX];       // Tracks which vertices have been seen (0 = not visited, 1 = visited)
int queue[MAX];         // Manual queue array (no stdlib used)
int n;                  // Actual number of vertices entered by user
```

**Why a global queue?**  
In C, there is no built-in queue. This implementation uses a simple integer array with two pointers — `front` and `rear` — to simulate queue behaviour.

---

### The `bfs()` Function

```c
void bfs(int start) {
    int front = 0, rear = 0;

    queue[rear++] = start;   // Enqueue starting vertex
    visited[start] = 1;      // Mark it visited immediately

    while (front < rear) {            // Queue is not empty
        int node = queue[front++];    // Dequeue from front
        printf("%d ", node);          // Process (print) the node

        for (int i = 0; i < n; i++) {
            // Check every possible neighbour
            if (graph[node][i] == 1 && visited[i] == 0) {
                queue[rear++] = i;   // Enqueue unvisited neighbour
                visited[i] = 1;      // Mark visited NOW to avoid duplicates
            }
        }
    }
}
```

**Key insight — mark visited when enqueuing, not when dequeuing.**  
If you mark visited only when printing, the same node can get enqueued multiple times by different neighbours before it is processed. Marking at enqueue time prevents this.

---

### The `main()` Function

```c
int main() {
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    // Read adjacency matrix row by row
    printf("Enter adjacency matrix:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &graph[i][j]);

    // Reset visited array to all 0s
    for (int i = 0; i < n; i++)
        visited[i] = 0;

    printf("BFS Traversal: ");
    bfs(0);   // Always starts from vertex 0

    return 0;
}
```

**Note:** This implementation always starts BFS from vertex 0. To support a user-chosen start vertex, replace `bfs(0)` with `bfs(start_vertex)` and add a `scanf` for it.

---

## ⚠️ Limitations of This Implementation

| Limitation | Explanation |
|---|---|
| Fixed start at vertex 0 | `bfs(0)` is hardcoded — modify to accept input |
| Max 10 vertices | `#define MAX 10` — increase for larger graphs |
| No disconnected graph support | BFS only visits vertices reachable from vertex 0 |
| No overflow check on queue | `rear` could exceed `MAX` on dense graphs |
| Undirected assumption | Matrix is symmetric — works for undirected graphs |

---

## 💡 BFS vs DFS — Quick Comparison

| Feature | BFS | DFS |
|---|---|---|
| Data structure | Queue (FIFO) | Stack (LIFO) or Recursion |
| Traversal order | Level by level | Depth first (goes as deep as possible) |
| Shortest path | ✅ Finds shortest path in unweighted graphs | ❌ Does not guarantee shortest path |
| Memory usage | Higher (stores whole level) | Lower (only current path) |
| Good for | Shortest path, peer networks, web crawlers | Maze solving, topological sort, cycle detection |

---

## 📚 Further Reading

- [BFS — GeeksForGeeks](https://www.geeksforgeeks.org/breadth-first-search-or-bfs-for-a-graph/)
- [Graph Theory Basics — Khan Academy](https://www.khanacademy.org/computing/computer-science/algorithms)
- [Visualise BFS interactively — VisuAlgo](https://visualgo.net/en/bfs)

---

## 🤝 Contributing

1. Fork this repository
2. Create a feature branch: `git checkout -b feature/improve-bfs`
3. Commit your changes: `git commit -m "feat: add disconnected graph support"`
4. Push your branch: `git push origin feature/improve-bfs`
5. Open a Pull Request

---

## 📄 License

This project is licensed under the MIT License — see the [LICENSE](LICENSE) file for details.