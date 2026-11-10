// A queue built from two stacks. Items enter through "in" and leave through
// "out"; moving everything from in to out reverses the order, which turns
// last-in-first-out into first-in-first-out.
typedef struct {
    stack in;
    stack out;
} twoStackQueue;

void tsqInit(twoStackQueue *q) {
    stInit(&q->in);
    stInit(&q->out);
}

void tsqPush(twoStackQueue *q, int x) {
    stPush(&q->in, x);
}

// Moves items only when out is empty, so each item moves at most once.
void shift(twoStackQueue *q) {
    if (stEmpty(&q->out)) {
        int x;
        while (stPop(&q->in, &x)) stPush(&q->out, x);
    }
}

// Removes the front into *x. Returns 0 if the queue is empty.
int tsqPop(twoStackQueue *q, int *x) {
    shift(q);
    return stPop(&q->out, x);
}

// Copies the front into *x without removing it. Returns 0 if empty.
int tsqPeek(twoStackQueue *q, int *x) {
    shift(q);
    return stTop(&q->out, x);
}

int tsqEmpty(twoStackQueue *q) {
    return stEmpty(&q->in) && stEmpty(&q->out);
}
