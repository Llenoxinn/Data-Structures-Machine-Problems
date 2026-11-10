// A stack built from one queue. After each push the new item is rotated to
// the front of the queue, so the front is always the top of the stack.
typedef struct {
    queue q;
} queueStack;

void qsInit(queueStack *s) {
    qInit(&s->q);
}

void qsPush(queueStack *s, int x) {
    int y;
    qEnq(&s->q, x);
    for (int i = 0; i < qSize(&s->q) - 1; i++) {   // older items go behind x
        qDeq(&s->q, &y);
        qEnq(&s->q, y);
    }
}

int qsPop(queueStack *s, int *x) {
    return qDeq(&s->q, x);
}

int qsTop(queueStack *s, int *x) {
    return qFront(&s->q, x);
}

int qsEmpty(queueStack *s) {
    return qEmpty(&s->q);
}
