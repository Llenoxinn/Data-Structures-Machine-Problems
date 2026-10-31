# MP 3: I Need A BigNum (BigNum), I Want A BigNum

## Problem

The 101st Fibonacci number has 21 digits. It cannot be stored even in an `unsigned long long`, whose range is only 0 to 18,446,744,073,709,551,615.

One way to address this is to represent the number as a string, which can hold as many characters as needed.

## Instructions

### `BigNum` class

Construct a class called `BigNum`.

- It should have at least a `std::string` data member that represents the number.
- Use C++'s `std::string` in this MP. When adding BigNums, remember that they are strings.

| Member | Description |
| --- | --- |
| `BigNum()` | Default constructor. Constructs the number `0`. |
| `BigNum(std::string)` | Constructs a BigNum from a string. Do **not** assume the string is a valid base 10 number. If it is not, set the BigNum to `0`. |
| `BigNum add(BigNum)` | Adds two BigNums. Needed to generate large Fibonacci numbers. |
| `std::string getNum()` | Accessor that returns the `std::string` of the BigNum. |

```cpp
BigNum();
BigNum(std::string);
BigNum add(BigNum);
std::string getNum();
```

### `fibonacci` function

Construct a function `fibonacci` (**not** a member function of `BigNum`) that takes an `unsigned int n` and returns the nth Fibonacci element as a `BigNum`.

```cpp
BigNum fibonacci(unsigned int);
```

- The 0th Fibonacci element is `0` and the 1st is `1`.
- Each next element is the sum of the previous two.
- The Fibonacci elements must be represented as `BigNum`, and their addition must use the `add` operation of the `BigNum` class.

## Notes

- **Do not submit a `main` function.** The `BigNum` header file and implementation file are enough.
- For context, the input to the machine problem (`main`) is an `unsigned int` used to call `fibonacci(unsigned int)`.

## Sample

**Input**

```
6
30
108
400
734
```

**Output**

```
8
832040
16641027750620563662096
17602368064501396646822694539241125077038438330449219188672599289675345044216019675
1115431593560796532808555613387415446435640602179650541231738132603247322617636923378668235747257928207760719121572766322243359119244897932753117196435737
```
