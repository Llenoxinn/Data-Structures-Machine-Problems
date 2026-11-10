int lowerBound(int a[], int n, int x) {
    int lo = 0, hi = n, mid;
    /* Invariant: a[i] <  x for every i < lo,
                  a[i] >= x for every i >= hi.   */
    while (lo < hi) {
        mid = lo + (hi - lo) / 2;      /* never (lo+hi)/2: avoids overflow     */
        if (a[mid] < x) lo = mid + 1;  /* mid and everything left is too small */
        else            hi = mid;      /* mid could be the answer: keep it     */
    }
    return lo;                         /* lo == hi: the boundary               */
}
