// An array deque with positional add and remove (after the course notes).
// Item i lives at a[(j + i) % 100]; an insertion or a removal moves the
// SHORTER side, so at most min(i, n - i) items are moved.
typedef struct {
    int a[100];
    int j;                           // index of item 0
    int n;                           // number of items
} arrayDeque;

void adInit(arrayDeque *d) { d->j = 0; d->n = 0; }

int adGet(arrayDeque *d, int i) { return d->a[(d->j + i) % 100]; }

// Inserts x so that it becomes item i (0 <= i <= n). Returns 0 on failure.
int adAdd(arrayDeque *d, int i, int x) {
    if (d->n == 100 || i < 0 || i > d->n) return 0;
    if (i < d->n / 2) {                       // move items 0..i-1 one cell left
        d->j = (d->j - 1 + 100) % 100;
        for (int k = 0; k < i; k++)
            d->a[(d->j + k) % 100] = d->a[(d->j + k + 1) % 100];
    } else {                                  // move items i..n-1 one cell right
        for (int k = d->n; k > i; k--)
            d->a[(d->j + k) % 100] = d->a[(d->j + k - 1) % 100];
    }
    d->a[(d->j + i) % 100] = x;
    d->n++;
    return 1;
}

// Removes item i into *x (0 <= i < n). Returns 0 on failure.
int adRemove(arrayDeque *d, int i, int *x) {
    if (i < 0 || i >= d->n) return 0;
    *x = d->a[(d->j + i) % 100];
    if (i < d->n / 2) {                       // move items 0..i-1 one cell right
        for (int k = i; k > 0; k--)
            d->a[(d->j + k) % 100] = d->a[(d->j + k - 1) % 100];
        d->j = (d->j + 1) % 100;
    } else {                                  // move items i+1..n-1 one cell left
        for (int k = i; k < d->n - 1; k++)
            d->a[(d->j + k) % 100] = d->a[(d->j + k + 1) % 100];
    }
    d->n--;
    return 1;
}
