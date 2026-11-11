#include "../lib/stackqueue.h"
#include "../lib/testutil.h"
#include "../sol/p32.cpp"
#include "../sol/p33.cpp"
#include "../sol/p34.cpp"
#include "../sol/p35.cpp"
#include "../sol/p36.cpp"
#include "../sol/p37.cpp"
#include "../sol/p38.cpp"
#include "../sol/p39.cpp"
#include "../sol/p40.cpp"
#include "../sol/p41.cpp"
#include "../sol/p42.cpp"

/* brute-force balanced test: repeatedly delete "()", "[]", "{}" */
int balancedSlow(const char *s) {
    char b[64]; int changed = 1, i, n; strcpy(b, s);
    while (changed) { changed = 0; n = (int)strlen(b);
        for (i = 0; i + 1 < n; i++) if ((b[i]=='('&&b[i+1]==')')||(b[i]=='['&&b[i+1]==']')||(b[i]=='{'&&b[i+1]=='}')) {
            memmove(b + i, b + i + 2, n - i - 1); changed = 1; break; } }
    return b[0] == 0;
}
/* recursive-descent reference for infix evaluation (left assoc, int division) */
const char *gp;
int expr(void); int term(void);
int factor(void) { if (*gp == '(') { int v; gp++; v = expr(); gp++; return v; } return *gp++ - '0'; }
int term(void) { int v = factor(); while (*gp == '*' || *gp == '/') { char o = *gp++; int w = factor(); v = (o == '*') ? v * w : v / w; } return v; }
int expr(void) { int v = term(); while (*gp == '+' || *gp == '-') { char o = *gp++; int w = term(); v = (o == '+') ? v + w : v - w; } return v; }
int genExpr(char *s, int depth) {   /* writes a random valid infix expression with no division by zero risk */
    int n = 0, parts = 1 + rnd(3), i;
    for (i = 0; i < parts; i++) {
        if (i) s[n++] = "+-*"[rnd(3)];
        if (depth > 0 && rnd(3) == 0) { s[n++] = '('; n += genExpr(s + n, depth - 1); s[n++] = ')'; }
        else s[n++] = (char)('0' + rnd(10));
    }
    s[n] = 0; return n;
}

