// libs:
typedef struct node { int item; struct node *next; } node;
typedef struct { node *head; int size; } slist;

slist shallowCopy(slist s) { return s; }
slist deepCopy(slist s) {
    slist d;
    node *c = s.head, **t = &d.head;
    d.head = NULL; d.size = s.size;
    while (c != NULL) {
        *t = (node *)malloc(sizeof(node));
        (*t)->item = c->item; (*t)->next = NULL;
        t = &((*t)->next);
        c = c->next;
    }
    return d;
}
void show(slist s) {
    for (node *c = s.head; c != NULL; c = c->next) printf("%d ", c->item);
    printf("| %d\n", s.size);
}
void pushFront(slist *s, int x) {
    node *n = (node *)malloc(sizeof(node));
    n->item = x; n->next = s->head; s->head = n; s->size++;
}

int main() {
    slist orig = {NULL, 0};
    pushFront(&orig, 3); pushFront(&orig, 2); pushFront(&orig, 1);
    slist sh = shallowCopy(orig), dp = deepCopy(orig);
    sh.head->item = 99;
    dp.head->next->item = 77;
    pushFront(&sh, 0);
    show(orig); show(sh); show(dp);
    return 0;
}
