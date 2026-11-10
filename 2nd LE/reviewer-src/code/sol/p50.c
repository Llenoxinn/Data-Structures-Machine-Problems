// A deque of capacity k (1 <= k <= 1000) in a circular array.
// Item i of the deque lives at items[(front + i) % cap].
typedef struct {
    int items[1000];
    int cap;
    int front;                       // index of the first item
    int size;
} circularDeque;

void cdInit(circularDeque *d, int k) {
    d->cap = k;
    d->front = 0;
    d->size = 0;
}

int cdIsEmpty(circularDeque *d) { return d->size == 0; }
int cdIsFull(circularDeque *d) { return d->size == d->cap; }

int cdInsertFront(circularDeque *d, int x) {
    if (cdIsFull(d)) return 0;
    d->front = (d->front - 1 + d->cap) % d->cap;   // NOT (front - 1) % cap
    d->items[d->front] = x;
    d->size++;
    return 1;
}

int cdInsertLast(circularDeque *d, int x) {
    if (cdIsFull(d)) return 0;
    d->items[(d->front + d->size) % d->cap] = x;
    d->size++;
    return 1;
}

int cdDeleteFront(circularDeque *d) {
    if (cdIsEmpty(d)) return 0;
    d->front = (d->front + 1) % d->cap;
    d->size--;
    return 1;
}

int cdDeleteLast(circularDeque *d) {
    if (cdIsEmpty(d)) return 0;
    d->size--;                       // the last cell simply stops counting
    return 1;
}

// The first / last item, or -1 if the deque is empty.
int cdGetFront(circularDeque *d) {
    if (cdIsEmpty(d)) return -1;
    return d->items[d->front];
}

int cdGetRear(circularDeque *d) {
    if (cdIsEmpty(d)) return -1;
    return d->items[(d->front + d->size - 1) % d->cap];
}
