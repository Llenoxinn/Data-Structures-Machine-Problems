#include "../lib/testutil.h"
#include "../sol/p24.c"

int main(void) {
    mlist l; int it, op, x, a[200], n;
    /* random operations against an array model; mid must be index (n-1)/2 */
    for (it = 0; it < 300; it++) {
        minit(&l); n = 0;
        for (op = 0; op < 150; op++) {
            int r = rnd(4), i; mnode *c;
            if (r == 0) { x = rnd(100); mPushBack(&l, x); a[n++] = x; }
            else if (r == 1) { x = rnd(100); mPushFront(&l, x); for (i = n; i > 0; i--) a[i] = a[i-1]; a[0] = x; n++; }
            else if (r == 2) { if (mPopFront(&l, &x)) { CHECK(x == a[0]); for (i = 0; i < n - 1; i++) a[i] = a[i+1]; n--; } else CHECK(n == 0); }
            else { if (mPopBack(&l, &x)) { CHECK(x == a[n-1]); n--; } else CHECK(n == 0); }
            CHECK(l.size == n);
            if (n == 0) CHECK(l.head == NULL && l.mid == NULL && l.tail == NULL);
            else { CHECK(middle(&l) == a[(n - 1) / 2]);
                   for (c = l.head, i = 0; c->next; c = c->next, i++) {} CHECK(c == l.tail && i == n - 1);
                   for (c = l.head, i = 0; i < (n - 1) / 2; i++) c = c->next; CHECK(c == l.mid); }
        }
        while (mPopFront(&l, &x)) {}
    }
    CHECK(g_live_blocks == 0);
    DONE();
}
