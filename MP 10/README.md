# MP 10: Infix Expression Tree Evaluator

## Overview

`suchsymbols.cpp` parses parentless arithmetic infix expressions into a binary expression tree, prints both prefix and postfix traversals, and evaluates the expression using integer (`long`) arithmetic.

## How It Works

Implemented in [suchsymbols.cpp](suchsymbols.cpp):

- **`struct TreeNode`** — Stores a token string (`item`) along with `left` and `right` child pointers.
- **`TreeNode* build(string str)`** — Recursively builds the tree by locating the rightmost lowest-precedence operator (`+` or `-` first; `*` or `/` only if no `+`/`-` exists). Choosing the rightmost occurrence preserves left-to-right associativity for equal-precedence operators. When no operator remains, the substring becomes a leaf operand.
- **`preOrder` / `postOrder`** — Emit space-separated prefix and postfix representations of the tree.
- **`long solve(TreeNode *r)`** — Recursively parses leaf digit strings and evaluates `+`, `-`, `*`, and `/` nodes bottom-up.

## Input / Output Format

- **Input:** Whitespace-separated infix expression strings (integers and `+`, `-`, `*`, `/` without parentheses) read until EOF.
- **Output:** Three lines per expression:
  1. Prefix expression
  2. Postfix expression
  3. Evaluated `long` result

## Build & Run

```bash
g++ -std=c++17 suchsymbols.cpp -o mp10
./mp10
```

### Example

Input:

```text
8+3*4-6/2
24/4*3
```

Output:

```text
- + 8 * 3 4 / 6 2 
8 3 4 * + 6 2 / - 
17
* / 24 4 3 
24 4 / 3 * 
18
```
