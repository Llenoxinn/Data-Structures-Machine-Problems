// libs:
int lowerBound(int a[], int n, int x) {
    int lo = 0, hi = n, mid, step = 1;
    while (lo < hi) {
        mid = lo + (hi - lo) / 2;
        printf("step %d: lo=%d hi=%d ", step++, lo, hi);
        printf("mid=%d a[mid]=%d\n", mid, a[mid]);
        if (a[mid] < x) lo = mid + 1;
        else            hi = mid;
    }
    return lo;
}

int main() {
    int a[] = {2, 4, 4, 4, 7, 9, 12, 15, 15};
    printf("answer %d\n", lowerBound(a, 9, 4));
    printf("answer %d\n", lowerBound(a, 9, 10));
    printf("answer %d\n", lowerBound(a, 9, 20));
    return 0;
}
