// libs:
typedef struct node { int item; struct node *next; } node;

void mystery(node *p) {
    if (p == NULL) { printf("# "); return; }
    printf("%d ", p->item);
    mystery(p->next);
    printf("%d ", p->item);
}

int g(node *p) {
    if (p == NULL) return 0;
    if (p->item % 2 == 0) return p->item + g(p->next);
    return g(p->next) - 1;
}

int h(node *p) {
    if (p == NULL || p->next == NULL) return 0;
    if (p->item < p->next->item) return 1 + h(p->next);
    return h(p->next);
}

int main() {
    int v[] = {1, 2, 3, 4}, w[] = {3, 5, 2, 8, 6, 9}, i;
    node *a = NULL, *b = NULL, **t = &a;
    for (i = 0; i < 4; i++) {          // t: address of the last next field
        *t = (node *)malloc(sizeof(node));
        (*t)->item = v[i];
        (*t)->next = NULL;
        t = &((*t)->next);
    }
    t = &b;
    for (i = 0; i < 6; i++) {
        *t = (node *)malloc(sizeof(node));
        (*t)->item = w[i];
        (*t)->next = NULL;
        t = &((*t)->next);
    }
    mystery(a); printf("\n");
    printf("%d %d\n", g(a), g(b));
    printf("%d %d\n", h(a), h(b));
    return 0;
}
