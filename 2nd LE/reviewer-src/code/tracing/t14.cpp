// libs:
// Pushes 1, 2, ..., n in this order and pops as soon as the top is the next
// wanted item. Prints u for a push, o for a pop. Returns 1 if want[] can be
// popped in this order.
int produce(int want[], int n) {
    stack<int> s;
    int next = 1, j = 0;
    while (j < n) {
        if (!s.empty() && s.top() == want[j]) {
            s.pop();
            printf("o");
            j++;
        } else if (next <= n) {
            s.push(next);
            next++;
            printf("u");
        } else {
            printf(" stuck: top %d, want %d\n", s.top(), want[j]);
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
