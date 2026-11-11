// out[i] = max(a[i..i+k-1]) for every window of size k. Returns n - k + 1.
// [1 3 -1 -3 5 3 6 7], k = 3 -> [3 3 5 5 6 7]
// The deque holds indices of the current window whose values decrease from
// front to back; the front is always the index of the window maximum.
int maxSlidingWindow(int a[], int n, int k, int out[]) {
    deque<int> d;
    int m = 0;

    for (int i = 0; i < n; i++) {
        // 1. the front leaves when it slides out of the window a[i-k+1..i]
        if (!d.empty() && d.front() <= i - k) d.pop_front();
        // 2. smaller values at the back can never be a maximum again
        while (!d.empty() && a[d.back()] <= a[i]) d.pop_back();
        d.push_back(i);
        // 3. once the first window is complete, its maximum is at the front
        if (i >= k - 1) {
            out[m] = a[d.front()];
            m++;
        }
    }
    return m;
}
