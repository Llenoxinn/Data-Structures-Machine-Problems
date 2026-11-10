// Merges sorted a[0..n-1] and b[0..m-1] into c. Returns n + m.
int mergeArrays(int a[], int n, int b[], int m, int c[]) {
    int i = 0;
    int j = 0;
    int k = 0;

    while (i < n && j < m) {
        if (a[i] <= b[j]) {          // <= keeps equal items of a first
            c[k] = a[i];
            i++;
        } else {
            c[k] = b[j];
            j++;
        }
        k++;
    }
    while (i < n) {                  // one of these loops does nothing
        c[k] = a[i];
        i++;
        k++;
    }
    while (j < m) {
        c[k] = b[j];
        j++;
        k++;
    }
    return k;
}
