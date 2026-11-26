# MP 12: Self-Balancing AVL Tree

## Overview

`avlTree.cpp` implements a parent-linked self-balancing Binary Search Tree (AVL tree) in C++ supporting sequential integer insertion with rotation-based rebalancing and iterative lookup that reports the number of node comparisons performed.

## Data Structures & Methods

Implemented in [avlTree.cpp](avlTree.cpp):

- **`class node`** — Stores an integer key (`item`), subtree `height`, `balance` sign (`-1`, `0`, or `1`), child-side marker (`child`: `-1` for left, `1` for right), and `left`, `right`, and `parent` pointers.
- **`class avl`** — Maintains the `root` pointer and provides:
  - `void insert(int x)` — Inserts `x` using standard BST placement, links the new node to its parent, and traverses back up to the root recomputing heights and balance signs. Whenever `|height(left) - height(right)| > 1`, rebalances the subtree via single (`leftrotate`, `rightrotate`) or double (right-left, left-right) rotations.
  - `int search(int x)` — Walks down from `root` while counting each node inspected, prints the comparison count, and returns `1` if `x` is found or `0` otherwise.
  - `void leftrotate(node *n)` / `void rightrotate(node *n)` — Rewires parent and child pointers around `n` and updates the heights of the rotated nodes.
  - `int height(node *n)` — Returns `-1` for `NULL` pointers and `n->height` otherwise.

## Input / Output Format

- **Input:** An integer `n`, followed by `n` integers to insert into the AVL tree in order, followed by a single target integer to search for.
- **Output:** A single line with the count of nodes checked during the search, followed by a space and either `FOUND` or `!FOUND`.

## Build & Run

```bash
g++ -std=c++17 avlTree.cpp -o mp12
./mp12
```

### Example

Input (key present):

```text
7
10 20 30 40 50 25 35
25
```

Output:

```text
3 FOUND
```

Input (key absent):

```text
7
10 20 30 40 50 25 35
15
```

Output:

```text
3 !FOUND
```
