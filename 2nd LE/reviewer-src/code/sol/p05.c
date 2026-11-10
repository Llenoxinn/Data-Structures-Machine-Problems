void reverse(int a[], int lo, int hi) {
    while (lo < hi) {
        int tmp = a[lo];
        a[lo] = a[hi];
        a[hi] = tmp;
        lo++;
        hi--;
    }
}

// Rotates a[0..n-1] to the right by k places.
void rotate(int a[], int n, int k) {
    if (n == 0) return;
    k = k % n;
    reverse(a, 0, n - 1);   // [1 2 3 4 5 6 7] -> [7 6 5 4 3 2 1]
    reverse(a, 0, k - 1);   // first k items   -> [5 6 7 4 3 2 1]
    reverse(a, k, n - 1);   // remaining items -> [5 6 7 1 2 3 4]
}
