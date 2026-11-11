// Length of the longest contiguous subarray in which max - min <= limit.
// [8 2 4 7], limit 4 -> 2 ([2 4] or [4 7]).
// Two monotonic deques of indices of the window a[left..right]:
//   maxd: values decreasing (front = index of the maximum)
//   mind: values increasing (front = index of the minimum)
int longestSubarray(int a[], int n, int limit) {
    deque<int> maxd, mind;
    int left = 0, best = 0;

    for (int right = 0; right < n; right++) {
        while (!maxd.empty() && a[maxd.back()] <= a[right]) maxd.pop_back();
        maxd.push_back(right);
        while (!mind.empty() && a[mind.back()] >= a[right]) mind.pop_back();
        mind.push_back(right);

        // shrink from the left until the window is valid again
        while (a[maxd.front()] - a[mind.front()] > limit) {
            left++;
            if (maxd.front() < left) maxd.pop_front();   // the front fell out
            if (mind.front() < left) mind.pop_front();
        }
        if (right - left + 1 > best) best = right - left + 1;
    }
    return best;
}
