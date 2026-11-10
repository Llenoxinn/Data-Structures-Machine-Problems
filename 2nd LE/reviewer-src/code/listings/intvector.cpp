// A growable array of int ("vector list"), after the course notes.
// Invariant: 0 <= n <= cap and the list is a[0..n-1].
class IntVector {
    int *a;          // the backing array (heap)
    int cap;         // its length
    int n;           // number of list items
    // resize: allocate a new array of length max(1, 2n) and copy the n items.
    void resize() {
        int newCap = (2 * n > 1) ? 2 * n : 1;
        int *b = (int *)malloc(newCap * sizeof(int));
        for (int i = 0; i < n; i++) b[i] = a[i];      // O(n) copy
        free(a);
        a = b;
        cap = newCap;
    }
public:
    IntVector() { a = NULL; cap = 0; n = 0; }
    ~IntVector() { free(a); }
    int size()     { return n; }
    int capacity() { return cap; }
    int get(int i) { return a[i]; }            // O(1); caller checks 0 <= i < n
    void set(int i, int x) { a[i] = x; }       // O(1)

    // add(i, x): insert x at position i (0 <= i <= n); shift a[i..n-1] right.
    void add(int i, int x) {
        if (n + 1 > cap) resize();                    // full: double the array
        for (int j = n; j > i; j--) a[j] = a[j - 1];  // shift, from the END
        a[i] = x;
        n++;
    }
    void push_back(int x) { add(n, x); }              // amortised O(1)

    // remove(i): delete position i, shifting a[i+1..n-1] left.
    int remove(int i) {
        int x = a[i];
        for (int j = i; j < n - 1; j++) a[j] = a[j + 1];
        n--;
        if (cap >= 3 * n) resize();                   // too empty: shrink (3n!)
        return x;
    }
    int pop_back() { return remove(n - 1); }          // amortised O(1)
};
