// A stack that also returns its minimum in O(1).
// "mins" holds, for every level of "all", the smallest value at or below it.
typedef struct {
    stack all;
    stack mins;
} minStack;

void msInit(minStack *m) {
    stInit(&m->all);
    stInit(&m->mins);
}

void msPush(minStack *m, int x) {
    int smallest;
    stPush(&m->all, x);
    if (stTop(&m->mins, &smallest) && smallest < x) {
        stPush(&m->mins, smallest);      // the old minimum still wins
    } else {
        stPush(&m->mins, x);             // x is the new minimum
    }
}

// Removes the top into *x. Returns 0 if empty.
int msPop(minStack *m, int *x) {
    int dummy;
    if (!stPop(&m->all, x)) return 0;
    stPop(&m->mins, &dummy);             // keep the two stacks in step
    return 1;
}

// Copies the minimum into *x. Returns 0 if empty.
int msMin(minStack *m, int *x) {
    return stTop(&m->mins, x);
}
