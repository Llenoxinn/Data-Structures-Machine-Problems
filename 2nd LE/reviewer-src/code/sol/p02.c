// t becomes the m x n transpose of the n x m matrix a.
void transpose(int a[][10], int n, int m, int t[][10]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            t[j][i] = a[i][j];
        }
    }
}

// Transposes a square n x n matrix in place.
void transposeInPlace(int a[][10], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {    // only above the diagonal
            int tmp = a[i][j];
            a[i][j] = a[j][i];
            a[j][i] = tmp;
        }
    }
}
