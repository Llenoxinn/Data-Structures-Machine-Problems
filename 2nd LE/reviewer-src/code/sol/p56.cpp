// An array deque with positional add and remove (after the course notes).
// Item i lives at a[(j + i) % 100]; an insertion or a removal moves the
// SHORTER side, so at most min(i, n - i) items are moved.
class ArrayDeque {
public:
    int a[100];
    int j;                           // index of item 0
    int n;                           // number of items

    ArrayDeque() { j = 0; n = 0; }

    int size() { return n; }
    int get(int i) { return a[(j + i) % 100]; }

    // Inserts x so that it becomes item i (0 <= i <= n). false on failure.
    bool add(int i, int x) {
        if (n == 100 || i < 0 || i > n) return false;
        if (i < n / 2) {                          // move items 0..i-1 one cell left
            j = (j - 1 + 100) % 100;
            for (int k = 0; k < i; k++)
                a[(j + k) % 100] = a[(j + k + 1) % 100];
        } else {                                  // move items i..n-1 one cell right
            for (int k = n; k > i; k--)
                a[(j + k) % 100] = a[(j + k - 1) % 100];
        }
        a[(j + i) % 100] = x;
        n++;
        return true;
    }

    // Removes item i (0 <= i < n) and returns it; returns -1 if i is invalid.
    int remove(int i) {
        if (i < 0 || i >= n) return -1;
        int x = a[(j + i) % 100];
        if (i < n / 2) {                          // move items 0..i-1 one cell right
            for (int k = i; k > 0; k--)
                a[(j + k) % 100] = a[(j + k - 1) % 100];
            j = (j + 1) % 100;
        } else {                                  // move items i+1..n-1 one cell left
            for (int k = i; k < n - 1; k++)
                a[(j + k) % 100] = a[(j + k + 1) % 100];
        }
        n--;
        return x;
    }
};
