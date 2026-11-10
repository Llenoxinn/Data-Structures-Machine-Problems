// O(m): the sum 1 + 2 + ... + (m + 1) is known, so subtract the array sum.
int missingNumber(int a[], int m) {
    int n = m + 1;
    int expected = n * (n + 1) / 2;
    int actual = 0;
    for (int i = 0; i < m; i++) {
        actual = actual + a[i];
    }
    return expected - actual;
}

// Bonus, O(log m): before the gap a[i] == i + 1, after it a[i] == i + 2.
// Binary search for the first index where a[i] != i + 1.
int missingNumberFast(int a[], int m) {
    int lo = 0;
    int hi = m;                          // the answer index is in [0, m]
    while (lo < hi) {
        int mid = lo + (hi - lo) / 2;
        if (a[mid] == mid + 1) lo = mid + 1;   // gap is to the right
        else hi = mid;                         // gap is here or to the left
    }
    return lo + 1;
}
