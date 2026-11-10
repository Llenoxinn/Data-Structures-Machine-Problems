// libs: sol/p24.c
void show(char *op, mlist *l) {
    mnode *c;
    printf("%-13s n=%d mid=", op, l->size);
    if (l->size) printf("%d", middle(l)); else printf("-");
    printf("  [");
    for (c = l->head; c != NULL; c = c->next)
        printf("%d%s", c->item, c->next ? " " : "");
    printf("]\n");
}

int main() {
    mlist l;
    int x;
    minit(&l);
    mPushBack(&l, 10);  show("mPushBack 10", &l);
    mPushBack(&l, 20);  show("mPushBack 20", &l);
    mPushBack(&l, 30);  show("mPushBack 30", &l);
    mPushBack(&l, 40);  show("mPushBack 40", &l);
    mPushFront(&l, 5);  show("mPushFront 5", &l);
    mPushFront(&l, 1);  show("mPushFront 1", &l);
    mPopFront(&l, &x);  show("mPopFront", &l);
    mPopBack(&l, &x);   show("mPopBack", &l);
    mPushBack(&l, 50);  show("mPushBack 50", &l);
    mPopFront(&l, &x);  show("mPopFront", &l);
    return 0;
}
