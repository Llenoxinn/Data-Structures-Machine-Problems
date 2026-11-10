// libs: lib/stackqueue.h
int main() {
    stack s;
    queue q;
    int x = -1, y = -1, r;
    stInit(&s);
    qInit(&q);
    stPush(&s, 1); stPush(&s, 2); stPush(&s, 3);
    qEnq(&q, 10); qEnq(&q, 20);
    stPop(&s, &x);
    qDeq(&q, &y);
    printf("%d %d\n", x, y);
    qEnq(&q, x);
    stPush(&s, y);
    r = stPop(&s, &x);
    r = r + stPop(&s, &x);
    r = r + stPop(&s, &x);
    r = r + stPop(&s, &x);
    printf("%d %d\n", r, x);
    r = qDeq(&q, &y);
    r = r + qDeq(&q, &y);
    r = r + qDeq(&q, &y);
    r = r + qDeq(&q, &y);
    printf("%d %d\n", r, y);
    stPush(&s, 4); stPush(&s, 5);
    while (!stEmpty(&s)) { stPop(&s, &x); qEnq(&q, x); }
    while (!qEmpty(&q)) { qDeq(&q, &y); stPush(&s, y); }
    while (!stEmpty(&s)) { stPop(&s, &x); printf("%d ", x); }
    printf("\n");
    return 0;
}
