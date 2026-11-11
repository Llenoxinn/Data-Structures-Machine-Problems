#include "../lib/deque.h"
#include "../lib/testutil.h"
#include "../sol/p50.cpp"
#include "../sol/p51.cpp"
#include "../sol/p52.cpp"
#include "../sol/p53.cpp"
#include "../sol/p54.cpp"
#include "../sol/p55.cpp"
#include "../sol/p56.cpp"
#include "../sol/p57.cpp"

/* array model of a deque: m[0..n-1] */
int m[400], mn;
void mPushF(int x) { int i; for (i = mn; i > 0; i--) m[i] = m[i-1]; m[0] = x; mn++; }
void mPopF(void) { int i; for (i = 0; i < mn - 1; i++) m[i] = m[i+1]; mn--; }

int main(void) {
    int it, i, x, op;
    /* the library Deque, P50 and P51 against the model, with wrap-around */
    for (it = 0; it < 300; it++) {
        int cap = 1 + rnd(8);
        Deque d; CircularDeque c(cap); LinkedDeque l; mn = 0;
        for (op = 0; op < 300; op++) {
            int r = rnd(4); x = rnd(100);
            if (r == 0) { bool ok = (mn < cap); CHECK(c.insertFront(x) == ok);
                          if (ok) { mPushF(x); d.push_front(x); l.push_front(x); } }
            else if (r == 1) { bool ok = (mn < cap); CHECK(c.insertLast(x) == ok);
                          if (ok) { m[mn++] = x; d.push_back(x); l.push_back(x); } }
            else if (r == 2) { bool ok = mn > 0; CHECK(c.deleteFront() == ok);
                          if (ok) { CHECK(d.front() == m[0] && l.front() == m[0]); mPopF(); }
                          d.pop_front(); l.pop_front(); }
            else { bool ok = mn > 0; CHECK(c.deleteLast() == ok);
                          if (ok) { CHECK(d.back() == m[mn-1] && l.back() == m[mn-1]); mn--; }
                          d.pop_back(); l.pop_back(); }
            CHECK(c.isEmpty() == (mn == 0) && c.isFull() == (mn == cap) && d.size() == mn && l.size() == mn);
            CHECK(c.getFront() == (mn ? m[0] : -1) && c.getRear() == (mn ? m[mn-1] : -1));
            if (mn) { CHECK(d.front() == m[0] && d.back() == m[mn-1]);
                      CHECK(l.front() == m[0] && l.back() == m[mn-1]); }
        }
        l.clear();
        CHECK(l.sentinel->next == l.sentinel && l.sentinel->prev == l.sentinel);
        delete l.sentinel;
    }
    { CircularDeque c(3);           /* LeetCode 641 sample */
      CHECK(c.insertLast(1) && c.insertLast(2) && c.insertFront(3) && !c.insertFront(4));
      CHECK(c.getRear()==2 && c.isFull() && c.deleteLast() && c.insertFront(4) && c.getFront()==4); }
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
    { FrontMiddleBackQueue q;                  /* LeetCode 1670 sample */
      q.pushFront(1); q.pushBack(2); q.pushMiddle(3); q.pushMiddle(4);
      CHECK(q.popFront()==1 && q.popMiddle()==3 && q.popMiddle()==4 && q.popBack()==2 && q.popFront()==-1); }
    for (it = 0; it < 300; it++) { FrontMiddleBackQueue q; mn = 0;
        for (op = 0; op < 120; op++) { int r = rnd(6), pos; x = rnd(100);
            if (r == 0 && mn < 90) { q.pushFront(x); mPushF(x); }
            else if (r == 1 && mn < 90) { q.pushBack(x); m[mn++] = x; }
            else if (r == 2 && mn < 90) { q.pushMiddle(x); pos = mn / 2;
                for (i = mn; i > pos; i--) m[i] = m[i-1]; m[pos] = x; mn++; }
            else if (r == 3) { x = q.popFront(); CHECK(x == (mn ? m[0] : -1)); if (mn) mPopF(); }
            else if (r == 4) { x = q.popBack(); CHECK(x == (mn ? m[mn-1] : -1)); if (mn) mn--; }
            else { x = q.popMiddle(); if (!mn) CHECK(x == -1); else { pos = (mn - 1) / 2; CHECK(x == m[pos]);
                for (i = pos; i < mn - 1; i++) m[i] = m[i+1]; mn--; } } } }
    /* P56 against the model */
    for (it = 0; it < 300; it++) { ArrayDeque d; mn = 0;
        for (op = 0; op < 200; op++) { int pos = rnd(mn + 2) - (rnd(9) == 0); x = rnd(100);
            if (rnd(2)) { bool ok = (pos >= 0 && pos <= mn && mn < 100); CHECK(d.add(pos, x) == ok);
                if (ok) { for (i = mn; i > pos; i--) m[i] = m[i-1]; m[pos] = x; mn++; } }
            else { bool ok = (pos >= 0 && pos < mn); int y = d.remove(pos);
                if (ok) { CHECK(y == m[pos]); for (i = pos; i < mn - 1; i++) m[i] = m[i+1]; mn--; }
                else CHECK(y == -1); }
            CHECK(d.size() == mn); for (i = 0; i < mn; i++) CHECK(d.get(i) == m[i]); } }
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
