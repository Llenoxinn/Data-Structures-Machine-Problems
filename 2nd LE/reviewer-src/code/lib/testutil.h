/* Test helpers (not shown in the book). Include after sll.h and/or dll.h. */
unsigned int g_seed = 12345u;
int rnd(int m) { g_seed = g_seed * 1103515245u + 12345u; return (int)((g_seed >> 16) % (unsigned)m); }

#ifdef HAVE_SLL
void sllFrom(sll *l, int a[], int n) { int i; sinit(l); for (i = 0; i < n; i++) pushBack(l, a[i]); }
/* 1 if l holds exactly a[0..n-1], size and tail are consistent */
int sllIs(sll *l, int a[], int n) {
    snode *c = l->head, *last = NULL; int i = 0;
    while (c != NULL) { if (i >= n || c->item != a[i]) return 0; last = c; c = c->next; i++; }
    return i == n && l->size == n && l->tail == last;
}
#endif
#ifdef HAVE_DLL
void dllFrom(list *l, int a[], int n) { int i; init(l); for (i = 0; i < n; i++) append(l, a[i]); }
int dllIs(list *l, int a[], int n) {
    node *c = l->head, *prev = NULL; int i = 0;
    while (c != NULL) {
        if (i >= n || c->item != a[i] || c->prev != prev) return 0;
        prev = c; c = c->next; i++;
    }
    return i == n && l->size == n && l->tail == prev;
}
#endif
