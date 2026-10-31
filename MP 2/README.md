# MP 2: 2 Become 1

## Problem

Given two sorted lists of strings, merge them into one sorted list.

Implement the following function:

```cpp
int merge(string A[], string B[], string C[], int n, int m);
```

- `A` has `n` elements, `B` has `m` elements.
- `C` can accommodate `n + m` elements.
- Merge the sorted elements of `A` and `B` into `C`, keeping them sorted.
- Return the **number of string comparisons** made while merging.
- In case of duplicates, take the string from `A` first.

## Samples

### Sample 1

**Input**

```
4 cayennepepper ginger tarragon turmeric
4 celeryseed marjoram saffron whitepepper
```

**Output**

```
7
cayennepepper celeryseed ginger marjoram saffron tarragon turmeric
```

The first line is the number of comparisons (7). The second line is the contents of `C`.

The 7 comparisons were:

1. `"cayennepepper"` with `"celeryseed"`
2. `"ginger"` with `"celeryseed"`
3. `"ginger"` with `"marjoram"`
4. `"marjoram"` with `"tarragon"`
5. `"saffron"` with `"tarragon"`
6. `"tarragon"` with `"whitepepper"`
7. `"turmeric"` with `"whitepepper"`

### Sample 2

**Input**

```
3 coriander dill nutmeg
3 thyme vanillabean wormwood
```

**Output**

```
3
coriander dill nutmeg thyme vanillabean wormwood
```

Only 3 comparisons were made:

1. `"coriander"` with `"thyme"`
2. `"dill"` with `"thyme"`
3. `"nutmeg"` with `"thyme"`

No more comparisons were needed, since `A` ran out of strings.

## Notes

- **Do not** create a `main` function. Implement `merge` only.
- For reference, the driver code is:

```cpp
int n, m;
cin >> n;
for (int i = 0; i < n; i++)
    cin >> A[i];
cin >> m;
for (int i = 0; i < m; i++)
    cin >> B[i];

cout << merge(A, B, C, n, m) << endl;
for (int i = 0; i < n + m; i++)
    cout << C[i] << " ";
cout << endl;
```
