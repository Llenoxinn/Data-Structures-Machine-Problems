// a[i] > 0 moves right, a[i] < 0 moves left; |a[i]| is the size. When two
// meet, the smaller explodes (both if equal). Writes the survivors, left to
// right, into out and returns how many there are.
int asteroidCollision(int a[], int n, int out[]) {
    stack st;                        // survivors so far, left to right
    stInit(&st);

    for (int i = 0; i < n; i++) {
        int x = a[i];
        int alive = 1;
        int top;
        // only a right-mover on the stack and a left-mover x can meet
        while (alive && x < 0 && stTop(&st, &top) && top > 0) {
            if (top < -x) {
                stPop(&st, &top);    // the top explodes, x keeps going
            } else if (top == -x) {
                stPop(&st, &top);    // both explode
                alive = 0;
            } else {
                alive = 0;           // x explodes
            }
        }
        if (alive) stPush(&st, x);
    }

    int m = stSize(&st);             // the stack holds the answer, last on top
    for (int k = m - 1; k >= 0; k--) stPop(&st, &out[k]);
    return m;
}
