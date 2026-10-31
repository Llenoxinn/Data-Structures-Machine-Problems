# MP 4: Ar(ray) of Light

## Problem

Implement the `array` class, a container holding items similar to a C-style array `A[n]`.

- The elements are integers.
- The capacity is 20 (`MAX`).
- It has a constructor that takes no arguments.

## Operations

Positions start at 0.

| Operation | Description |
| --- | --- |
| `int getItem(int p)` | Returns the item at position `p`. |
| `bool setItem(int x, int p)` | Sets the item at position `p` to `x`. Figure out why it returns a `bool`. |
| `bool insert(int x, int p)` | Inserts `x` at position `p`. Return the appropriate boolean value. |
| `bool append(int x)` | Inserts `x` at the end of the array. |
| `bool insertFront(int x)` | Inserts `x` at the front of the array. |
| `int getSize()` | Returns the size of the array. |
| `void display()` | Displays all elements on one line, separated by spaces. |
| `int remove(int p)` | Removes the item at position `p` and returns the removed item. |

## Class Declaration

```cpp
#include <iostream>
#define MAX 20

using namespace std;

class array {
private:
    int items[MAX], size;
public:
    array();
    int getItem(int);
    bool setItem(int, int);
    bool insert(int, int);
    bool append(int);
    bool insertFront(int);
    int getSize();
    void display();
    int remove(int);
};
```

## Input

The first line is `t`, the number of test cases. Each test case has two sets:

1. **Initial contents:** a number `n`, followed by `n` integers. Insert them into the array in the order they are read.
2. **Command:** a number `c` (1, 2, 3 or 4), followed by its arguments:

| `c` | Operation | Numbers that follow |
| --- | --- | --- |
| 1 | Append | the item to append |
| 2 | Insert at front | the item to insert |
| 3 | Insert at position | the item, then the position |
| 4 | Remove | the position of the item to remove |

## Output

For each test case, display the contents of the array on one line. For `t` test cases, there are `t` lines of output.

## Samples

### Sample 1

**Input**

```
9
10
1 2 3 4 5 6 7 8 9 10
1 -10
20
5 5 5 5 5 5 5 5 5 7 5 5 5 5 5 5 5 5 5 7
2 -7
10
49 49 49 49 49 49 49 49 49 49
3 2 7
10
49 49 49 49 49 49 49 49 49 49
3 2 17
10
10 15 20 25 26 26 45 20 21 10
1 1004
20
1 7 3 8 7 3 5 6 8 1 1 7 3 8 7 3 5 6 8 1
3 12345 10
20
1 7 3 8 7 3 5 6 8 1 1 7 3 8 7 3 5 6 8 1
4 19
20
1 7 3 8 7 3 5 6 8 1 1 7 3 8 7 3 5 6 8 1
4 2
10
1 7 3 8 7 3 5 6 8 1
4 11
```

**Output**

```
1 2 3 4 5 6 7 8 9 10 -10
5 5 5 5 5 5 5 5 5 7 5 5 5 5 5 5 5 5 5 7
49 49 49 49 49 49 49 2 49 49 49
49 49 49 49 49 49 49 49 49 49
10 15 20 25 26 26 45 20 21 10 1004
1 7 3 8 7 3 5 6 8 1 1 7 3 8 7 3 5 6 8 1
1 7 3 8 7 3 5 6 8 1 1 7 3 8 7 3 5 6 8
1 7 8 7 3 5 6 8 1 1 7 3 8 7 3 5 6 8 1
1 7 3 8 7 3 5 6 8 1
```

### Sample 2: Other test cases

**Input**

```
4
19
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19
2 20
19
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19
3 20 10
19
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19
4 19
19
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19
4 -2
```

**Output**

```
20 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19
1 2 3 4 5 6 7 8 9 10 20 11 12 13 14 15 16 17 18 19
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19
```

### Sample 3: Empty arrays

**Input**

```
5
0
1 17
0
2 24
0
3 3 3
0
4 19
0
4 0
```

**Output**

```
17
24



```

The last three lines are blank: they are part of the expected output (the array is empty for the last three test cases). Nothing follows them.
