# Data Structures and Algorithms: Time and Space Complexity Table

## Data Structures

| **Data Structure**      | **Operation**   | **Best Case**      | **Average Case**   | **Worst Case**     | **Space Complexity** |
|--------------------------|-----------------|--------------------|--------------------|--------------------|-----------------------|
| **Array**               | Access          | O(1)               | O(1)               | O(1)               | O(n)                 |
|                          | Search          | O(1) (if sorted)   | O(n)               | O(n)               |                       |
|                          | Insertion       | O(1) (end)         | O(n)               | O(n)               |                       |
|                          | Deletion        | O(1) (end)         | O(n)               | O(n)               |                       |
| **Linked List**          | Access          | O(n)               | O(n)               | O(n)               | O(n)                 |
|                          | Search          | O(n)               | O(n)               | O(n)               |                       |
|                          | Insertion       | O(1)               | O(1)               | O(1)               |                       |
|                          | Deletion        | O(1)               | O(1)               | O(1)               |                       |
| **Doubly Linked List**   | Access          | O(n)               | O(n)               | O(n)               | O(n)                 |
|                          | Search          | O(n)               | O(n)               | O(n)               |                       |
|                          | Insertion       | O(1)               | O(1)               | O(1)               |                       |
|                          | Deletion        | O(1)               | O(1)               | O(1)               |                       |
| **Stack (Array)**        | Push/Pop        | O(1)               | O(1)               | O(1)               | O(n)                 |
|                          | Search          | O(n)               | O(n)               | O(n)               |                       |
| **Queue (Array)**        | Enqueue/Dequeue | O(1)               | O(1)               | O(1)               | O(n)                 |
| **Priority Queue**       | Enqueue         | O(1)               | O(log n)           | O(log n)           | O(n)                 |
|                          | Dequeue         | O(log n)           | O(log n)           | O(log n)           |                       |
| **Hash Table**           | Search          | O(1)               | O(1)               | O(n)               | O(n)                 |
|                          | Insertion       | O(1)               | O(1)               | O(n)               |                       |
|                          | Deletion        | O(1)               | O(1)               | O(n)               |                       |
| **Binary Search Tree**   | Search          | O(log n)           | O(log n)           | O(n)               | O(n)                 |
|                          | Insertion       | O(log n)           | O(log n)           | O(n)               |                       |
|                          | Deletion        | O(log n)           | O(log n)           | O(n)               |                       |
| **AVL Tree**             | Search          | O(log n)           | O(log n)           | O(log n)           | O(n)                 |
|                          | Insertion       | O(log n)           | O(log n)           | O(log n)           |                       |
|                          | Deletion        | O(log n)           | O(log n)           | O(log n)           |                       |
| **Red-Black Tree**       | Search          | O(log n)           | O(log n)           | O(log n)           | O(n)                 |
|                          | Insertion       | O(log n)           | O(log n)           | O(log n)           |                       |
|                          | Deletion        | O(log n)           | O(log n)           | O(log n)           |                       |
| **Heap**                 | Search          | O(n)               | O(n)               | O(n)               | O(n)                 |
|                          | Insert          | O(1)               | O(log n)           | O(log n)           |                       |
|                          | Delete          | O(log n)           | O(log n)           | O(log n)           |                       |
| **Graph (Adj. List)**    | Search          | O(V + E)           | O(V + E)           | O(V + E)           | O(V + E)             |
| **Graph (Adj. Matrix)**  | Search          | O(V^2)             | O(V^2)             | O(V^2)             | O(V^2)               |
| **Trie**                 | Search          | O(k)               | O(k)               | O(k)               | O(n * k)             |
|                          | Insertion       | O(k)               | O(k)               | O(k)               |                       |
|                          | Deletion        | O(k)               | O(k)               | O(k)               |                       |

## Algorithms

| **Algorithm**        | **Operation**   | **Best Case**      | **Average Case**   | **Worst Case**     | **Space Complexity** |
|-----------------------|-----------------|--------------------|--------------------|--------------------|-----------------------|
| **Binary Search**    | Search          | O(1)               | O(log n)           | O(log n)           | O(1)                 |
| **Linear Search**    | Search          | O(1)               | O(n)               | O(n)               | O(1)                 |
| **Merge Sort**       | Sort            | O(n log n)         | O(n log n)         | O(n log n)         | O(n)                 |
| **Quick Sort**       | Sort            | O(n log n)         | O(n log n)         | O(n^2)             | O(log n)             |
| **Heap Sort**        | Sort            | O(n log n)         | O(n log n)         | O(n log n)         | O(1)                 |
| **Bubble Sort**      | Sort            | O(n)               | O(n^2)             | O(n^2)             | O(1)                 |
| **Insertion Sort**   | Sort            | O(n)               | O(n^2)             | O(n^2)             | O(1)                 |
| **Selection Sort**   | Sort            | O(n^2)             | O(n^2)             | O(n^2)             | O(1)                 |
| **Dijkstra’s**      | Shortest Path   | O(V + E log V)      | O(V + E log V)      | O(V^2)             | O(V + E)             |
| **Floyd-Warshall**   | All-Pairs Path  | O(V^3)             | O(V^3)             | O(V^3)             | O(V^2)               |
| **Hashing**          | Search          | O(1)               | O(1)               | O(n)               | O(n)                 |
| **DFS (Graph)**      | Search/Traversal| O(V + E)           | O(V + E)           | O(V + E)           | O(V)                 |
| **BFS (Graph)**      | Search/Traversal| O(V + E)           | O(V + E)           | O(V + E)           | O(V)                 |

### Notes:
- **n**: Number of elements.
- **k**: Length of the key in Trie.
- **V**: Number of vertices in a graph.
- **E**: Number of edges in a graph.
- Space complexities assume adjacency list representation for graphs unless otherwise specified.

This document is a quick reference guide for analyzing different data structures and algorithms.

