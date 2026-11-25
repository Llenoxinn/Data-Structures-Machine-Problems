# MP 11: Binary Search Tree Lineage & Inorder Neighbor Queries

## Overview

`beMyMasterAncestor.cpp` implements a parent-linked Binary Search Tree (`BST`) supporting insertion, search, proper ancestor/descendant checks, and inorder successor/predecessor lookups.

## Data Structures & Methods

Implemented in [beMyMasterAncestor.cpp](beMyMasterAncestor.cpp):

- **`class node`** — Holds an integer `item` and `left`, `right`, and `parent` pointers.
- **`class BST`** — Maintains the root pointer `r` and provides:
  - `node* search(node *t, int a)` — Iterative BST lookup starting at `t`.
  - `void rinsert(node **t, int x)` — Recursive BST insertion that sets each new node's `parent` pointer.
  - `bool ancestor(int a, int b)` — Returns `true` when `a != b` and `b` lies along a downward BST search path starting from `a`.
  - `bool descendant(int a, int b)` — Delegates to `ancestor(b, a)`.
  - `int successor(int a)` — Finds the minimum key in `a`'s right subtree, or walks up `parent` pointers to the first ancestor reached from a left child; returns `a` if no successor exists.
  - `int predecessor(int a)` — Finds the maximum key in `a`'s left subtree, or walks up `parent` pointers to the first ancestor reached from a right child; returns `a` if no predecessor exists.

## Input / Output Format

1. Read `n`, then insert `n` integers into the BST.
2. Read `a b` and query `ancestor(a, b)`: prints `Laozi` if true, `Mushu` otherwise.
3. Read `a b` and query `descendant(a, b)`: prints `Mulan` if true, `Mushu` otherwise.
4. Read `a b` and print `successor(a)` on one line and `predecessor(b)` on the next, outputting `Li Shang` whenever a query has no result.

## Build & Run

```bash
g++ -std=c++17 beMyMasterAncestor.cpp -o mp11
./mp11
```

### Example

Input:

```text
7
20 10 30 5 15 25 35
20 15
35 30
15 20
```

Output:

```text
Laozi
Mulan
20
15
```
