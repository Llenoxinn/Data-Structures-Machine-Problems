// out[i] = the first negative number of the window a[i..i+k-1], or 0 if the
// window has none, for every window of size k. Returns n - k + 1.
// [12 -1 -7 8 -15 30 16 28], k = 3 -> [-1 -1 -7 -15 -15 0]
int firstNegatives(int a[], int n, int k, int out[]) {
    queue<int> neg;                  // indices of negatives, oldest first
    int m = 0;

    for (int i = 0; i < n; i++) {
        if (a[i] < 0) neg.push(i);
        if (i >= k - 1) {                        // window a[i-k+1..i] is full
            while (!neg.empty() && neg.front() < i - k + 1) {
                neg.pop();                       // fell out of the window
            }
            if (!neg.empty()) out[m] = a[neg.front()];
            else out[m] = 0;
            m++;
        }
    }
    return m;
}
