// libs:
int main() {
    queue<int> q;
    int k = 3;
    for (int i = 1; i <= 6; i++) q.push(i);
    while (q.size() > 1) {
        for (int step = 1; step < k; step++) { q.push(q.front()); q.pop(); }
        printf("out:%d ", q.front());
        q.pop();
    }
    printf("\nwinner:%d\n", q.front());
    return 0;
}
