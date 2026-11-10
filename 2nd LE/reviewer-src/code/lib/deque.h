typedef struct {
    int items[100];
    int front;           // index of the first item
    int size;
} deque;                 // circular: item i is at items[(front + i) % 100]

void dqInit(deque *d) { d->front = 0; d->size = 0; }
int dqEmpty(deque *d) { return d->size == 0; }
int dqSize(deque *d) { return d->size; }

// Adds x before the first item. Returns 0 if the deque is full.
int dqPushFront(deque *d, int x) {
    if (d->size == 100) return 0;
    d->front = (d->front - 1 + 100) % 100;   // one step back, wrapping to 99
    d->items[d->front] = x;
    d->size++;
    return 1;
}

// Adds x after the last item. Returns 0 if the deque is full.
int dqPushBack(deque *d, int x) {
    if (d->size == 100) return 0;
    d->items[(d->front + d->size) % 100] = x;
    d->size++;
    return 1;
}

// Removes the first item into *x. Returns 0 if the deque is empty.
int dqPopFront(deque *d, int *x) {
    if (d->size == 0) return 0;
    *x = d->items[d->front];
    d->front = (d->front + 1) % 100;
    d->size--;
    return 1;
}

// Removes the last item into *x. Returns 0 if the deque is empty.
int dqPopBack(deque *d, int *x) {
    if (d->size == 0) return 0;
    *x = d->items[(d->front + d->size - 1) % 100];
    d->size--;
    return 1;
}

// Copy the first / last item into *x without removing it. 0 if empty.
int dqFront(deque *d, int *x) {
    if (d->size == 0) return 0;
    *x = d->items[d->front];
    return 1;
}

int dqBack(deque *d, int *x) {
    if (d->size == 0) return 0;
    *x = d->items[(d->front + d->size - 1) % 100];
    return 1;
}
