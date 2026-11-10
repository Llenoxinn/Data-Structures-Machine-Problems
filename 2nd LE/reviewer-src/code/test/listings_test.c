// Tests of the C listings of Part I (array list, lowerBound, popFront/popBack,
// circular queue).
#include "../listings/arraylist.c"
#include "../listings/lowerbound.c"
#include "../lib/sll.h"
#include "../listings/sll_pop.c"
#include "../listings/circular.c"
#include "../lib/testutil.h"

int main(void) {
    int it, op, i, x, m[200], mn;
    /* array list (1-based setItem / itemAt) */
    for (it = 0; it < 300; it++) {
        list l; init(&l); mn = 0;
        for (op = 0; op < 100; op++) { int r = rnd(5); x = rnd(50);
            if (r == 0) { CHECK(append(&l, x) == (mn < MAX)); if (mn < MAX) m[mn++] = x; }
            else if (r == 1) { CHECK(insertFront(&l, x) == (mn < MAX));
                if (mn < MAX) { for (i = mn; i > 0; i--) m[i] = m[i-1]; m[0] = x; mn++; } }
            else if (r == 2) { CHECK(removeFirst(&l) == (mn > 0)); if (mn) { for (i = 0; i < mn - 1; i++) m[i] = m[i+1]; mn--; } }
            else if (r == 3) { CHECK(removeLast(&l) == (mn > 0)); if (mn) mn--; }
            else { int p = rnd(mn + 2); CHECK(setItem(&l, x, p) == (p >= 1 && p <= mn)); if (p >= 1 && p <= mn) m[p-1] = x; }
            CHECK(l.size == mn); for (i = 1; i <= mn; i++) CHECK(itemAt(l, i) == m[i-1]); }
    }
    /* lowerBound */
    for (it = 0; it < 2000; it++) { int n = rnd(20), a[20], lb;
        for (i = 0; i < n; i++) a[i] = (i ? a[i-1] : 0) + rnd(3);
        x = rnd(40); lb = 0; while (lb < n && a[lb] < x) lb++;
        CHECK(lowerBound(a, n, x) == lb); }
    /* SLL popFront / popBack */
    for (it = 0; it < 300; it++) { sll l; sinit(&l); mn = 0;
        for (op = 0; op < 100; op++) { int r = rnd(4); x = rnd(50);
            if (r == 0) { pushBack(&l, x); m[mn++] = x; }
            else if (r == 1) { pushFront(&l, x); for (i = mn; i > 0; i--) m[i] = m[i-1]; m[0] = x; mn++; }
            else if (r == 2) { int y; CHECK(popFront(&l, &y) == (mn > 0)); if (mn) { CHECK(y == m[0]); for (i = 0; i < mn-1; i++) m[i] = m[i+1]; mn--; } }
            else { int y; CHECK(popBack(&l, &y) == (mn > 0)); if (mn) { CHECK(y == m[mn-1]); mn--; } }
            CHECK(l.size == mn && (mn == 0) == (l.head == NULL) && (mn == 0) == (l.tail == NULL));
            if (mn) CHECK(l.head->item == m[0] && l.tail->item == m[mn-1] && l.tail->next == NULL); }
        sdestroy(&l); }
    /* circular list queue */
    for (it = 0; it < 300; it++) { cnode *q = NULL; int h = 0, t = 0;
        for (op = 0; op < 100; op++) {
            if (rnd(2)) { x = rnd(50); enq(&q, x); m[t++] = x; }
            else { int y; CHECK(deq(&q, &y) == (h < t)); if (h < t) CHECK(y == m[h++]); } }
        while (deq(&q, &x)) {} }
    CHECK(g_live_blocks == 0);
    DONE();
}
