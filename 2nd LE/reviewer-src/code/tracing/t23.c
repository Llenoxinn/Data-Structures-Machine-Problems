// libs: lib/deque.h
// The sliding-window maximum of Problem 53, printing the deque (indices,
// front first) after each step. show() looks inside only to print.
void show(deque *d) {
    printf("[");
    for (int t = 0; t < d->size; t++)
        printf("%s%d", t ? " " : "", d->items[(d->front + t) % 100]);
    printf("]");
}

int main() {
    int a[] = {4, 2, 12, 3, 8, 8, 1, 5}, n = 8, k = 3, j;
    deque d;
    dqInit(&d);
    for (int i = 0; i < n; i++) {
        if (dqFront(&d, &j) && j <= i - k) dqPopFront(&d, &j);
        while (dqBack(&d, &j) && a[j] <= a[i]) dqPopBack(&d, &j);
        dqPushBack(&d, i);
        printf("i=%d a[i]=%2d dq=", i, a[i]);
        show(&d);
        if (i >= k - 1) { dqFront(&d, &j); printf(" max=%d", a[j]); }
        printf("\n");
    }
    return 0;
}
