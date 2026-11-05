# MP 11: "Ancestors, hear my plea ... Please bring honor to us all"

> Tranquil as a forest<br>
> But on fire within.<br>
> Once you find your center<br>
> You are sure to win.

## Problem

Implement the following additional operations for a **binary search tree**.

## Operations

| Operation | Description |
| --- | --- |
| `bool ancestor(int a, int b)` | Returns `true` if `a` is a **proper ancestor** of `b`, `false` otherwise. |
| `bool descendant(int a, int b)` | Returns `true` if `a` is a **proper descendant** of `b`, `false` otherwise. |
| `int successor(int a)` | Returns the **successor** of `a`. |
| `int predecessor(int a)` | Returns the **predecessor** of `a`. |

## Definitions

- **Ancestor:** any node `y` on the unique path from the root `r` to node `n` is an ancestor of `n`. Every node is an ancestor of itself.
- **Proper ancestor:** a node `y` that is an ancestor of `n` and is not the same node as `n`.
- **Proper descendant:** a node `y` for which `n` is an ancestor of `y` and `y` is not the same node as `n`.
- **Successor:** the next node or item in the inorder traversal of a binary tree. The last node or item in the traversal has no successor.
- **Predecessor:** the previous node or item in the inorder traversal of a binary tree. The first node or item in the traversal has no predecessor.

## Input

1. A positive integer `n`, the number of elements to insert into the BST, followed by `n` integers. Insert them one by one.
2. Two items `a` and `b`. Determine if `a` is a proper ancestor of `b`.
3. Two items `a` and `b`. Determine if `a` is a proper descendant of `b`.
4. Two items `a` and `b`. Determine the successor of `a` and the predecessor of `b`.

## Output

| Query | Condition | Print |
| --- | --- | --- |
| Ancestor | `a` is an ancestor of `b` | `Laozi` |
| Ancestor | otherwise | `Mushu` |
| Descendant | `a` is a descendant of `b` | `Mulan` |
| Descendant | otherwise | `Mushu` |
| Successor and predecessor | they exist | the successor and predecessor |
| Successor and predecessor | otherwise | `Li Shang` |
