typedef struct {
    int items[100];
    int size;            // the top is items[size - 1]
} stack;

void stInit(stack *s) { s->size = 0; }
int stEmpty(stack *s) { return s->size == 0; }
int stSize(stack *s) { return s->size; }

// Returns 1 on success, 0 if the stack is full.
int stPush(stack *s, int x) {
    if (s->size == 100) return 0;
    s->items[s->size] = x;
    s->size++;
    return 1;
}

// Removes the top into *x. Returns 1 on success, 0 if the stack is empty.
int stPop(stack *s, int *x) {
    if (s->size == 0) return 0;
    s->size--;
    *x = s->items[s->size];
    return 1;
}

// Copies the top into *x without removing it. Returns 0 if empty.
int stTop(stack *s, int *x) {
    if (s->size == 0) return 0;
    *x = s->items[s->size - 1];
    return 1;
}

typedef struct {
    int items[100];
    int front;           // index of the first item
    int size;
} queue;                 // circular: item i is at items[(front + i) % 100]

void qInit(queue *q) { q->front = 0; q->size = 0; }
int qEmpty(queue *q) { return q->size == 0; }
int qSize(queue *q) { return q->size; }

// Returns 1 on success, 0 if the queue is full.
int qEnq(queue *q, int x) {
    if (q->size == 100) return 0;
    q->items[(q->front + q->size) % 100] = x;
    q->size++;
    return 1;
}

// Removes the front into *x. Returns 1 on success, 0 if the queue is empty.
int qDeq(queue *q, int *x) {
    if (q->size == 0) return 0;
    *x = q->items[q->front];
    q->front = (q->front + 1) % 100;
    q->size--;
    return 1;
}

// Copies the front into *x without removing it. Returns 0 if empty.
int qFront(queue *q, int *x) {
    if (q->size == 0) return 0;
    *x = q->items[q->front];
    return 1;
}
