// A deque on a circular doubly linked list with one sentinel node.
// sentinel.next is the first item, sentinel.prev the last; when the deque is
// empty both point back to the sentinel, so no pointer is ever NULL.
typedef struct dqnode {
    int item;
    struct dqnode *prev;
    struct dqnode *next;
} dqnode;

typedef struct {
    dqnode sentinel;                 // inside the struct: never copy a
    int size;                        // linkedDeque, always pass its address
} linkedDeque;

void ldInit(linkedDeque *d) {
    d->sentinel.next = &d->sentinel;
    d->sentinel.prev = &d->sentinel;
    d->size = 0;
}

int ldEmpty(linkedDeque *d) { return d->size == 0; }

// Links a new node with item x between the neighbours a and b.
int ldLinkBetween(linkedDeque *d, dqnode *a, dqnode *b, int x) {
    dqnode *n = (dqnode *)malloc(sizeof(dqnode));
    if (n == NULL) return 0;
    n->item = x;
    n->prev = a;
    n->next = b;
    a->next = n;
    b->prev = n;
    d->size++;
    return 1;
}

// Unlinks node n, stores its item in *x and frees it.
void ldUnlink(linkedDeque *d, dqnode *n, int *x) {
    *x = n->item;
    n->prev->next = n->next;
    n->next->prev = n->prev;
    free(n);
    d->size--;
}

int ldPushFront(linkedDeque *d, int x) {
    return ldLinkBetween(d, &d->sentinel, d->sentinel.next, x);
}

int ldPushBack(linkedDeque *d, int x) {
    return ldLinkBetween(d, d->sentinel.prev, &d->sentinel, x);
}

int ldPopFront(linkedDeque *d, int *x) {
    if (ldEmpty(d)) return 0;
    ldUnlink(d, d->sentinel.next, x);
    return 1;
}

int ldPopBack(linkedDeque *d, int *x) {
    if (ldEmpty(d)) return 0;
    ldUnlink(d, d->sentinel.prev, x);
    return 1;
}

int ldFront(linkedDeque *d, int *x) {
    if (ldEmpty(d)) return 0;
    *x = d->sentinel.next->item;
    return 1;
}

int ldBack(linkedDeque *d, int *x) {
    if (ldEmpty(d)) return 0;
    *x = d->sentinel.prev->item;
    return 1;
}

void ldFree(linkedDeque *d) {
    int x;
    while (ldPopFront(d, &x)) {}
}
