// libs:
int main() {
    int n = 16, i, j, c1 = 0, c2 = 0, c3 = 0, c4 = 0, c5 = 0, c6 = 0;

    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            c1++;

    for (i = 0; i < n; i++)
        for (j = 0; j <= i; j++)
            c2++;

    for (i = 1; i < n; i *= 2)
        for (j = 0; j < n; j++)
            c3++;

    for (i = n; i > 0; i /= 2)
        c4++;

    for (i = 0; i < n; i++)
        for (j = i; j < n; j += 4)
            c5++;

    for (i = 1; i < n; i *= 2)
        for (j = 0; j < i; j++)
            c6++;

    printf("%d %d %d %d %d %d\n", c1, c2, c3, c4, c5, c6);
    return 0;
}
