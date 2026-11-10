// Jump Game VI. Start on index 0, finish on index n-1; from index i you may
// jump to any of i+1..i+k. The score is the sum of the values you land on
// (both ends included). Returns the largest possible score.
// [1 -1 -2 4 -7 3], k = 2 -> 7 (path 1 -1 4 3).
// best[i] = a[i] + max(best[i-k..i-1]); a monotonic deque of indices
// (best values decreasing) gives that window maximum in O(1).
int maxResult(int a[], int n, int k) {
    int best[10000];
    deque d;
    int j;
    dqInit(&d);

    best[0] = a[0];
    dqPushBack(&d, 0);
    for (int i = 1; i < n; i++) {
        if (dqFront(&d, &j) && j < i - k) dqPopFront(&d, &j);   // too far back
        dqFront(&d, &j);
        best[i] = a[i] + best[j];
        while (dqBack(&d, &j) && best[j] <= best[i]) dqPopBack(&d, &j);
        dqPushBack(&d, i);
    }
    return best[n - 1];
}
