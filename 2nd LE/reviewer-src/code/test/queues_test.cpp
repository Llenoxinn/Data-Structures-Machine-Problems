#include "../lib/testutil.h"
#include "../sol/p43.cpp"
#include "../sol/p44.cpp"
#include "../sol/p45.cpp"
#include "../sol/p46.cpp"
#include "../sol/p47.cpp"
#include "../sol/p48.cpp"
#include "../sol/p49.cpp"

int main(void) {
    int it, i, x;
    /* P43 / P44 against an array model */
    for (it = 0; it < 500; it++) {
        MyQueue q; MyStack s; int model[200], h = 0, t = 0, st[200], top = 0, op;
        for (op = 0; op < 100; op++) {
            if (rnd(2)) { x = rnd(100); q.push(x); model[t++] = x; s.push(x); st[top++] = x; }
            else {
                if (h < t) { CHECK(q.front() == model[h]); q.pop(); h++; }
                if (top > 0) { CHECK(s.top() == st[top - 1]); s.pop(); top--; }
            }
            CHECK(q.empty() == (h == t) && s.empty() == (top == 0));
            if (h < t) CHECK(q.front() == model[h]);
            if (top > 0) CHECK(s.top() == st[top - 1]);
        }
    }
    /* P45 */
    CHECK(josephus(5,2)==3 && josephus(7,3)==4 && josephus(6,3)==1 && josephus(10,2)==5 && josephus(41,3)==31);
    for (i = 1; i <= 60; i++) { int k; for (k = 1; k <= 7; k++) CHECK(josephus(i, k) == josephusFast(i, k)); }
    /* P46 */
    for (it = 0; it < 500; it++) { queue<int> q; int n = rnd(12), k = rnd(n + 1), e[12];
        for (i = 0; i < n; i++) { q.push(i); e[i] = (i < k) ? k - 1 - i : i; }
        q = reverseFirstK(q, k);
        for (i = 0; i < n; i++) { CHECK(q.front() == e[i]); q.pop(); } CHECK(q.empty()); }
    /* P47 */
    { RecentCounter r; CHECK(r.ping(1)==1 && r.ping(100)==2 && r.ping(3001)==3 && r.ping(3002)==3); }
    for (it = 0; it < 300; it++) { RecentCounter r; int tm[60], n = 1 + rnd(60), j, c;
        for (i = 0; i < n; i++) { tm[i] = (i ? tm[i-1] : 0) + 1 + rnd(400);
            for (c = 0, j = 0; j <= i; j++) if (tm[j] >= tm[i] - 3000) c++;
            CHECK(r.ping(tm[i]) == c); } }
    /* P48 */
    for (it = 1; it <= 20; it++) { queue<int> q; int n = 2 * (it % 7);
        for (i = 0; i < n; i++) q.push(i + 1);
        q = interleaveHalves(q);
        for (i = 0; i < n; i++) { CHECK(q.front() == ((i % 2 == 0) ? i / 2 + 1 : n / 2 + i / 2 + 1)); q.pop(); } }
    /* P49 */
    { int a[] = {12,-1,-7,8,-15,30,16,28}, o[8], e[] = {-1,-1,-7,-15,-15,0};
      CHECK(firstNegatives(a,8,3,o)==6); for (i = 0; i < 6; i++) CHECK(o[i]==e[i]); }
    for (it = 0; it < 2000; it++) { int n = 1 + rnd(20), k = 1 + rnd(n), a[20], o[20], j, m;
        for (i = 0; i < n; i++) a[i] = rnd(7) - 3;
        m = firstNegatives(a, n, k, o); CHECK(m == n - k + 1);
        for (i = 0; i < m; i++) { int f = 0; for (j = i; j < i + k; j++) if (a[j] < 0) { f = a[j]; break; }
            CHECK(o[i] == f); } }
    DONE();
}
