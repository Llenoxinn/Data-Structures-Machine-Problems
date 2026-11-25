# MP 3: Arbitrary-Precision Integer & Fibonacci

## Overview

`BigNum.h` and `BigNum.cpp` implement string-backed non-negative integers (`BigNum`) and an iterative Fibonacci generator capable of computing values well beyond 64-bit integer limits.

## API

Declared in [BigNum.h](BigNum.h) and defined in [BigNum.cpp](BigNum.cpp):

### `BigNum` Class

| Member | Description |
| --- | --- |
| `BigNum()` | Default constructor; initializes the value to `"0"`. |
| `BigNum(std::string str)` | Constructs a `BigNum` from `str` (strips a leading `'+'` if present, or falls back to `"0"` when empty). |
| `BigNum add(BigNum &other) const` | Adds `this` and `other` digit by digit from least significant to most significant digit with carry propagation. |
| `std::string getNum()` | Returns the decimal string representation. |

### Free Function

```cpp
BigNum fibonacci(unsigned int n);
```

Computes the `n`-th Fibonacci number iteratively (`F(0) = 0`, `F(1) = 1`) using `BigNum::add`.

## Build Notes

This module intentionally omits `main()` so it can be linked with an external test driver:

```bash
g++ -std=c++17 BigNum.cpp driver.cpp -o mp3
./mp3
```

### Sample Results

| `n` | `fibonacci(n).getNum()` |
| --- | --- |
| `0` | `0` |
| `10` | `55` |
| `50` | `12586269025` |
| `100` | `354224848179261915075` |
