// out[i] = max(a[i..i+k-1]) for every window of size k. Returns n - k + 1.
// [1 3 -1 -3 5 3 6 7], k = 3 -> [3 3 5 5 6 7]
// The deque holds indices of the current window whose values decrease from
// front to back; the front is always the index of the window maximum.
int maxSlidingWindow(int a[], int n, int k, int out[]) {
    deque d;
    int j, m = 0;
    dqInit(&d);

    for (int i = 0; i < n; i++) {
        // 1. the front leaves when it slides out of the window a[i-k+1..i]
        if (dqFront(&d, &j) && j <= i - k) dqPopFront(&d, &j);
        // 2. smaller values at the back can never be a maximum again
        while (dqBack(&d, &j) && a[j] <= a[i]) dqPopBack(&d, &j);
        dqPushBack(&d, i);
        // 3. once the first window is complete, its maximum is at the front
        if (i >= k - 1) {
            dqFront(&d, &j);
            out[m] = a[j];
            m++;
        }
    }
    return m;
}