int main(void) {
    char out[2000]; int it, i;
    /* the library Stack and Queue against stack<int> / queue<int> */
    for (it = 0; it < 300; it++) {
        Stack s; stack<int> rs; Queue q; queue<int> rq;
        for (int op = 0; op < 300; op++) {
            int x = rnd(100);
            if (rnd(2) && rs.size() < 100) { s.push(x); rs.push(x); q.push(x); rq.push(x); }
            else if (!rs.empty()) { s.pop(); rs.pop(); q.pop(); rq.pop(); }
            CHECK(s.size() == (int)rs.size() && s.empty() == rs.empty());
            CHECK(q.size() == (int)rq.size() && q.empty() == rq.empty());
            if (!rs.empty()) CHECK(s.top() == rs.top() && q.front() == rq.front() && q.back() == rq.back());
        }
    }
    /* P32 */
    CHECK(isBalanced("{[()]}") && !isBalanced("([)]") && !isBalanced("((") && !isBalanced("))"));
    CHECK(isBalanced("") && isBalanced("()[]{}"));
    for (it = 0; it < 5000; it++) { char s[20]; int n = rnd(10);
        for (i = 0; i < n; i++) s[i] = "()[]{}"[rnd(6)]; s[n] = 0;
        CHECK(isBalanced(s) == balancedSlow(s)); }
    /* P33 */
    toPostfix("2+3*4", out); CHECK(strcmp(out, "234*+") == 0);
    toPostfix("(2+3)*4", out); CHECK(strcmp(out, "23+4*") == 0);
    toPostfix("8-3-2", out); CHECK(strcmp(out, "83-2-") == 0);
    toPostfix("8/(4/2)", out); CHECK(strcmp(out, "842//") == 0);
    CHECK(evalPostfix("234*+") == 14 && evalPostfix("83-2-") == 3);
    for (it = 0; it < 5000; it++) { char s[200]; genExpr(s, 3); toPostfix(s, out); gp = s;
        CHECK(evalPostfix(out) == expr()); }
    /* P34 */
    { MinStack m; m.push(5); m.push(3); m.push(7); m.push(3); m.push(1);
      CHECK(m.getMin()==1); m.pop(); CHECK(m.getMin()==3);
      m.pop(); m.pop(); CHECK(m.getMin()==3 && m.top()==3); m.pop(); CHECK(m.getMin()==5);
      m.pop(); CHECK(m.empty()); }
    /* P35, P36 against brute force */
    { int a[] = {2,1,5,3}, o[4]; nextGreater(a,4,o); CHECK(o[0]==5 && o[1]==5 && o[2]==-1 && o[3]==-1);
      int t[] = {73,74,75,71,69,72,76,73}, w[8], e[] = {1,1,4,2,1,1,0,0}; dailyTemperatures(t,8,w);
      for (i = 0; i < 8; i++) CHECK(w[i] == e[i]); }
    for (it = 0; it < 3000; it++) { int n = 1 + rnd(20), a[20], o[20], w[20], j, k;
        for (i = 0; i < n; i++) a[i] = rnd(6);
        nextGreater(a, n, o); dailyTemperatures(a, n, w);
        for (i = 0; i < n; i++) { k = -1; for (j = i + 1; j < n; j++) if (a[j] > a[i]) { k = j; break; }
            CHECK(o[i] == (k < 0 ? -1 : a[k]) && w[i] == (k < 0 ? 0 : k - i)); } }
    /* P37 */
    { StockSpanner s; int p[] = {100,80,60,70,60,75,85}, e[] = {1,1,1,2,1,4,6};
      for (i = 0; i < 7; i++) CHECK(s.next(p[i]) == e[i]); }
    for (it = 0; it < 2000; it++) { StockSpanner s; int n = 1 + rnd(30), p[30], j;
        for (i = 0; i < n; i++) { p[i] = rnd(10); for (j = i; j >= 0 && p[j] <= p[i]; j--) {}
            CHECK(s.next(p[i]) == i - j); } }
    /* P38 */
    { int a[] = {5,10,-5}, o[3]; CHECK(asteroidCollision(a,3,o)==2 && o[0]==5 && o[1]==10);
      int b[] = {8,-8}; CHECK(asteroidCollision(b,2,o)==0);
      int c[] = {10,2,-5}; CHECK(asteroidCollision(c,3,o)==1 && o[0]==10);
      int d[] = {-2,-1,1,2}; CHECK(asteroidCollision(d,4,o)==4 && o[0]==-2 && o[3]==2); }
    for (it = 0; it < 3000; it++) {          /* simulate collisions pairwise until stable */
        int n = 1 + rnd(10), a[10], b[10], m, o[10], changed = 1;
        for (i = 0; i < n; i++) { a[i] = 1 + rnd(4); if (rnd(2)) a[i] = -a[i]; b[i] = a[i]; }
        m = n;
        while (changed) { changed = 0;
            for (i = 0; i + 1 < m; i++) if (b[i] > 0 && b[i+1] < 0) {
                int l = b[i], r = -b[i+1];
                if (l == r) { memmove(b + i, b + i + 2, (m - i - 2) * sizeof(int)); m -= 2; }
                else if (l > r) { memmove(b + i + 1, b + i + 2, (m - i - 2) * sizeof(int)); m--; }
                else { memmove(b + i, b + i + 1, (m - i - 1) * sizeof(int)); m--; }
                changed = 1; break; } }
        CHECK(asteroidCollision(a, n, o) == m);
        for (i = 0; i < m; i++) CHECK(o[i] == b[i]); }
    /* P39 */
    decodeString("3[a]2[bc]", out); CHECK(strcmp(out, "aaabcbc") == 0);
    decodeString("3[a2[c]]", out); CHECK(strcmp(out, "accaccacc") == 0);
    decodeString("2[abc]3[cd]ef", out); CHECK(strcmp(out, "abcabccdcdcdef") == 0);
    decodeString("10[a]", out); CHECK(strcmp(out, "aaaaaaaaaa") == 0);
    decodeString("abc", out); CHECK(strcmp(out, "abc") == 0);
    /* P40 */
    removeAdjacent("abbaca", out); CHECK(strcmp(out, "ca") == 0);
    removeAdjacent("azxxzy", out); CHECK(strcmp(out, "ay") == 0);
    removeAdjacent("aaaa", out); CHECK(strcmp(out, "") == 0);
    removeAdjacent("abc", out); CHECK(strcmp(out, "abc") == 0);
    /* P41 */
    for (it = 0; it < 1000; it++) { stack<int> s; int n = rnd(30), prev = -1;
        for (i = 0; i < n; i++) s.push(rnd(10));
        s = sortStack(s); CHECK((int)s.size() == n);
        while (!s.empty()) { CHECK(s.top() >= prev); prev = s.top(); s.pop(); } }
    /* P42: compare with brute force over all pop sequences of 1..n */
    { int pu[] = {1,2,3,4,5}, a[] = {4,5,3,2,1}, b[] = {4,3,5,1,2};
      CHECK(validateStackSequences(pu,a,5)==1 && validateStackSequences(pu,b,5)==0); }
    { int n, perm[6], pu[6], cnt; for (n = 1; n <= 6; n++) { int total = 1, idx, ok;
        for (i = 0; i < n; i++) { pu[i] = i + 1; total *= (i + 1); }
        cnt = 0;
        for (idx = 0; idx < total; idx++) {      /* idx-th permutation (factorial number system) */
            int used[7] = {0}, r = idx, f, j, c;
            for (i = 0; i < n; i++) { f = 1; for (j = 1; j < n - i; j++) f *= j;
                c = r / f; r %= f;
                for (j = 1; j <= n; j++) if (!used[j] && c-- == 0) { perm[i] = j; used[j] = 1; break; } }
            ok = validateStackSequences(pu, perm, n); cnt += ok;
            /* a pop sequence is valid iff it has no pattern c..a..b with a < b < c */
            { int bad = 0, p, q, r2; for (p = 0; p < n; p++) for (q = p+1; q < n; q++) for (r2 = q+1; r2 < n; r2++)
                if (perm[q] < perm[r2] && perm[r2] < perm[p]) bad = 1;
              CHECK(ok == !bad); } }
        { int catalan[] = {1,1,2,5,14,42,132}; CHECK(cnt == catalan[n]); } } }
    DONE();
}
