// libs: lib/stackqueue.h
// Pushes 1, 2, ..., n in this order and pops as soon as the top is the next
// wanted item. Prints u for a push, o for a pop. Returns 1 if want[] can be
// popped in this order.
int produce(int want[], int n) {
    stack s;
    int next = 1, j = 0, top;
    stInit(&s);
    while (j < n) {
        if (stTop(&s, &top) && top == want[j]) {
            stPop(&s, &top);
            printf("o");
            j++;
        } else if (next <= n) {
            stPush(&s, next);
            next++;
            printf("u");
        } else {
            printf(" stuck: top %d, want %d\n", top, want[j]);
            return 0;
        }
    }
    printf(" ok\n");
    return 1;
}

int main() {
    int w[5][4] = {{3, 2, 1, 4}, {1, 2, 3, 4}, {3, 1, 2, 4},
                   {2, 4, 3, 1}, {4, 1, 2, 3}};
    int count = 0;
    for (int i = 0; i < 5; i++) count = count + produce(w[i], 4);
    printf("%d\n", count);
    return 0;
}
