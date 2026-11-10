// libs: lib/stackqueue.h
// a queue built from two stacks:
// enqueue pushes onto in; dequeue pops from out (refilled from in when empty)
typedef struct {
    stack in;
    stack out;
} twoQ;

void enq(twoQ *q, int x) { stPush(&q->in, x); }

int deq(twoQ *q) {
    int x;
    if (stEmpty(&q->out))
        while (stPop(&q->in, &x)) stPush(&q->out, x);
    if (!stPop(&q->out, &x)) return -1;
    return x;
}

int main() {
    twoQ q;
    int a;
    stInit(&q.in);
    stInit(&q.out);
    enq(&q, 1); enq(&q, 2); enq(&q, 3);
    a = deq(&q); printf("%d ", a);
    enq(&q, 4);
    a = deq(&q); printf("%d ", a);
    enq(&q, 5); enq(&q, 6);
    a = deq(&q); printf("%d ", a);
    a = deq(&q); printf("%d ", a);
    a = deq(&q); printf("%d ", a);
    a = deq(&q); printf("%d ", a);
    a = deq(&q); printf("%d\n", a);
    printf("in=%d out=%d\n", stSize(&q.in), stSize(&q.out));
    return 0;
}
