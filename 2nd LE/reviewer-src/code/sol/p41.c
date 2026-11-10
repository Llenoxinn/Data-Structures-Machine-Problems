// Sorts the stack so that the smallest item is on top (popping gives
// 1, 2, 3, ...). Only one extra stack is used.
void sortStack(stack *s) {
    stack r;                         // sorted, largest on top
    int x, y;
    stInit(&r);

    while (stPop(s, &x)) {
        // items in r larger than x must go back to s so that x fits below them
        while (stTop(&r, &y) && y > x) {
            stPop(&r, &y);
            stPush(s, y);
        }
        stPush(&r, x);
    }
    while (stPop(&r, &x)) stPush(s, x);   // moving back reverses the order
}
