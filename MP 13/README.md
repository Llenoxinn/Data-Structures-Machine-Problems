# MP 13: Min-Heap Array Validator

## Overview

`minHeapCheck.cpp` verifies whether a 0-indexed integer array stored in a fixed-size buffer (`MAX = 20`) satisfies the binary min-heap order property.

## How It Works

Implemented in [minHeapCheck.cpp](minHeapCheck.cpp):

- **`#define MAX 20`** — Fixed upper bound on the array capacity.
- **`bool isHeap(int A[], int n)`** — Iterates over every internal node index `i` from `0` through `(n / 2) - 1`, computes its left (`2 * i + 1`) and right (`2 * i + 2`) child indices, and checks that `A[i] <= A[left]` and `A[i] <= A[right]` whenever each child is within bounds (`< n`). Returns `false` on the first violation, or `true` if all parent-child pairs hold.

## Input / Output Format

- **Input:** An integer `n` (`1 <= n <= 20`), followed by `n` space-separated integers representing the array elements in level order.
- **Output:** `Yes` if the array satisfies the min-heap invariant, or `No` otherwise.

## Build & Run

```bash
g++ -std=c++17 minHeapCheck.cpp -o mp13
./mp13
```

### Example

Input (valid min-heap):

```text
6
5 10 8 15 20 9
```

Output:

```text
Yes
```

Input (not a min-heap):

```text
6
5 14 8 11 20 9
```

Output:

```text
No
```

## Related Study Material

- **[Topics/Heaps](../Topics/Heaps/README.md)** — Quick reference and index for heap notes and practice problems.
- **[Heap-Heap-Hooray](https://github.com/Llenoxinn/Heap-Heap-Hooray)** — Companion repository with [`heapNotes.md`](https://github.com/Llenoxinn/Heap-Heap-Hooray/blob/main/heapNotes.md), array-based Min-Heap and Heap Sort implementations, and the 34-problem [`heaps-dont-lie`](https://github.com/Llenoxinn/Heap-Heap-Hooray/tree/main/heaps-dont-lie) playbook (see [`01-check-if-array-is-heap.md`](https://github.com/Llenoxinn/Heap-Heap-Hooray/blob/main/heaps-dont-lie/easy/01-check-if-array-is-heap.md) and [`14-check-min-heap-from-level-order.md`](https://github.com/Llenoxinn/Heap-Heap-Hooray/blob/main/heaps-dont-lie/medium/14-check-min-heap-from-level-order.md)).
