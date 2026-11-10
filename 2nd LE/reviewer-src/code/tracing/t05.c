// libs:
// circular queue: item i of the queue lives at a[(j + i) % 4]
typedef struct {
    int a[4];
    int j;           // index of the front item
    int n;           // number of items
} cqueue;

int add(cqueue *q, int x) {
    if (q->n == 4) return 0;
    q->a[(q->j + q->n) % 4] = x;
    q->n++;
    return 1;
}

int removeFront(cqueue *q, int *out) {
    if (q->n == 0) return 0;
    *out = q->a[q->j];
    q->j = (q->j + 1) % 4;
    q->n--;
    return 1;
}

void show(cqueue *q) {
    printf("j=%d n=%d ", q->j, q->n);
    printf("[%d %d %d %d]\n", q->a[0], q->a[1], q->a[2], q->a[3]);
}

int main() {
    cqueue q = {{0, 0, 0, 0}, 0, 0};
    int x;
    add(&q, 1); add(&q, 2); add(&q, 3); show(&q);
    removeFront(&q, &x); printf("removed %d\n", x); show(&q);
    add(&q, 4); add(&q, 5); show(&q);
    printf("%d\n", add(&q, 6));
    removeFront(&q, &x); removeFront(&q, &x); show(&q);
    add(&q, 7); add(&q, 8); show(&q);
    while (removeFront(&q, &x)) printf("%d ", x);
    printf("\n");
    show(&q);
    return 0;
}
