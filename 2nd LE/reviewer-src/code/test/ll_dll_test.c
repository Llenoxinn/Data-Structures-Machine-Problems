#include "../lib/dll.h"
#define HAVE_DLL
#include "../lib/testutil.h"
#include "../sol/p13.c"
#include "../sol/p14.c"
#include "../sol/p19.c"
#include "../sol/p20.c"
#include "../sol/p21.c"
#include "../sol/p22.c"
#include "../sol/p23.c"

int main(void) {
    list l, m; int it, i;
    /* P13: sample tests and random tests against a filter model */
    { int a[] = {10,5,5,10,10,6,9,10,12,13}, e[] = {5,5,6,9,12,13};
      dllFrom(&l, a, 10); eraseItems(&l, 10); CHECK(dllIs(&l, e, 6)); destroy(&l); }
    { int a[] = {3,3,3,3,3}; dllFrom(&l, a, 5); eraseItems(&l, 3);
      CHECK(l.head == NULL && l.tail == NULL && l.size == 0); }
    for (it = 0; it < 3000; it++) {
        int n = rnd(12), a[12], e[12], k = 0, x = rnd(3);
        for (i = 0; i < n; i++) { a[i] = rnd(3); if (a[i] != x) e[k++] = a[i]; }
        dllFrom(&l, a, n); eraseItems(&l, x); CHECK(dllIs(&l, e, k)); destroy(&l);
    }
    CHECK(g_live_blocks == 0);
    /* P14: deep copy, including appendList(&x, x) */
    for (it = 0; it < 2000; it++) {
        int n = rnd(8), k = rnd(8), a[16], b[8];
        for (i = 0; i < n; i++) a[i] = rnd(50);
        for (i = 0; i < k; i++) { b[i] = rnd(50); a[n + i] = b[i]; }
        dllFrom(&l, a, n); dllFrom(&m, b, k);
        appendList(&l, m); destroy(&m);
        CHECK(dllIs(&l, a, n + k));
        if (it % 2) { int d[32]; for (i = 0; i < n + k; i++) d[i] = d[n + k + i] = a[i];
          appendList(&l, l); CHECK(dllIs(&l, d, 2 * (n + k))); }
        destroy(&l);
    }
    CHECK(g_live_blocks == 0);
    /* P19 */
    for (it = 0; it < 2000; it++) {
        int n = rnd(8), k = rnd(8), a[8], b[8], e[16], p = 0, q = 0, r = 0;
        a[0] = b[0] = 0;
        for (i = 0; i < n; i++) a[i] = (i ? a[i-1] : 0) + rnd(3);
        for (i = 0; i < k; i++) b[i] = (i ? b[i-1] : 0) + rnd(3);
        while (p < n || q < k) e[r++] = (q == k || (p < n && a[p] <= b[q])) ? a[p++] : b[q++];
        dllFrom(&l, a, n); dllFrom(&m, b, k); mergeSorted(&l, &m);
        CHECK(dllIs(&l, e, n + k) && m.head == NULL && m.tail == NULL && m.size == 0);
        destroy(&l);
    }
    /* P20 */
    { int a[] = {1,2,3,2,1}, b[] = {1,2,3,4}, c[] = {7}, d[] = {4,5,5,4};
      dllFrom(&l,a,5); CHECK(isPalindrome(&l)==1); destroy(&l);
      dllFrom(&l,b,4); CHECK(isPalindrome(&l)==0); destroy(&l);
      dllFrom(&l,c,0); CHECK(isPalindrome(&l)==1);
      dllFrom(&l,c,1); CHECK(isPalindrome(&l)==1); destroy(&l);
      dllFrom(&l,d,4); CHECK(isPalindrome(&l)==1); destroy(&l); }
    for (it = 0; it < 2000; it++) {
        int n = rnd(9), a[9], pal = 1;
        for (i = 0; i < n; i++) a[i] = rnd(2);
        for (i = 0; i < n; i++) if (a[i] != a[n-1-i]) pal = 0;
        dllFrom(&l, a, n); CHECK(isPalindrome(&l) == pal); destroy(&l);
    }
    /* P21 */
    for (it = 0; it < 500; it++) {
        int n = rnd(9), a[9], e[9];
        for (i = 0; i < n; i++) { a[i] = rnd(50); e[n-1-i] = a[i]; }
        dllFrom(&l, a, n); reverseDLL(&l); CHECK(dllIs(&l, e, n)); destroy(&l);
    }
    /* P22 */
    for (it = 0; it < 2000; it++) {
        int n = rnd(10), a[10], e[10], k = 0;
        for (i = 0; i < n; i++) { a[i] = (i ? a[i-1] : 0) + rnd(2); if (k == 0 || e[k-1] != a[i]) e[k++] = a[i]; }
        dllFrom(&l, a, n); removeDuplicates(&l); CHECK(dllIs(&l, e, k)); destroy(&l);
    }
    /* P23 */
    { int a[] = {2,4,4,8}, e[] = {1,2,4,4,4,5,8,9};
      dllFrom(&l,a,4); insertSorted(&l,1); insertSorted(&l,5); insertSorted(&l,9); insertSorted(&l,4);
      CHECK(dllIs(&l,e,8)); destroy(&l);
      init(&l); insertSorted(&l,3); CHECK(l.size==1 && l.head==l.tail && l.head->item==3); destroy(&l); }
    for (it = 0; it < 1000; it++) {
        int n = rnd(10), e[10], k;
        init(&l);
        for (k = 0; k < n; k++) { int x = rnd(6), j = k; insertSorted(&l, x);
          while (j > 0 && e[j-1] > x) { e[j] = e[j-1]; j--; } e[j] = x; }
        CHECK(dllIs(&l, e, n)); destroy(&l);
    }
    CHECK(g_live_blocks == 0);
    DONE();
}
