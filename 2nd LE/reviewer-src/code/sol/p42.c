// pushed[] is the order in which items are pushed; may some interleaving of
// pops produce popped[]?   pushed 1 2 3 4 5: popped 4 5 3 2 1 -> 1,
// popped 4 3 5 1 2 -> 0. Both arrays have n distinct items.
int validateStackSequences(int pushed[], int popped[], int n) {
    stack st;
    int j = 0;                       // next item of popped[] to produce
    int top;
    stInit(&st);

    for (int i = 0; i < n; i++) {
        stPush(&st, pushed[i]);
        // pop greedily while the top is the item we need next
        while (stTop(&st, &top) && top == popped[j]) {
            stPop(&st, &top);
            j++;
        }
    }
    return j == n;                   // every item was produced
}
