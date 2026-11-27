# Heaps — Study Notes & Practice Hub

Full study notes, C++ implementations, and practice problems for **Heaps** live in the dedicated companion repository:

> **[Llenoxinn/Heap-Heap-Hooray](https://github.com/Llenoxinn/Heap-Heap-Hooray)**

## Direct Links

| Resource | Description | Link |
| --- | --- | --- |
| **Heap Notes** | Complete binary tree rules, min/max-heap properties, priority queue motivation, level-order array layout, and 0-indexed vs. 1-indexed formulas | [`heapNotes.md`](https://github.com/Llenoxinn/Heap-Heap-Hooray/blob/main/heapNotes.md) |
| **1-Indexed Min-Heap** | Starter array-based min-heap (`insert`, `remove`, `display`) | [`Heap-Implementation.cpp`](https://github.com/Llenoxinn/Heap-Heap-Hooray/blob/main/Heap-Implementation.cpp) |
| **Optimized Min-Heap** | Expanded min-heap with `heapifyUp`, `minHeapify`, `getMin`, `extractMin`, `decreaseKey` | [`Heap-Implementation-OPTIMIZED.cpp`](https://github.com/Llenoxinn/Heap-Heap-Hooray/blob/main/Heap-Implementation-OPTIMIZED.cpp) |
| **Heap Sort** | 0-indexed `maxheapify`, `minheapify`, and decreasing heap sort | [`heapSort.cpp`](https://github.com/Llenoxinn/Heap-Heap-Hooray/blob/main/heapSort.cpp) |
| **Heaps Don't Lie Playbook** | 34 Easy, Medium, and Hard DSA/LeetCode heap problems (standard C++ & pure raw-array C++ variants) | [`heaps-dont-lie/`](https://github.com/Llenoxinn/Heap-Heap-Hooray/tree/main/heaps-dont-lie) |

## Quick Reference

### Array Index Math

| Indexing | Root | Parent of `i` | Left Child of `i` | Right Child of `i` |
| --- | :---: | :---: | :---: | :---: |
| **0-indexed** *(used in [MP 13](../../MP%2013/README.md) & `heapSort.cpp`)* | `0` | `(i - 1) / 2` | `2 * i + 1` | `2 * i + 2` |
| **1-indexed** *(used in `Heap-Implementation.cpp`)* | `1` | `i / 2` | `2 * i` | `2 * i + 1` |

### Core Complexities

| Operation | Time |
| --- | --- |
| Peek Min / Max | $O(1)$ |
| Insert / Extract Root / Decrease Key | $O(\log n)$ |
| Build Heap (Floyd's bottom-up `heapify`) | $O(n)$ |
| Heap Sort | $O(n \log n)$ |

## Connections in This Repository

- **[MP 13: Min-Heap Array Validator](../../MP%2013/README.md)** (`minHeapCheck.cpp`) — Directly corresponds to [`heaps-dont-lie/easy/01-check-if-array-is-heap.md`](https://github.com/Llenoxinn/Heap-Heap-Hooray/blob/main/heaps-dont-lie/easy/01-check-if-array-is-heap.md) and [`heaps-dont-lie/medium/14-check-min-heap-from-level-order.md`](https://github.com/Llenoxinn/Heap-Heap-Hooray/blob/main/heaps-dont-lie/medium/14-check-min-heap-from-level-order.md).
- **Next Topic:** [Hashing (`HashbyHash`)](../Hashing/README.md) | **Back to:** [Topics Hub](../README.md) · [Repository Root](../../README.md)
