// Largest sum of a non-empty contiguous subarray (n >= 1).
int maxSubarray(int a[], int n) {
    int endingHere = a[0];           // best sum of a subarray ending at i
    int best = a[0];
    for (int i = 1; i < n; i++) {
        if (endingHere > 0) endingHere = endingHere + a[i];   // extend
        else endingHere = a[i];                               // start over
        if (endingHere > best) best = endingHere;
    }
    return best;
}

// Slower version, O(n^2): try every starting index with a running sum.
int maxSubarraySlow(int a[], int n) {
    int best = a[0];
    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int j = i; j < n; j++) {
            sum = sum + a[j];
            if (sum > best) best = sum;
        }
    }
    return best;
}
