// libs:
// circular deque of capacity 5: item i lives at a[(f + i) % 5]
class Cdq {
public:
    int a[5];
    int f;           // index of the front item
    int n;           // number of items

    Cdq() {
        for (int i = 0; i < 5; i++) a[i] = 0;
        f = 0;
        n = 0;
    }

    int pushFront(int x) {           // 1 on success, 0 if full
        if (n == 5) return 0;
        f = (f + 4) % 5;             // one step back: + 4 is - 1 modulo 5
        a[f] = x;
        n++;
        return 1;
    }
    int pushBack(int x) {
        if (n == 5) return 0;
        a[(f + n) % 5] = x;
        n++;
        return 1;
    }
    int popFront() { int x = a[f]; f = (f + 1) % 5; n--; return x; }
    int popBack() { n--; return a[(f + n) % 5]; }

    void show() {
        printf("f=%d n=%d raw=[%d %d %d %d %d] deque=", f, n,
               a[0], a[1], a[2], a[3], a[4]);
        for (int i = 0; i < n; i++) printf("%d ", a[(f + i) % 5]);
        printf("\n");
    }
};

int main() {
    Cdq d;
    d.pushBack(1); d.pushFront(2); d.pushFront(3); d.pushBack(4);
    d.show();
    printf("%d ", d.popBack());
    printf("%d\n", d.popFront());
    d.show();
    d.pushBack(5); d.pushBack(6); d.pushFront(7);
    d.show();
    int r = d.pushFront(8);
    r = r * 10 + d.pushBack(9);
    printf("%d\n", r);
    printf("%d %d %d\n", (0 - 1) % 5, (0 - 1 + 5) % 5, -7 / 2);
    return 0;
}
