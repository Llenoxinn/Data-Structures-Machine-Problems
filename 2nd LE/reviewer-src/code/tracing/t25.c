// libs: sol/p51.c
void forward(linkedDeque *d) {
    for (dqnode *c = d->sentinel.next; c != &d->sentinel; c = c->next)
        printf("%d ", c->item);
    printf("| size %d\n", d->size);
}

int main() {
    linkedDeque d;
    int x = -1;
    ldInit(&d);
    int r = ldPopBack(&d, &x);
    printf("%d %d %d\n", d.sentinel.next == &d.sentinel, r, x);
    ldPushBack(&d, 1); ldPushBack(&d, 2); ldPushFront(&d, 0); ldPushBack(&d, 3);
    forward(&d);
    ldPopBack(&d, &x); printf("%d ", x);
    ldPopFront(&d, &x); printf("%d\n", x);
    forward(&d);
    printf("%d %d\n", d.sentinel.prev->item, d.sentinel.next->prev == &d.sentinel);

    linkedDeque e = d;                       // copies the struct, sentinel too
    printf("%d %d\n", e.sentinel.next == d.sentinel.next,
           e.sentinel.next->prev == &e.sentinel);
    ldPushFront(&d, 9);
    printf("%d %d %d\n", d.sentinel.next->item, e.sentinel.next->item, e.size);
    ldFree(&d);
    printf("%d %d\n", d.size, d.sentinel.next == &d.sentinel);
    return 0;
}
