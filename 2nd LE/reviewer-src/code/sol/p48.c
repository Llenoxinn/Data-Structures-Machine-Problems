// Interleaves the first half of a queue of even length with the second:
// [1 2 3 4 5 6 7 8] -> [1 5 2 6 3 7 4 8]. Uses one stack.
void interleaveHalves(queue *q) {
    stack st;
    int x, half = qSize(q) / 2;
    stInit(&st);

    for (int i = 0; i < half; i++) {     // 1. first half onto the stack
        qDeq(q, &x);                     //    q: 5 6 7 8   st: 1 2 3 4 (top 4)
        stPush(&st, x);
    }
    while (stPop(&st, &x)) qEnq(q, x);   // 2. q: 5 6 7 8 4 3 2 1
    for (int i = 0; i < half; i++) {     // 3. q: 4 3 2 1 5 6 7 8
        qDeq(q, &x);
        qEnq(q, x);
    }
    for (int i = 0; i < half; i++) {     // 4. first half onto the stack again
        qDeq(q, &x);                     //    q: 5 6 7 8   st: 4 3 2 1 (top 1)
        stPush(&st, x);
    }
    for (int i = 0; i < half; i++) {     // 5. alternate: one from the stack,
        stPop(&st, &x);                  //    one from the front of q
        qEnq(q, x);
        qDeq(q, &x);
        qEnq(q, x);
    }
}
