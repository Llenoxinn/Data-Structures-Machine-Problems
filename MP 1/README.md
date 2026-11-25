# MP 1: Fixed-Point Search in a Sorted Array

## Overview

`amIReallyI.cpp` determines whether a sorted integer array `A` of length `n` (`n <= 20`) contains at least one index `i` where `A[i] == i`, and reports how many element comparisons each search method performs.

## Implementation

Both search functions live in [amIReallyI.cpp](amIReallyI.cpp) and communicate results to `main` via reference parameters (`bool &foundYah`, `int &count`):

- `void linear(int A[], int n, bool &foundYah, int &count)` — Scans from index `0` onward, stopping as soon as a match is found or `A[i] > i` (early termination on strictly increasing values).
- `void subLinear(int A[], int n, bool &foundYah, int &count)` — Performs binary search across `[0, n - 1]`, adjusting `left` or `right` based on whether `A[middle] < middle` or `A[middle] > middle`.

No global variables are used; only `main` handles input and output.

## Input / Output Format

- **Input:** An integer `t` (number of test cases), followed by `t` pairs of an integer `n` (`n <= 20`) and `n` sorted integers.
- **Output:** Two lines per test case (`linear` first, then `subLinear`), each formatted as `YES <comparisons>` or `NO <comparisons>`.

## Build & Run

```bash
g++ -std=c++17 amIReallyI.cpp -o mp1
./mp1
```

### Example

Input:

```text
2
6
-3 -1 1 3 7 9
5
2 4 6 8 10
```

Output:

```text
YES 4
YES 3
NO 1
NO 2
```
