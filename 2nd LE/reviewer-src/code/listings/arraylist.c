#define MAX 10
typedef struct { int items[MAX]; int size; } list;

void init(list *l) { l->size = 0; }

int append(list *l, int x) {                 /* O(1) */
    if (l->size == MAX) return 0;            /* full: report failure, change nothing */
    l->items[l->size++] = x;                 /* store, THEN increment */
    return 1;
}
int insertFront(list *l, int x) {            /* O(n) */
    int i;
    if (l->size == MAX) return 0;
    for (i = l->size; i > 0; i--)            /* move the LAST item first, so that */
        l->items[i] = l->items[i - 1];       /* nothing is overwritten before it  */
    l->items[0] = x;                         /* is copied                          */
    l->size++;
    return 1;
}
int removeFirst(list *l) {                   /* O(n) */
    int i;
    if (l->size == 0) return 0;
    for (i = 0; i < l->size - 1; i++)        /* move the FIRST item first */
        l->items[i] = l->items[i + 1];
    l->size--;
    return 1;
}
int removeLast(list *l) {                    /* O(1): the old cell is just ignored */
    if (l->size == 0) return 0;
    l->size--;
    return 1;
}
int setItem(list *l, int x, int p) {         /* p is 1-based, as in arraylist.c */
    if (p < 1 || p > l->size) return 0;
    l->items[p - 1] = x;
    return 1;
}
int itemAt(list l, int p) {                  /* 1-based; no bounds check! */
    return l.items[p - 1];
}
