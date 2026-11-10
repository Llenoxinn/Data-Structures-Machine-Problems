// Rotates an n x n matrix 90 degrees clockwise, in place.
// Clockwise rotation = transpose, then reverse every row.
void rotate90(int a[][10], int n) {
    for (int i = 0; i < n; i++) {             // transpose
        for (int j = i + 1; j < n; j++) {
            int tmp = a[i][j];
            a[i][j] = a[j][i];
            a[j][i] = tmp;
        }
    }
    for (int i = 0; i < n; i++) {             // reverse each row
        int lo = 0;
        int hi = n - 1;
        while (lo < hi) {
            int tmp = a[i][lo];
            a[i][lo] = a[i][hi];
            a[i][hi] = tmp;
            lo++;
            hi--;
        }
    }
}
