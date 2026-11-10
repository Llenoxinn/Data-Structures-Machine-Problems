// Reverses the order of the first k items of the queue; the rest stay.
// [1 2 3 4 5], k = 3 -> [3 2 1 4 5]. Assumes 0 <= k <= size.
void reverseFirstK(queue *q, int k) {
    stack st;
    int x;
    stInit(&st);

    for (int i = 0; i < k; i++) {           // the stack reverses the first k
        qDeq(q, &x);
        stPush(&st, x);
    }
    while (stPop(&st, &x)) qEnq(q, x);      // put them back at the end

    int rest = qSize(q) - k;                // read the size once
    for (int i = 0; i < rest; i++) {        // rotate the other items
        qDeq(q, &x);                        // behind the reversed ones
        qEnq(q, x);
    }
}
