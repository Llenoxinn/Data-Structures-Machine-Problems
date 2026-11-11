// libs:
// array deque of capacity 8 with positional add: the SHORTER side moves.
class Adq {
public:
    int a[8];
    int j;           // item i is at a[(j + i) % 8]
    int n;

    Adq() {
        for (int k = 0; k < 8; k++) a[k] = 0;
        j = 0;
        n = 0;
    }

    int add(int i, int x) {          // returns the number of items moved
        int moved = 0;
        if (i < n / 2) {                          // items 0..i-1 move one cell left
            j = (j + 7) % 8;
            for (int k = 0; k < i; k++, moved++)
                a[(j + k) % 8] = a[(j + k + 1) % 8];
        } else {                                  // items i..n-1 move one cell right
            for (int k = n; k > i; k--, moved++)
                a[(j + k) % 8] = a[(j + k - 1) % 8];
        }
        a[(j + i) % 8] = x;
        n++;
        return moved;
    }

    void show() {
        printf("j=%d raw=[", j);
        for (int k = 0; k < 8; k++) printf("%d%s", a[k], k < 7 ? " " : "");
        printf("] list=");
        for (int k = 0; k < n; k++) printf("%d ", a[(j + k) % 8]);
        printf("\n");
    }
};

int main() {
    Adq d;
    int m = 0;
    for (int x = 1; x <= 4; x++) m = m + d.add(d.n, x * 10);   // 10 20 30 40
    printf("moved %d  ", m); d.show();
    printf("moved %d  ", d.add(1, 15)); d.show();
    printf("moved %d  ", d.add(3, 25)); d.show();
    printf("moved %d  ", d.add(0, 5)); d.show();
    printf("moved %d  ", d.add(6, 45)); d.show();
    return 0;
}
