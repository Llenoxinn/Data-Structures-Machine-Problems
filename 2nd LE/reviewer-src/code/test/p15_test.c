#include "../lib/sll.h"
#include "../sol/p15.c"

int main(void) {
    sll l; int i, n;
    for (n = 0; n <= 10; n++) {
        snode *c;
        sinit(&l);
        for (i = 0; i < n; i++) { if (i % 2) append(&l.head, i); else appendLoop(&l.head, i); }
        for (c = l.head, i = 0; c != NULL; c = c->next, i++) CHECK(c->item == i);
        CHECK(i == n);
        sdestroy(&l);
    }
    CHECK(g_live_blocks == 0);
    DONE();
}
