# Data Structures Machine Problems & Exam Reviewers

A collection of C and C++ implementations for Data Structures coursework at the University of the Philippines Cebu, covering Machine Problems (MPs), programming assignments, and study notes on fundamental data structures and algorithms.

## Repository Structure

```text
.
├── MP 1/                       # Fixed-point search in a sorted array (linear vs. binary)
├── MP 2/                       # Merging two sorted string arrays with comparison counting
├── MP 3/                       # Arbitrary-precision integer (BigNum) & Fibonacci generator
├── MP 4/                       # Fixed-capacity integer array list and test harness
├── MP 10/                      # Infix arithmetic expression tree parser & evaluator
├── MP 11/                      # Parent-linked BST with lineage & inorder neighbor queries
├── MP 12/                      # Self-balancing AVL tree with search probe counting
├── MP 13/                      # 0-indexed array min-heap property validator
├── MP Assignments/
│   └── Assignment 1/           # Binary packet stream checksum verifier & text reconstructor
└── 2nd LE/                     # Second Long Exam notes, PDFs, LaTeX source, and test suite
    ├── NEW/                    # Stack & queue ADT summaries, practice problems, and snippets
    └── reviewer-src/           # LaTeX source and compiled/tested C & C++ programs
```

## Machine Problems & Assignments

Each module folder contains its own `README.md` with implementation details, input/output formats, and build instructions.

| Module | Topic | Main Files | Link |
| --- | --- | --- | --- |
| **MP 1** | Fixed-point search (`A[i] == i`) comparing linear and binary search | `amIReallyI.cpp` | [MP 1](MP%201/README.md) |
| **MP 2** | Lexicographical merge of two sorted `std::string` arrays | `merge.h`, `merge.cpp` | [MP 2](MP%202/README.md) |
| **MP 3** | String-backed `BigNum` addition and iterative `fibonacci(n)` | `BigNum.h`, `BigNum.cpp` | [MP 3](MP%203/README.md) |
| **MP 4** | Static-capacity (`MAX = 20`) integer list with stdin test driver | `arrayOfLight.h`, `arrayOfLight.cpp` | [MP 4](MP%204/README.md) |
| **MP 10** | Binary expression tree construction, prefix/postfix traversal, and evaluation | `suchsymbols.cpp` | [MP 10](MP%2010/README.md) |
| **MP 11** | Parent-linked BST supporting ancestor, descendant, successor, and predecessor | `beMyMasterAncestor.cpp` | [MP 11](MP%2011/README.md) |
| **MP 12** | Self-balancing AVL tree with rotations and comparison-counted lookup | `avlTree.cpp` | [MP 12](MP%2012/README.md) |
| **MP 13** | Binary min-heap invariant checker over a fixed-size integer array | `minHeapCheck.cpp` | [MP 13](MP%2013/README.md) |
| **Assignment 1** | 16-bit one's-complement packet validation and multi-stream reassembly | `poem.h`, `poem.cpp` | [Assignment 1](MP%20Assignments/Assignment%201/README.md) |

## Second Long Exam (2nd LE) Reviewer

The [`2nd LE`](2nd%20LE/) directory holds study materials covering **Array Lists, Vectors, Singly Linked Lists, Doubly Linked Lists, Stacks, Queues, and Deques**:

- **[Second Long Exam - Lists, Stacks, Queues, Deques.pdf](2nd%20LE/Second%20Long%20Exam%20-%20Lists,%20Stacks,%20Queues,%20Deques.pdf)** — Full compiled reviewer containing consolidated lecture notes, practice exam questions, tracing exercises, and worked solutions.
- **[Second Long Exam - Notes and Practice.pdf](2nd%20LE/Second%20Long%20Exam%20-%20Notes%20and%20Practice.pdf)** — Condensed exam notes and practice problems.
- **[`2nd LE/reviewer-src/`](2nd%20LE/reviewer-src/README.md)** — LaTeX source (`src/reviewer.tex`), course ADT headers (`code/lib/`), lecture listings (`code/listings/`), tracing programs (`t01`–`t25`), problem solutions (`p01`–`p57`), and automated verification tests (`code/test/`).
- **[`2nd LE/NEW/`](2nd%20LE/NEW/)** — Stack and queue ADT summaries ([`01-SUMMARY-stack-queue.md`](2nd%20LE/NEW/01-SUMMARY-stack-queue.md)), sample tracing/theory problems ([`02-PROBLEMS-stack-queue.md`](2nd%20LE/NEW/02-PROBLEMS-stack-queue.md)), ADT slides, and array/circular/inherited queue implementations.

## Building & Running

### Machine Problems (C++17)

Standalone programs (`MP 1`, `MP 4`, `MP 10`, `MP 11`, `MP 12`, `MP 13`, `Assignment 1`) include `main()` and can be compiled directly with `g++`:

```bash
g++ -std=c++17 "MP 1/amIReallyI.cpp" -o mp1 && ./mp1
```

Library-only modules (`MP 2`, `MP 3`) omit `main()` so they can be linked against your own test driver:

```bash
g++ -std=c++17 "MP 3/BigNum.cpp" driver.cpp -o mp3 && ./mp3
```

### 2nd LE Reviewer Programs & PDF

From `2nd LE/reviewer-src/` (requires `gcc`/`g++` in `PATH`, and `tectonic` to rebuild the PDF):

```bash
bash code/build.sh            # compile and run all listings, demos, traces, and tests
cd src && tectonic reviewer.tex
```

See [2nd LE/reviewer-src/README.md](2nd%20LE/reviewer-src/README.md) for selective test runs and font requirements.
