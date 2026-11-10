#include "../lib/testutil.h"
#include "../sol/p04.c"

void fill(slist *l) { int v[] = {2,4,4,4,7,9}, i; l->size = 6; for (i = 0; i < 6; i++) l->items[i] = v[i]; }

int main(void) {
    slist l; int i, it;
    fill(&l); insert(&l, 5);
    { int e[] = {2,4,4,4,5,7,9}; CHECK(l.size == 7); for (i = 0; i < 7; i++) CHECK(l.items[i] == e[i]); }
    fill(&l); CHECK(erase(&l, 4) == 1);
    { int e[] = {2,4,4,7,9}; CHECK(l.size == 5); for (i = 0; i < 5; i++) CHECK(l.items[i] == e[i]); }
    fill(&l); CHECK(search(&l, 4) == 1 && search(&l, 5) == -1);
    CHECK(count(&l, 4) == 3 && count(&l, 9) == 1 && count(&l, 3) == 0);
    CHECK(erase(&l, 8) == 0);
    /* random operations against a counting model */
    for (it = 0; it < 300; it++) {
        int cnt[20] = {0}, op, x, k;
        l.size = 0;
        for (op = 0; op < 200; op++) {
            x = rnd(20);
            if (rnd(3)) { if (insert(&l, x)) cnt[x]++; }
            else CHECK(erase(&l, x) == (cnt[x] > 0 ? (cnt[x]--, 1) : 0));
            for (k = 1; k < l.size; k++) CHECK(l.items[k - 1] <= l.items[k]);
            x = rnd(20);
            CHECK(count(&l, x) == cnt[x]);
            k = search(&l, x);
            CHECK(cnt[x] ? (k >= 0 && l.items[k] == x && (k == 0 || l.items[k - 1] < x)) : k == -1);
        }
    }
    DONE();
}
