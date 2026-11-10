// out[i] = the first negative number of the window a[i..i+k-1], or 0 if the
// window has none, for every window of size k. Returns n - k + 1.
// [12 -1 -7 8 -15 30 16 28], k = 3 -> [-1 -1 -7 -15 -15 0]
int firstNegatives(int a[], int n, int k, int out[]) {
    queue neg;                       // indices of negatives, oldest first
    int front, m = 0;
    qInit(&neg);

    for (int i = 0; i < n; i++) {
        if (a[i] < 0) qEnq(&neg, i);
        if (i >= k - 1) {                        // window a[i-k+1..i] is full
            while (qFront(&neg, &front) && front < i - k + 1) {
                qDeq(&neg, &front);              // fell out of the window
            }
            if (qFront(&neg, &front)) out[m] = a[front];
            else out[m] = 0;
            m++;
        }
    }
    return m;
}
