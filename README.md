# Lab Programs - Time Complexity Analysis

This repository contains various algorithmic implementations in C++. Below is the time complexity analysis (Best, Worst, and Average cases) for each program.

## 1. Dijkstra's Algorithm (`dijkstra.cpp`)
Finds the shortest path from a source vertex to all other vertices in a graph.
- **Data Structure:** Adjacency Matrix
- **Best Case:** `O(V^2)`
- **Average Case:** `O(V^2)`
- **Worst Case:** `O(V^2)`
> *Note: Where `V` is the number of vertices. Since an adjacency matrix is used, we have to iterate through all vertices to find the minimum distance and update adjacent vertices.*

## 2. Horspool's String Matching (`horspool.cpp`)
A string matching algorithm that compares characters from right to left.
- **Best Case:** `O(n / m)` - when the pattern mismatch occurs on the last character and the mismatched character is not in the pattern.
- **Average Case:** `O(n)` - for typical texts.
- **Worst Case:** `O(n * m)` - when all characters match except the first one, for every shift.
> *Note: Where `n` is the length of the text and `m` is the length of the pattern.*

## 3. 0/1 Knapsack using DP (`knapsack_dp.cpp`)
Solves the 0/1 Knapsack problem using Dynamic Programming.
- **Best Case:** `O(n * W)`
- **Average Case:** `O(n * W)`
- **Worst Case:** `O(n * W)`
> *Note: Where `n` is the number of items and `W` is the knapsack capacity. The algorithm always fills an `n x W` table.*

## 4. Merge Sort (`mergesort.cpp`)
A divide-and-conquer sorting algorithm.
- **Best Case:** `O(n log n)`
- **Average Case:** `O(n log n)`
- **Worst Case:** `O(n log n)`
> *Note: Merge sort consistently divides the array in half and takes linear time to merge, regardless of the initial order.*

## 5. N-Queens using Branch and Bound (`nqueens_bb.cpp`)
Places N non-attacking queens on an N×N chessboard.
- **Best Case:** `O(1)` - practically bounded by finding the first solution early on if constraints are optimal.
- **Average Case:** `O(N!)` - practically bounded by permutations and significant pruning.
- **Worst Case:** `O(N!)`
> *Note: Branch and bound (tracking columns and diagonals using arrays) significantly reduces the number of recursive calls compared to naive backtracking, but the theoretical upper bound remains `O(N!)`.*

## 6. Sum of Subsets (`sum_of_subsets.cpp`)
Finds all subsets of a given set whose elements sum to a target value using backtracking.
- **Best Case:** `O(n)` - when the target is matched early and bounds prune the rest.
- **Average Case:** `O(2^n)` - as it explores the subset tree.
- **Worst Case:** `O(2^n)`
> *Note: Bounding conditions help prune the state space tree, but in the worst case, it still explores `2^n` possibilities.*

## 7. Topological Sort using DFS (`topological_sort_dfs.cpp`)
Produces a linear ordering of vertices in a Directed Acyclic Graph (DAG).
- **Data Structure:** Adjacency Matrix
- **Best Case:** `O(V^2)`
- **Average Case:** `O(V^2)`
- **Worst Case:** `O(V^2)`
> *Note: The DFS visits all vertices and for each vertex, it iterates over all other vertices in the row to find adjacent edges because of the adjacency matrix representation.*
