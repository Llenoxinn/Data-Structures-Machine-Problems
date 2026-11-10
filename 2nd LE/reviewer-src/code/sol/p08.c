// Finds i < j with a[i] + a[j] == target in a sorted array.
// Returns 1 and sets *pi, *pj, or returns 0 if there is no such pair.
int twoSum(int a[], int n, int target, int *pi, int *pj) {
    int lo = 0;
    int hi = n - 1;
    while (lo < hi) {
        int sum = a[lo] + a[hi];
        if (sum == target) {
            *pi = lo;
            *pj = hi;
            return 1;
        }
        if (sum < target) lo++;      // need a bigger sum
        else hi--;                   // need a smaller sum
    }
    return 0;
}
