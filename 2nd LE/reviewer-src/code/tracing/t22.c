// libs:
// array deque of capacity 8 with positional add: the SHORTER side moves.
// Returns the number of items moved.
typedef struct { int a[8]; int j; int n; } adq;   // item i at a[(j + i) % 8]

int add(adq *d, int i, int x) {
    int moved = 0;
    if (i < d->n / 2) {                       // items 0..i-1 move one cell left
        d->j = (d->j + 7) % 8;
        for (int k = 0; k < i; k++, moved++)
            d->a[(d->j + k) % 8] = d->a[(d->j + k + 1) % 8];
    } else {                                  // items i..n-1 move one cell right
        for (int k = d->n; k > i; k--, moved++)
            d->a[(d->j + k) % 8] = d->a[(d->j + k - 1) % 8];
    }
    d->a[(d->j + i) % 8] = x;
    d->n++;
    return moved;
}

void show(adq *d) {
    printf("j=%d raw=[", d->j);
    for (int k = 0; k < 8; k++) printf("%d%s", d->a[k], k < 7 ? " " : "");
    printf("] list=");
    for (int k = 0; k < d->n; k++) printf("%d ", d->a[(d->j + k) % 8]);
    printf("\n");
}

int main() {
    adq d = {{0}, 0, 0};
    int m = 0;
    for (int x = 1; x <= 4; x++) m = m + add(&d, d.n, x * 10);   // 10 20 30 40
    printf("moved %d  ", m); show(&d);
    printf("moved %d  ", add(&d, 1, 15)); show(&d);
    printf("moved %d  ", add(&d, 3, 25)); show(&d);
    printf("moved %d  ", add(&d, 0, 5)); show(&d);
    printf("moved %d  ", add(&d, 6, 45)); show(&d);
    return 0;
}
