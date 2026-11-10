// libs: listings/circular.c
void show(cnode *last) {
    if (last == NULL) { printf("(empty)\n"); return; }
    cnode *c = last->next;
    do { printf("%d ", c->item); c = c->next; } while (c != last->next);
    printf("| last=%d\n", last->item);
}

int main() {
    cnode *q = NULL;
    int x = 0;
    enq(&q, 1); enq(&q, 2); enq(&q, 3); show(q);
    q = q->next; show(q);                    // one pointer move
    q = q->next->next; show(q);
    deq(&q, &x); printf("got %d  ", x); show(q);
    enq(&q, 4); show(q);
    while (deq(&q, &x)) printf("%d ", x);
    printf("\n");
    show(q);
    int r = deq(&q, &x);
    printf("%d %d\n", r, x);
    return 0;
}
