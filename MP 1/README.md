# MP 1: A[i] == i?

## Problem

Given an array `A` of size `n`, determine whether there is an element `A[i]` equal to its index `i`. The elements of `A` are assumed to be sorted in increasing order.

Produce **two solutions**:

1. A **linear** solution
2. A **sub-linear** solution

Implement them as two separate functions and call them one after another in `main`.

## Requirements

- Do **not** use global variables.
- Print the number of comparisons made (how many times `A[i] == i` was executed) and whether the answer is `YES` or `NO`.
- **No printing inside the functions.** Only `main` may print.

## Input

| Line | Description |
| --- | --- |
| 1 | `t`, the number of test cases |
| Per test case | `n` (where `5 <= n <= 20`), followed by `n` integers |

Declare the array with a capacity of 20.

## Output

For each test case, print **2 lines** (so `2t` lines in total):

1. Linear solution
2. Sub-linear solution

Each line has the form:

```
YES <comparisons>
```
or
```
NO <comparisons>
```

`YES` means some `A[i] == i`; `NO` means there is none.

## Sample

**Input**

```
2
5
0 1 2 3 4
5
1 2 3 4 5
```

**Output**

```
YES 1
YES 1
NO 1
NO 2
```
