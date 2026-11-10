// Returns the element that appears more than n/2 times (it always exists).
// Boyer-Moore voting: different items cancel each other in pairs.
int majority(int a[], int n) {
    int candidate = a[0];
    int votes = 0;
    for (int i = 0; i < n; i++) {
        if (votes == 0) candidate = a[i];
        if (a[i] == candidate) votes++;
        else votes--;
    }
    return candidate;
}

// Slower version, O(n^2): count every item.
int majoritySlow(int a[], int n) {
    for (int i = 0; i < n; i++) {
        int c = 0;
        for (int j = 0; j < n; j++) {
            if (a[j] == a[i]) c++;
        }
        if (c > n / 2) return a[i];
    }
    return -1;
}
