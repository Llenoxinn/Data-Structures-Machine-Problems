// Jump Game VI. Start on index 0, finish on index n-1; from index i you may
// jump to any of i+1..i+k. The score is the sum of the values you land on
// (both ends included). Returns the largest possible score.
// [1 -1 -2 4 -7 3], k = 2 -> 7 (path 1 -1 4 3).
// best[i] = a[i] + max(best[i-k..i-1]); a monotonic deque of indices
// (best values decreasing) gives that window maximum in O(1).
int maxResult(int a[], int n, int k) {
    int best[10000];
    deque<int> d;

    best[0] = a[0];
    d.push_back(0);
    for (int i = 1; i < n; i++) {
        if (d.front() < i - k) d.pop_front();        // too far back
        best[i] = a[i] + best[d.front()];
        while (!d.empty() && best[d.back()] <= best[i]) d.pop_back();
        d.push_back(i);
    }
    return best[n - 1];
}
