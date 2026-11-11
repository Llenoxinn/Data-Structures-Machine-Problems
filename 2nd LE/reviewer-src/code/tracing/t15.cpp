// libs: sol/p37.cpp
// show() prints the two stacks of s as price:span pairs, bottom to top.
// s is a copy, so popping it here does not change the real spanner.
void show(StockSpanner s) {
    int p[20], d[20], n = 0;
    while (!s.prices.empty()) {
        p[n] = s.prices.top(); s.prices.pop();
        d[n] = s.spans.top();  s.spans.pop();
        n++;
    }
    printf("[");
    for (int i = n - 1; i >= 0; i--)          // top was read first: go backwards
        printf("%s%d:%d", i < n - 1 ? " " : "", p[i], d[i]);
    printf("]\n");
}

int main() {
    int p[] = {100, 80, 60, 70, 60, 75, 85, 85};
    StockSpanner s;
    for (int i = 0; i < 8; i++) {
        int span = s.next(p[i]);
        printf("%3d -> %d  ", p[i], span);
        show(s);
    }
    return 0;
}
