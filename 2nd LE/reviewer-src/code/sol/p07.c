// Keeps one copy of each value of the sorted array. Returns the new length.
int dedupSorted(int a[], int n) {
    if (n == 0) return 0;
    int w = 1;                       // a[0..w-1] holds the unique items
    for (int r = 1; r < n; r++) {
        if (a[r] != a[w - 1]) {      // a new value
            a[w] = a[r];
            w++;
        }
    }
    return w;
}
