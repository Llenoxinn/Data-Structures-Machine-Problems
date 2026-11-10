#include "../lib/sll.h"
#define HAVE_SLL
#include "../lib/testutil.h"
#include "../sol/p16.c"
#include "../sol/p17.c"
#include "../sol/p18.c"
#include "../sol/p25.c"
#include "../sol/p26.c"
#include "../sol/p27.c"
#include "../sol/p28.c"
#include "../sol/p29.c"
#include "../sol/p30.c"
#include "../sol/p31.c"

int main(void) {
    sll l, m, o; int it, i, x;
    /* P16 */
    for (it = 0; it < 500; it++) {
        int n = rnd(9), a[9], e[9]; snode *c;
        for (i = 0; i < n; i++) { a[i] = rnd(50); e[n-1-i] = a[i]; }
        sllFrom(&l, a, n); reverseList(&l); CHECK(sllIs(&l, e, n));
        l.head = reverseRec(l.head); for (c = l.head; c && c->next; c = c->next) {} l.tail = c;
        CHECK(sllIs(&l, a, n)); sdestroy(&l);
    }
    /* P17 */
    { int a[] = {1,2,3,4}, b[] = {1,2,3,4,5}, c[] = {10,20,30,40,50};
      sllFrom(&l,a,4); CHECK(middleItem(&l)==3); sdestroy(&l);
      sllFrom(&l,b,5); CHECK(middleItem(&l)==3); sdestroy(&l);
      sllFrom(&l,c,5); CHECK(kthFromEnd(&l,2,&x)==1 && x==40); CHECK(kthFromEnd(&l,5,&x)==1 && x==10);
      CHECK(kthFromEnd(&l,6,&x)==0 && kthFromEnd(&l,0,&x)==0); sdestroy(&l); }
    for (it = 0; it < 1000; it++) {
        int n = 1 + rnd(12), a[12], k = rnd(14);
        for (i = 0; i < n; i++) a[i] = i;
        sllFrom(&l, a, n); CHECK(middleItem(&l) == n / 2);
        if (k >= 1 && k <= n) CHECK(kthFromEnd(&l, k, &x) == 1 && x == n - k);
        else CHECK(kthFromEnd(&l, k, &x) == 0);
        sdestroy(&l);
    }
    /* P18 */
    for (it = 0; it < 2000; it++) {
        int n = rnd(6), k = rnd(4), pos = rnd(8) - 1, a[6], b[4], e[10], r = 0, ok;
        for (i = 0; i < n; i++) a[i] = i; for (i = 0; i < k; i++) b[i] = 100 + i;
        sllFrom(&l, a, n); sllFrom(&m, b, k);
        ok = splice(&l, pos, &m);
        if (pos < 0 || pos > n) { CHECK(ok == 0 && sllIs(&l, a, n) && sllIs(&m, b, k)); }
        else {
            for (i = 0; i < pos; i++) e[r++] = a[i]; for (i = 0; i < k; i++) e[r++] = b[i];
            for (i = pos; i < n; i++) e[r++] = a[i];
            CHECK(ok == 1 && sllIs(&l, e, n + k) && m.head == NULL && m.tail == NULL && m.size == 0);
        }
        sdestroy(&l); sdestroy(&m);
    }
    /* P25 */
    for (it = 0; it < 2000; it++) {
        int n = rnd(7), k = rnd(30), a[7], e[7];
        for (i = 0; i < n; i++) a[i] = i;
        for (i = 0; i < n; i++) e[i] = a[(i + k) % n];
        sllFrom(&l, a, n); rotateLeft(&l, k); CHECK(sllIs(&l, e, n)); sdestroy(&l);
    }
    /* P26 */
    for (it = 0; it < 2000; it++) {
        int n = rnd(9), a[9], e[9], r = 0, p = rnd(6);
        for (i = 0; i < n; i++) a[i] = rnd(6);
        for (i = 0; i < n; i++) if (a[i] < p) e[r++] = a[i];
        for (i = 0; i < n; i++) if (a[i] >= p) e[r++] = a[i];
        sllFrom(&l, a, n); partitionList(&l, p); CHECK(sllIs(&l, e, n)); sdestroy(&l);
    }
    /* P27 */
    for (it = 0; it < 2000; it++) {
        int n = rnd(7), k = rnd(9) - 1, a[7], e[7], r = 0, ok;
        for (i = 0; i < n; i++) a[i] = i;
        sllFrom(&l, a, n); ok = removeNthFromEnd(&l, k);
        if (k < 1 || k > n) CHECK(ok == 0 && sllIs(&l, a, n));
        else { for (i = 0; i < n; i++) if (i != n - k) e[r++] = a[i]; CHECK(ok == 1 && sllIs(&l, e, n - 1)); }
        sdestroy(&l);
    }
    /* P28 */
    for (it = 0; it < 500; it++) {
        int n = rnd(9), a[9], e[9];
        for (i = 0; i < n; i++) a[i] = i;
        for (i = 0; i < n; i++) e[i] = (i % 2 == 0) ? (i + 1 < n ? a[i+1] : a[i]) : a[i-1];
        sllFrom(&l, a, n); swapPairs(&l); CHECK(sllIs(&l, e, n)); sdestroy(&l);
    }
    /* P29 */
    for (it = 0; it < 2000; it++) {
        int n = rnd(9), back = rnd(n + 1) - 1, a[9]; snode *c, *target = NULL;   /* back = -1: no cycle */
        for (i = 0; i < n; i++) a[i] = i;
        sllFrom(&l, a, n);
        for (c = l.head, i = 0; c; c = c->next, i++) if (i == back) target = c;
        if (n > 0 && back >= 0) l.tail->next = target;
        CHECK(hasCycle(l.head) == (n > 0 && back >= 0));
        CHECK(cycleStart(l.head) == ((n > 0 && back >= 0) ? target : NULL));
        if (n > 0) l.tail->next = NULL;
        sdestroy(&l);
    }
    /* P30 */
    for (it = 0; it < 500; it++) {
        int n = rnd(9), a[9], e[9], r = 0;
        for (i = 0; i < n; i++) a[i] = i;
        for (i = 0; i < n; i += 2) e[r++] = a[i]; for (i = 1; i < n; i += 2) e[r++] = a[i];
        sllFrom(&l, a, n); oddEvenList(&l); CHECK(sllIs(&l, e, n)); sdestroy(&l);
    }
    /* P31 */
    for (it = 0; it < 2000; it++) {
        int n = 1 + rnd(5), k = 1 + rnd(5), a[5], b[5], va = 0, vb = 0, p = 1, s;
        for (i = 0; i < n; i++) { a[i] = rnd(10); va += a[i] * p; p *= 10; } p = 1;
        for (i = 0; i < k; i++) { b[i] = rnd(10); vb += b[i] * p; p *= 10; }
        sllFrom(&l, a, n); sllFrom(&m, b, k); addNumbers(&l, &m, &o);
        { int e[7], r = 0; s = va + vb; do { e[r++] = s % 10; s /= 10; } while (s);
          /* leading zeros of the inputs survive in the output */
          while (r < (n > k ? n : k)) e[r++] = 0;
          CHECK(sllIs(&o, e, r)); }
        sdestroy(&l); sdestroy(&m); sdestroy(&o);
    }
    CHECK(g_live_blocks == 0);
    DONE();
}
