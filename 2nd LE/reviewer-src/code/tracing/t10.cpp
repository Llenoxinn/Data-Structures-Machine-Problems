// libs:
int main() {
    stack<int> s;
    queue<int> q;
    int x, y, r;
    s.push(1); s.push(2); s.push(3);
    q.push(10); q.push(20);
    x = s.top(); s.pop();
    y = q.front(); q.pop();
    printf("%d %d\n", x, y);
    q.push(x);
    s.push(y);
    r = 0;
    while (!s.empty()) { x = s.top(); s.pop(); r++; }
    printf("%d %d\n", r, x);
    r = 0;
    while (!q.empty()) { y = q.front(); q.pop(); r++; }
    printf("%d %d\n", r, y);
    s.push(4); s.push(5);
    while (!s.empty()) { q.push(s.top()); s.pop(); }
    while (!q.empty()) { s.push(q.front()); q.pop(); }
    while (!s.empty()) { printf("%d ", s.top()); s.pop(); }
    printf("\n");
    return 0;
}
