// n people stand in a circle, numbered 1..n. Starting at 1, every k-th
// person is removed until one is left. Returns that person's number.
int josephus(int n, int k) {
    queue q;
    int x;
    qInit(&q);
    for (int i = 1; i <= n; i++) qEnq(&q, i);

    while (qSize(&q) > 1) {
        for (int i = 1; i < k; i++) {    // the first k-1 are skipped:
            qDeq(&q, &x);                // they go to the back
            qEnq(&q, x);
        }
        qDeq(&q, &x);                    // the k-th is removed
    }
    qDeq(&q, &x);
    return x;
}

// Bonus, O(n) time and O(1) space. With i people the survivor's 0-based
// position is (survivor with i-1 people + k) % i.
int josephusFast(int n, int k) {
    int pos = 0;                         // one person: position 0
    for (int i = 2; i <= n; i++) pos = (pos + k) % i;
    return pos + 1;
}
