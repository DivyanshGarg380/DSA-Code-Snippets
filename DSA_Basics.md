# 🧱 Data Structures — Complete Overview

> This document summarizes all major data structures, their purpose, common operations, and time complexities :)

---

## 📘 Table of Contents
1. [Introduction](#introduction)
2. [Arrays](#arrays)
3. [Linked List](#linked-list)
4. [Stack](#stack)
5. [Queue](#queue)
6. [Hash Table](#hash-table)
7. [Trees](#trees)
8. [Heap / Priority Queue](#heap--priority-queue)
9. [Graph](#graph)
10. [Trie](#trie)
11. [Summary Table](#summary-table)
12. [References](#references)

---

## 🏁 Introduction

A **Data Structure** is a way to organize and store data efficiently so that it can be accessed and modified quickly.

Each data structure offers trade-offs between **time complexity**, **space complexity**, and **ease of use** depending on the application.

---

## 📦 Arrays

- **Definition:** Collection of elements stored in contiguous memory.
- **Indexed access:** Directly access any element using index.
- **Applications:** Searching, sorting, matrices.

| Operation | Average | Worst |
|-----------|---------|-------|
| Access    | O(1)    | O(1)  |
| Search    | O(n)    | O(n)  |
| Insertion | O(n)    | O(n)  |
| Deletion  | O(n)    | O(n)  |

---

## 🔗 Linked List

- **Definition:** Linear collection of nodes connected by pointers.
- **Types:** Singly, Doubly, Circular.
- **Applications:** Dynamic memory allocation, queues, stacks.

| Operation | Average | Worst |
|-----------|---------|-------|
| Access    | O(n)    | O(n)  |
| Search    | O(n)    | O(n)  |
| Insertion | O(1)    | O(1)  |
| Deletion  | O(1)    | O(1)  |

---

## 🧮 Stack

- **Definition:** LIFO (Last In, First Out) data structure.
- **Applications:** Function calls, undo operations, expression evaluation.

| Operation | Average | Worst |
|-----------|---------|-------|
| Push      | O(1)    | O(1)  |
| Pop       | O(1)    | O(1)  |
| Peek      | O(1)    | O(1)  |
| Search    | O(n)    | O(n)  |

---

## 🧾 Queue

- **Definition:** FIFO (First In, First Out) data structure.
- **Types:** Simple, Circular, Deque, Priority Queue.
- **Applications:** Scheduling, buffering, BFS.

| Operation   | Average | Worst |
|-------------|---------|-------|
| Enqueue     | O(1)    | O(1)  |
| Dequeue     | O(1)    | O(1)  |
| Front/Rear  | O(1)    | O(1)  |
| Search      | O(n)    | O(n)  |

---

## 🔑 Hash Table

- **Definition:** Stores key-value pairs using hash functions.
- **Applications:** Caching, frequency counting, lookups.

| Operation | Average | Worst |
|-----------|---------|-------|
| Insert    | O(1)    | O(n)  |
| Delete    | O(1)    | O(n)  |
| Search    | O(1)    | O(n)  |

**Note:** Worst case occurs when many keys hash to the same index (collisions).

---

## 🌳 Trees

- **Definition:** Hierarchical structure of nodes.
- **Special Forms:** Binary Tree, Binary Search Tree (BST), AVL Tree, Segment Tree.
- **Applications:** Hierarchies, searching, indexing.

| Operation | Average   | Worst |
|-----------|-----------|-------|
| Search    | O(log n)  | O(n)  |
| Insert    | O(log n)  | O(n)  |
| Delete    | O(log n)  | O(n)  |
| Traversal | O(n)      | O(n)  |

### Common Traversals

- **Inorder:** Left → Root → Right
- **Preorder:** Root → Left → Right
- **Postorder:** Left → Right → Root

---

## ⛰ Heap / Priority Queue

- **Definition:** Complete binary tree that satisfies heap property.
- **Types:** Min-Heap (smallest at root), Max-Heap (largest at root).
- **Applications:** Scheduling, Dijkstra's algorithm, Top K elements.

| Operation    | Average   | Worst     |
|--------------|-----------|-----------|
| Insert       | O(log n)  | O(log n)  |
| Get Min/Max  | O(1)      | O(1)      |
| Delete       | O(log n)  | O(log n)  |

---

## 🌐 Graph

- **Definition:** Set of vertices connected by edges.
- **Representations:** Adjacency list, Adjacency matrix.
- **Types:** Directed, Undirected, Weighted, Unweighted.

| Operation    | Adjacency List | Adjacency Matrix |
|--------------|----------------|------------------|
| Add Edge     | O(1)           | O(1)             |
| Remove Edge  | O(V)           | O(1)             |
| Search Edge  | O(V)           | O(1)             |
| Space        | O(V + E)       | O(V²)            |

### Common Algorithms

- **BFS / DFS** — O(V + E)
- **Dijkstra's Algorithm** — O(E log V)
- **Kruskal's / Prim's MST** — O(E log V)
- **Topological Sort** — O(V + E)

---

## 🔤 Trie

- **Definition:** Tree-like data structure for storing strings by prefixes.
- **Applications:** Autocomplete, dictionary search, prefix matching.

| Operation | Average | Worst |
|-----------|---------|-------|
| Insert    | O(L)    | O(L)  |
| Search    | O(L)    | O(L)  |
| Delete    | O(L)    | O(L)  |

**Note:** L = length of the string/key.

---

## 📊 Summary Table

| Data Structure | Access    | Search    | Insert    | Delete    | Space     | Typical Use           |
|----------------|-----------|-----------|-----------|-----------|-----------|----------------------|
| Array          | O(1)      | O(n)      | O(n)      | O(n)      | O(n)      | Indexing, lookup     |
| Linked List    | O(n)      | O(n)      | O(1)      | O(1)      | O(n)      | Dynamic memory       |
| Stack          | O(n)      | O(n)      | O(1)      | O(1)      | O(n)      | Function calls, undo |
| Queue          | O(n)      | O(n)      | O(1)      | O(1)      | O(n)      | Scheduling, BFS      |
| Hash Table     | -         | O(1)      | O(1)      | O(1)      | O(n)      | Fast lookup          |
| Tree (BST)     | O(log n)  | O(log n)  | O(log n)  | O(log n)  | O(n)      | Searching, indexing  |
| Heap           | O(n)      | O(log n)  | O(log n)  | O(log n)  | O(n)      | Priority tasks       |
| Graph          | -         | O(V + E)  | O(1)      | O(1)      | O(V + E)  | Networks, routes     |
| Trie           | O(L)      | O(L)      | O(L)      | O(L)      | O(AL)     | String search        |

---

## 📚 References

- [GeeksForGeeks - Data Structures](https://www.geeksforgeeks.org/data-structures/)
- [CP-Algorithms](https://cp-algorithms.com/)
- [LeetCode Explore - DSA Topics](https://leetcode.com/explore/)
- [Big-O Cheat Sheet](https://www.bigocheatsheet.com/)

---

## 🧠 Tip

Understanding time and space complexities is more valuable than memorizing them — always reason about why a structure has a certain complexity.

---

⭐ If you found this helpful, give it a star on GitHub and share it!
