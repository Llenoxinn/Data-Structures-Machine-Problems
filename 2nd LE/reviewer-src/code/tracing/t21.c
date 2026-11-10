// libs:
// circular deque of capacity 5: item i lives at a[(f + i) % 5]
typedef struct {
    int a[5];
    int f;           // index of the front item
    int n;           // number of items
} cdq;

int pushFront(cdq *d, int x) {
    if (d->n == 5) return 0;
    d->f = (d->f + 4) % 5;           // one step back: + 4 is - 1 modulo 5
    d->a[d->f] = x;
    d->n++;
    return 1;
}
int pushBack(cdq *d, int x) {
    if (d->n == 5) return 0;
    d->a[(d->f + d->n) % 5] = x;
    d->n++;
    return 1;
}
int popFront(cdq *d) { int x = d->a[d->f]; d->f = (d->f + 1) % 5; d->n--; return x; }
int popBack(cdq *d) { d->n--; return d->a[(d->f + d->n) % 5]; }

void show(cdq *d) {
    printf("f=%d n=%d raw=[%d %d %d %d %d] deque=", d->f, d->n,
           d->a[0], d->a[1], d->a[2], d->a[3], d->a[4]);
    for (int i = 0; i < d->n; i++) printf("%d ", d->a[(d->f + i) % 5]);
    printf("\n");
}

int main() {
    cdq d = {{0, 0, 0, 0, 0}, 0, 0};
    pushBack(&d, 1); pushFront(&d, 2); pushFront(&d, 3); pushBack(&d, 4);
    show(&d);
    printf("%d ", popBack(&d));
    printf("%d\n", popFront(&d));
    show(&d);
    pushBack(&d, 5); pushBack(&d, 6); pushFront(&d, 7);
    show(&d);
    int r = pushFront(&d, 8);
    r = r * 10 + pushBack(&d, 9);
    printf("%d\n", r);
    printf("%d %d %d\n", (0 - 1) % 5, (0 - 1 + 5) % 5, -7 / 2);
    return 0;
}
