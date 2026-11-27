# Hashing & Hash Tables — Study Notes & Practice Hub

Full study notes, C++ implementations, and practice problems for **Hashing & Hash Tables** live in the dedicated companion repository:

> **[Llenoxinn/HashbyHash](https://github.com/Llenoxinn/HashbyHash)**

## Direct Links

| Resource | Description | Link |
| --- | --- | --- |
| **Hashing Notes** | Direct-index $O(1)$ motivation, modulo hashing, collisions & Birthday Paradox, Linear Probing (Closed Hashing), and Separate Chaining (Open Hashing) | [`hashnotes.md`](https://github.com/Llenoxinn/HashbyHash/blob/main/hashnotes.md) |
| **BST-Chained HashTable** | Fixed-bucket (`MAX = 11`) open-hashing table in C++ storing a Binary Search Tree in each bucket (`insert`, `search`, `remove`, `display`) | [`hash.cpp`](https://github.com/Llenoxinn/HashbyHash/blob/main/hash.cpp) |
| **Hashuh Playbook** | 11 Easy, Medium, and Hard DSA/LeetCode hashing problems across 7 patterns (custom C++ & pure raw-array C++ variants) | [`hashuh/`](https://github.com/Llenoxinn/HashbyHash/tree/main/hashuh) |

## Quick Reference

### Collision Resolution Strategies

| Strategy | Mechanism | Notes |
| --- | --- | --- |
| **Linear Probing (Closed Hashing)** | Probe sequential slots `(idx + step) % M` with wrap-around until an empty slot is found | Requires empty/tombstone states (`EMPTY`, `OCCUPIED`, `DELETED` or sentinel `inf`) so searches stop accurately |
| **Separate Chaining (Open Hashing)** | Store a secondary structure (linked list or BST) at each array bucket | Handles negative keys safely via `((x % M) + M) % M`; `hash.cpp` uses a BST per bucket |

### Core Complexities

| Operation | Average | Worst Case |
| --- | :---: | :---: |
| Search / Insert / Delete | $O(1)$ | $O(n)$ *(all keys collide into one bucket/chain; $O(\log n)$ with balanced trees)* |

## Connections in This Repository

- **[MP 11: Binary Search Tree](../../MP%2011/README.md)** (`beMyMasterAncestor.cpp`) — Core BST operations (`search`, `insert`, `remove`) directly carry over into the per-bucket BST chaining used in [`HashbyHash/hash.cpp`](https://github.com/Llenoxinn/HashbyHash/blob/main/hash.cpp).
- **Previous Topic:** [Heaps (`Heap-Heap-Hooray`)](../Heaps/README.md) | **Back to:** [Topics Hub](../README.md) · [Repository Root](../../README.md)
