# MP 10: [[ ^_^ (°o°) (^_^) (^O^) (^o^) (^^) ¯\_(ツ)_/¯ ]] ↟↟↟

Read the lecture slides on **expression trees** first.

## Problem

Evaluate a given **infix expression**.

- The expression contains **no parentheses**.
- The only operators are `+`, `−`, `*` and `/`.
- `+` and `−` have the same precedence, and `*` and `/` have the same precedence.
- `+` and `−` have **lower** precedence than `*` and `/`.
- Operators with the same precedence are evaluated **left to right**. This affects which operator is placed where in the expression tree ↟.

### Example

Take the infix expression `100/10*2/5`. All operators have the same precedence, so they are evaluated left to right. The resulting postfix expression, based on the expression tree, must evaluate `100/10` first.

## Approach

- Build the expression tree of the infix expression to aid in its evaluation (see the slides).
- You may implement this **iteratively or recursively**.
- It is **not required** to build a `binaryTree` class, especially if you go recursive. At the very least, implement a **node** for the expression tree.
- The input is a string, so string operations can help. For example:

```cpp
int main() {
    string st = "34*2*3-2*3*7";
    string left = st.substr(0, 6);
    string right = st.substr(7);
    int position = st.find("-");

    cout << "string: " << st << endl;
    cout << "left: " << left << endl;
    cout << "right: " << right << endl;
    cout << "position: " << position << endl;

    return 0;
}
```

## Output

For each expression, print three lines:

1. The **prefix** expression
2. The **postfix** expression
3. The computed **value**

## Sample

**Input**

```
1+2+3+4+5+6+7+8+9+10-55
1-2-3-4-5-6-7-8-9-10+55
100/2/5/5/2*100
20*2+50
```

**Output**

```
- + + + + + + + + + 1 2 3 4 5 6 7 8 9 10 55
1 2 + 3 + 4 + 5 + 6 + 7 + 8 + 9 + 10 + 55 -
0
+ - - - - - - - - - 1 2 3 4 5 6 7 8 9 10 55
1 2 - 3 - 4 - 5 - 6 - 7 - 8 - 9 - 10 - 55 +
2
* / / / / 100 2 5 5 2 100
100 2 / 5 / 5 / 2 / 100 *
100
+ * 20 2 50
20 2 * 50 +
90
```
