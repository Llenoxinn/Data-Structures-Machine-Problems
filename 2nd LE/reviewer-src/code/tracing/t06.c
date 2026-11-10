// libs: lib/sll.h listings/sll_pop.c
void state(char *op, sll *l) {
    printf("%-11s size=%d head=", op, l->size);
    if (l->head) printf("%d", l->head->item); else printf("NULL");
    printf(" tail=");
    if (l->tail) printf("%d", l->tail->item); else printf("NULL");
    printf("  ");
    sdisplay(l);
}

int main() {
    sll l;
    int x = -1;
    sinit(&l);
    pushBack(&l, 5);   state("pushBack 5", &l);
    pushFront(&l, 3);  state("pushFront 3", &l);
    pushBack(&l, 8);   state("pushBack 8", &l);
    popBack(&l, &x);   state("popBack", &l);
    popBack(&l, &x);   state("popBack", &l);
    popFront(&l, &x);  state("popFront", &l);
    int r = popFront(&l, &x);
    printf("%d %d\n", r, x);
    pushFront(&l, 1);  state("pushFront 1", &l);
    pushBack(&l, 2);   state("pushBack 2", &l);
    return 0;
}
