# MP 2: Merging Two Sorted String Arrays

## Overview

`merge.h` and `merge.cpp` provide a standalone library function that combines two lexicographically sorted `std::string` arrays into a single sorted output array while counting string comparisons.

## API

Declared in [merge.h](merge.h) and implemented in [merge.cpp](merge.cpp):

```cpp
int merge(string A[], string B[], string C[], int n, int m);
```

- `A` — First sorted input array of `n` strings.
- `B` — Second sorted input array of `m` strings.
- `C` — Destination buffer sized for at least `n + m` strings.
- **Returns:** Total number of string comparisons executed while both arrays still have unconsumed elements.

When `A[a] == B[b]`, the element from `A` is placed into `C` first (`A[a] <= B[b]`). Any leftover elements after one array is exhausted are copied directly into `C` without additional comparisons. No `main` function is included so the module can be linked against a test harness.

## Usage Example

Compile with a driver file (e.g., `driver.cpp`) that reads `A` and `B` and calls `merge`:

```bash
g++ -std=c++17 merge.cpp driver.cpp -o mp2
./mp2
```

Given `A = ["alpha", "delta", "hotel"]` (`n = 3`) and `B = ["bravo", "echo", "india"]` (`m = 3`):

- Comparisons made: `5` (`"alpha"` vs `"bravo"`, `"delta"` vs `"bravo"`, `"delta"` vs `"echo"`, `"hotel"` vs `"echo"`, `"hotel"` vs `"india"`).
- Resulting `C`: `["alpha", "bravo", "delta", "echo", "hotel", "india"]` (`"india"` is appended without a comparison once `A` is empty).
