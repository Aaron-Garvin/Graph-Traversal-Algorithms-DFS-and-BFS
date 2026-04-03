# 🕸️ Graph Traversal Algorithms: BFS & DFS in C

[![C Language](https://img.shields.io/badge/Language-C-blue.svg)](https://en.wikipedia.org/wiki/C_(programming_language))
[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)

A comprehensive implementation and comparative study of the two fundamental graph traversal algorithms: **Breadth-First Search** and **Depth-First Search**, implemented using C and Adjacency Matrices.

---

## 📖 Overview
Graph traversal is the process of visiting every vertex in a graph exactly once. This repository breaks down the two most common methods for traversing non-linear data structures.

### 🔍 [01. Breadth-First Search (BFS)](./01.Breadth_First_Search/)
* **Strategy:** Explore the neighbor nodes first, before moving to the next level neighbors.
* **Analogy:** Like ripples in a pond spreading outward.
* **Core Logic:** Uses a **Queue (FIFO)** data structure.
* **Best For:** Finding the shortest path in unweighted graphs.

### 🌲 [02. Depth-First Search (DFS)](./02.Depth_First_Search/)
* **Strategy:** Explore as far as possible along each branch before backtracking.
* **Analogy:** Like exploring a maze by following one path until you hit a wall.
* **Core Logic:** Uses a **Stack (LIFO)**, typically via recursion.
* **Best For:** Cycle detection, pathfinding, and topological sorting.

---

## 📊 Quick Comparison Report

| Feature | Breadth-First Search (BFS) | Depth-First Search (DFS) |
| :--- | :--- | :--- |
| **Data Structure** | Queue (Manual Array) | Stack (Recursive Call Stack) |
| **Approach** | Level-order (Wide) | Depth-order (Deep) |
| **Time Complexity** | $O(V^2)$ (with Matrix) | $O(V^2)$ (with Matrix) |
| **Space Complexity** | $O(V)$ | $O(V)$ |
| **Shortest Path** | Guaranteed for unweighted | Not guaranteed |

---

## 🧠 Algorithmic Logic

### BFS Process
1. Initialize a queue and a visited array.
2. Enqueue the starting node and mark as visited.
3. While the queue is not empty:
    - Dequeue a node and process it.
    - Enqueue all its unvisited neighbors and mark them visited.

### DFS Process
1. Start at the root node.
2. Mark node as visited and process it.
3. For every unvisited neighbor, recursively call the DFS function.
4. Backtrack when no more unvisited neighbors exist.

---

## 🚀 Getting Started

### Prerequisites
You need a C compiler (like GCC) installed on your system.

### Installation & Execution
1. **Clone the repository:**
   ```bash
   git clone [https://github.com/Aaron-Garvin/Graph-Traversal-Algorithms-DFS-and-BFS.git](https://github.com/Aaron-Garvin/Graph-Traversal-Algorithms-DFS-and-BFS.git)
   cd Graph-Traversal-Algorithms-DFS-and-BFS
   ```
   
2. **Run BFS:**
   ```bash
   gcc "01. Breadth_First_Search/main.c" -o bfs
   ./bfs
   ```
3. **Run DFS:**
   ```bash
   gcc "02. Depth_First_Search/main.c" -o dfs
   ./dfs
   ```
## 📁 Repository Structure:
```text
├── 01. Breadth_First_Search/       # Level-order implementation
│   ├── main.c                      # BFS Source Code
│   └── README.md                   # BFS detailed documentation
├── 02. Depth_First_Search/         # Deep-dive implementation
│   ├── main.c                      # DFS Source Code
│   └── README.md                   # DFS detailed documentation
├── .gitignore                      # Prevents binary/temp files
├── LICENSE                         # MIT License
└── README.md                       # Main Documentation (This file)
```
## 🤝 Contributing
Contributions, issues, and feature requests are welcome! Feel free to check the issues page if you want to contribute.

## 📄 License
Distributed under the MIT License. See LICENSE for more information.

## Developed by Aaron Garvin
