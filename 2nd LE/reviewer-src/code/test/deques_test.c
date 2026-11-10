#include "../lib/deque.h"
#include "../lib/testutil.h"
#include "../sol/p50.c"
#include "../sol/p51.c"
#include "../sol/p52.c"
#include "../sol/p53.c"
#include "../sol/p54.c"
#include "../sol/p55.c"
#include "../sol/p56.c"
#include "../sol/p57.c"

/* array model of a deque: m[0..n-1] */
int m[400], mn;
void mPushF(int x) { int i; for (i = mn; i > 0; i--) m[i] = m[i-1]; m[0] = x; mn++; }
void mPopF(void) { int i; for (i = 0; i < mn - 1; i++) m[i] = m[i+1]; mn--; }

int main(void) {
    int it, i, x, op;
    /* the library deque, P50 and P51 against the model, with wrap-around */
    for (it = 0; it < 300; it++) {
        deque d; circularDeque c; linkedDeque l; int cap = 1 + rnd(8);
        dqInit(&d); cdInit(&c, cap); ldInit(&l); mn = 0;
        for (op = 0; op < 300; op++) {
            int r = rnd(4); x = rnd(100);
            if (r == 0) { int ok = (mn < cap); CHECK(cdInsertFront(&c, x) == ok); CHECK(dqPushFront(&d, x)); CHECK(ldPushFront(&l, x));
                          if (ok) mPushF(x); else { int y; dqPopFront(&d, &y); ldPopFront(&l, &y); } }
            else if (r == 1) { int ok = (mn < cap); CHECK(cdInsertLast(&c, x) == ok); CHECK(dqPushBack(&d, x)); CHECK(ldPushBack(&l, x));
                          if (ok) m[mn++] = x; else { int y; dqPopBack(&d, &y); ldPopBack(&l, &y); } }
            else if (r == 2) { int ok = mn > 0, y; CHECK(cdDeleteFront(&c) == ok); CHECK(dqPopFront(&d, &x) == ok); CHECK(ldPopFront(&l, &y) == ok);
                          if (ok) { CHECK(x == m[0] && y == m[0]); mPopF(); } }
            else { int ok = mn > 0, y; CHECK(cdDeleteLast(&c) == ok); CHECK(dqPopBack(&d, &x) == ok); CHECK(ldPopBack(&l, &y) == ok);
                          if (ok) { CHECK(x == m[mn-1] && y == m[mn-1]); mn--; } }
            CHECK(cdIsEmpty(&c) == (mn == 0) && cdIsFull(&c) == (mn == cap) && dqSize(&d) == mn && l.size == mn);
            CHECK(cdGetFront(&c) == (mn ? m[0] : -1) && cdGetRear(&c) == (mn ? m[mn-1] : -1));
            if (mn) { CHECK(dqFront(&d, &x) && x == m[0] && dqBack(&d, &x) && x == m[mn-1]);
                      CHECK(ldFront(&l, &x) && x == m[0] && ldBack(&l, &x) && x == m[mn-1]); }
        }
        ldFree(&l);
    }
    CHECK(g_live_blocks == 0);
    { circularDeque c; cdInit(&c, 3);           /* LeetCode 641 sample */
      CHECK(cdInsertLast(&c,1)==1 && cdInsertLast(&c,2)==1 && cdInsertFront(&c,3)==1 && cdInsertFront(&c,4)==0);
      CHECK(cdGetRear(&c)==2 && cdIsFull(&c)==1 && cdDeleteLast(&c)==1 && cdInsertFront(&c,4)==1 && cdGetFront(&c)==4); }
    /* P52 */
    CHECK(isPalindromeText("A man, a plan, a canal: Panama") == 1 && isPalindromeText("race a car") == 0);
    CHECK(isPalindromeText(" ") == 1 && isPalindromeText("0P") == 0 && isPalindromeText("Was it a car or a cat I saw?") == 1);
    /* P53 and P54 against brute force */
    { int a[] = {1,3,-1,-3,5,3,6,7}, o[8], e[] = {3,3,5,5,6,7};
      CHECK(maxSlidingWindow(a,8,3,o)==6); for (i = 0; i < 6; i++) CHECK(o[i]==e[i]);
      int b[] = {8,2,4,7}, c[] = {10,1,2,4,7,2}, d[] = {4,2,2,2,4,4,2,2};
      CHECK(longestSubarray(b,4,4)==2 && longestSubarray(c,6,5)==4 && longestSubarray(d,8,0)==3); }
    for (it = 0; it < 3000; it++) {
        int n = 1 + rnd(25), k = 1 + rnd(n), a[25], o[25], j, p, lim = rnd(6), best = 0;
        for (i = 0; i < n; i++) a[i] = rnd(10);
        CHECK(maxSlidingWindow(a, n, k, o) == n - k + 1);
        for (i = 0; i + k <= n; i++) { int mx = a[i]; for (j = i; j < i + k; j++) if (a[j] > mx) mx = a[j]; CHECK(o[i] == mx); }
        for (i = 0; i < n; i++) for (j = i; j < n; j++) { int mx = a[i], mi = a[i];
            for (p = i; p <= j; p++) { if (a[p] > mx) mx = a[p]; if (a[p] < mi) mi = a[p]; }
            if (mx - mi <= lim && j - i + 1 > best) best = j - i + 1; }
        CHECK(longestSubarray(a, n, lim) == best);
    }
    /* P55 against the model: pushMiddle at n/2, popMiddle at (n-1)/2 */
    { fmbQueue q; fmbInit(&q);                  /* LeetCode 1670 sample */
      fmbPushFront(&q,1); fmbPushBack(&q,2); fmbPushMiddle(&q,3); fmbPushMiddle(&q,4);
      CHECK(fmbPopFront(&q)==1 && fmbPopMiddle(&q)==3 && fmbPopMiddle(&q)==4 && fmbPopBack(&q)==2 && fmbPopFront(&q)==-1); }
    for (it = 0; it < 300; it++) { fmbQueue q; fmbInit(&q); mn = 0;
        for (op = 0; op < 120; op++) { int r = rnd(6), pos; x = rnd(100);
            if (r == 0 && mn < 90) { fmbPushFront(&q, x); mPushF(x); }
            else if (r == 1 && mn < 90) { fmbPushBack(&q, x); m[mn++] = x; }
            else if (r == 2 && mn < 90) { fmbPushMiddle(&q, x); pos = mn / 2;
                for (i = mn; i > pos; i--) m[i] = m[i-1]; m[pos] = x; mn++; }
            else if (r == 3) { x = fmbPopFront(&q); CHECK(x == (mn ? m[0] : -1)); if (mn) mPopF(); }
            else if (r == 4) { x = fmbPopBack(&q); CHECK(x == (mn ? m[mn-1] : -1)); if (mn) mn--; }
            else { x = fmbPopMiddle(&q); if (!mn) CHECK(x == -1); else { pos = (mn - 1) / 2; CHECK(x == m[pos]);
                for (i = pos; i < mn - 1; i++) m[i] = m[i+1]; mn--; } } } }
    /* P56 against the model */
    for (it = 0; it < 300; it++) { arrayDeque d; adInit(&d); mn = 0;
        for (op = 0; op < 200; op++) { int pos = rnd(mn + 2) - (rnd(9) == 0); x = rnd(100);
            if (rnd(2)) { int ok = (pos >= 0 && pos <= mn && mn < 100); CHECK(adAdd(&d, pos, x) == ok);
                if (ok) { for (i = mn; i > pos; i--) m[i] = m[i-1]; m[pos] = x; mn++; } }
            else { int ok = (pos >= 0 && pos < mn), y; CHECK(adRemove(&d, pos, &y) == ok);
                if (ok) { CHECK(y == m[pos]); for (i = pos; i < mn - 1; i++) m[i] = m[i+1]; mn--; } }
            CHECK(d.n == mn); for (i = 0; i < mn; i++) CHECK(adGet(&d, i) == m[i]); } }
    /* P57 against an O(nk) DP */
    { int a[] = {1,-1,-2,4,-7,3}, b[] = {10,-5,-2,4,0,3}, c[] = {1,-5,-20,4,-1,3,-6,-3};
      CHECK(maxResult(a,6,2)==7 && maxResult(b,6,3)==17 && maxResult(c,8,2)==0); }
    for (it = 0; it < 3000; it++) { int n = 1 + rnd(30), k = 1 + rnd(10), a[30], bst[30], j;
        for (i = 0; i < n; i++) a[i] = rnd(21) - 10;
        bst[0] = a[0];
        for (i = 1; i < n; i++) { int mx = bst[i-1]; for (j = i - k; j < i; j++) if (j >= 0 && bst[j] > mx) mx = bst[j]; bst[i] = a[i] + mx; }
        CHECK(maxResult(a, n, k) == bst[n-1]); }
    DONE();
}
