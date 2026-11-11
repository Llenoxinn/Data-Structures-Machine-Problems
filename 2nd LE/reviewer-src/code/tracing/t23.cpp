// libs:
// The sliding-window maximum of Problem 53, printing the deque (indices,
// front first) after each step. d[t] reads item t of a deque<int>.
void show(deque<int> d) {
    printf("[");
    for (int t = 0; t < (int)d.size(); t++)
        printf("%s%d", t ? " " : "", d[t]);
    printf("]");
}

int main() {
    int a[] = {4, 2, 12, 3, 8, 8, 1, 5}, n = 8, k = 3;
    deque<int> d;
    for (int i = 0; i < n; i++) {
        if (!d.empty() && d.front() <= i - k) d.pop_front();
        while (!d.empty() && a[d.back()] <= a[i]) d.pop_back();
        d.push_back(i);
        printf("i=%d a[i]=%2d dq=", i, a[i]);
        show(d);
        if (i >= k - 1) printf(" max=%d", a[d.front()]);
        printf("\n");
    }
    return 0;
}
