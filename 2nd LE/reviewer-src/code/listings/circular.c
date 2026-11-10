// A queue on a circular singly linked list that keeps ONLY a pointer to the
// last node: last->next is the first node. Both operations are O(1).
typedef struct cnode { int item; struct cnode *next; } cnode;

void enq(cnode **last, int x) {
    cnode *n = (cnode *)malloc(sizeof(cnode));
    n->item = x;
    if (*last == NULL) n->next = n;          // a one-node circle
    else { n->next = (*last)->next; (*last)->next = n; }
    *last = n;                               // the new node is the last one
}

int deq(cnode **last, int *x) {
    if (*last == NULL) return 0;
    cnode *first = (*last)->next;
    *x = first->item;
    if (first == *last) *last = NULL;        // it was the only node
    else (*last)->next = first->next;
    free(first);
    return 1;
}
