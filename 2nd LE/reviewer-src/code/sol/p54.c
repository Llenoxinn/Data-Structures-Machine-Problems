// Length of the longest contiguous subarray in which max - min <= limit.
// [8 2 4 7], limit 4 -> 2 ([2 4] or [4 7]).
// Two monotonic deques of indices of the window a[left..right]:
//   maxd: values decreasing (front = index of the maximum)
//   mind: values increasing (front = index of the minimum)
int longestSubarray(int a[], int n, int limit) {
    deque maxd, mind;
    int left = 0, best = 0, j, f, g;
    dqInit(&maxd);
    dqInit(&mind);

    for (int right = 0; right < n; right++) {
        while (dqBack(&maxd, &j) && a[j] <= a[right]) dqPopBack(&maxd, &j);
        dqPushBack(&maxd, right);
        while (dqBack(&mind, &j) && a[j] >= a[right]) dqPopBack(&mind, &j);
        dqPushBack(&mind, right);

        // shrink from the left until the window is valid again
        while (dqFront(&maxd, &f) && dqFront(&mind, &g) && a[f] - a[g] > limit) {
            left++;
            if (f < left) dqPopFront(&maxd, &f);   // the front fell out
            if (g < left) dqPopFront(&mind, &g);
        }
        if (right - left + 1 > best) best = right - left + 1;
    }
    return best;
}
