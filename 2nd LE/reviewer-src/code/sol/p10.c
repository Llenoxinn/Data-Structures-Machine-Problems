// Moves all zeros to the end; the other items keep their order.
void moveZeroes(int a[], int n) {
    int w = 0;                       // next place for a non-zero item
    for (int r = 0; r < n; r++) {
        if (a[r] != 0) {
            a[w] = a[r];
            w++;
        }
    }
    while (w < n) {
        a[w] = 0;
        w++;
    }
}
