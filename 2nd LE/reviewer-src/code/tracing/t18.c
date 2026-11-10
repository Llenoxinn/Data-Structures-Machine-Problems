// libs: lib/stackqueue.h
int main() {
    queue q;
    int x, k = 3, step;
    qInit(&q);
    for (int i = 1; i <= 6; i++) qEnq(&q, i);
    while (qSize(&q) > 1) {
        for (step = 1; step < k; step++) { qDeq(&q, &x); qEnq(&q, x); }
        qDeq(&q, &x);
        printf("out:%d ", x);
    }
    qDeq(&q, &x);
    printf("\nwinner:%d\n", x);
    return 0;
}
