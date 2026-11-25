# MP 4: Fixed-Capacity Integer Array List

## Overview

`arrayOfLight.h` and `arrayOfLight.cpp` implement a static-capacity (`MAX = 20`) integer list class named `array` together with a command-driven `main()` harness for testing insertions and deletions.

## Class Interface

Declared in [arrayOfLight.h](arrayOfLight.h) and implemented in [arrayOfLight.cpp](arrayOfLight.cpp):

| Method | Behavior |
| --- | --- |
| `array()` | Initializes an empty list (`size = 0`). |
| `int getItem(int p)` | Returns the element at zero-based index `p`, or `-1` if `p` is out of range. |
| `bool setItem(int x, int p)` | Overwrites index `p` with `x`; returns `false` if `p` is invalid. |
| `bool insert(int x, int p)` | Shifts elements right and inserts `x` at index `p`; returns `false` when full or out of bounds (`p < 0` or `p > size`). |
| `bool append(int x)` | Appends `x` at the end if `size < MAX`. |
| `bool insertFront(int x)` | Shifts elements right and inserts `x` at index `0` if `size < MAX`. |
| `int getSize()` | Returns the current number of stored elements. |
| `void display()` | Prints all elements separated by spaces followed by a newline. |
| `int rem(int p)` | Removes and returns the element at index `p` (shifting trailing items left), or returns `-1` if `p` is invalid. |

## Test Driver Format

`main()` reads `t` test cases. Each case specifies:

1. An initial count `n` followed by `n` integers (added via `append`).
2. An operation code `c` and its operands:
   - `1 x` — `append(x)`
   - `2 x` — `insertFront(x)`
   - `3 x p` — `insert(x, p)`
   - `4 p` — `rem(p)`

After executing the operation, `display()` prints the resulting list on its own line.

## Build & Run

```bash
g++ -std=c++17 arrayOfLight.cpp -o mp4
./mp4
```

### Example

Input:

```text
3
4
10 20 30 40
1 50
4
10 20 30 40
3 99 2
3
5 6 7
4 1
```

Output:

```text
10 20 30 40 50 
10 20 99 30 40 
5 7 
```
