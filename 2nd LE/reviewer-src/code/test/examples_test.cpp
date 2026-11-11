/* Checks every sample-test row of Problems 33-57 that the other tests do not. */
#include "../sol/p33.cpp"
#include "../sol/p34.cpp"
#include "../sol/p36.cpp"
#include "../sol/p37.cpp"
#include "../sol/p40.cpp"
#include "../sol/p41.cpp"
#include "../sol/p42.cpp"
#include "../sol/p43.cpp"
#include "../sol/p44.cpp"
#include "../sol/p45.cpp"
#include "../sol/p46.cpp"
#include "../sol/p47.cpp"
#include "../sol/p48.cpp"
#include "../sol/p49.cpp"
#include "../sol/p50.cpp"
#include "../sol/p51.cpp"
#include "../sol/p52.cpp"
#include "../sol/p53.cpp"
#include "../sol/p55.cpp"
#include "../sol/p56.cpp"
#include "../sol/p57.cpp"

int same(int a[], int b[], int n) {
    for (int i = 0; i < n; i++) if (a[i] != b[i]) return 0;
    return 1;
}

/* the queue from front to back equals e[0..n-1] (q is a copy) */
int qIs(queue<int> q, int e[], int n) {
    int ok = (int)q.size() == n;
    for (int i = 0; !q.empty(); i++) {
        if (i < n && q.front() != e[i]) ok = 0;
        q.pop();
    }
    return ok;
}

queue<int> range(int from, int to, int step) {
    queue<int> q;
    for (int i = from; i <= to; i++) q.push(i * step);
    return q;
}

int main(void) {
    char out[200];
    int o[20];

    /* P33 */
    char *in[] = {"2+3*4", "(2+3)*4", "2*(3+4)-5", "8-3-2", "9-8/(4-2)"};
    char *pf[] = {"234*+", "23+4*", "234+*5-", "83-2-", "9842-/-"};
    int val[] = {14, 20, 9, 3, 5};
    for (int i = 0; i < 5; i++) {
        toPostfix(in[i], out);
        CHECK(strcmp(out, pf[i]) == 0);
        CHECK(evalPostfix(out) == val[i]);
    }

    /* P34 */
    { MinStack m;
      CHECK(m.empty());
      m.push(5); m.push(3); m.push(7); m.push(3); m.push(1);
      CHECK(m.getMin() == 1);
      m.pop(); m.pop(); CHECK(m.getMin() == 3);
      m.push(2); CHECK(m.getMin() == 2);
      m.pop(); CHECK(m.getMin() == 3); }

    /* P36 */
    { int t1[] = {30,40,50,60}, e1[] = {1,1,1,0}; dailyTemperatures(t1, 4, o); CHECK(same(o, e1, 4));
      int t2[] = {30,60,90}, e2[] = {1,1,0};      dailyTemperatures(t2, 3, o); CHECK(same(o, e2, 3));
      int t3[] = {50,50}, e3[] = {0,0};           dailyTemperatures(t3, 2, o); CHECK(same(o, e3, 2)); }

    /* P37 */
    { int p[] = {100,80,60,70,60,75,85}, e[] = {1,1,1,2,1,4,6};
      StockSpanner s;
      for (int i = 0; i < 7; i++) CHECK(s.next(p[i]) == e[i]);
      StockSpanner s2; CHECK(s2.next(10)==1 && s2.next(10)==2 && s2.next(10)==3);
      StockSpanner s3; for (int i = 5; i >= 1; i--) CHECK(s3.next(i) == 1); }

    /* P40 */
    removeAdjacent("abbaca", out); CHECK(strcmp(out, "ca") == 0);
    removeAdjacent("azxxzy", out); CHECK(strcmp(out, "ay") == 0);
    removeAdjacent("aa", out); CHECK(strcmp(out, "") == 0);
    removeAdjacent("abc", out); CHECK(strcmp(out, "abc") == 0);

    /* P41 */
    { stack<int> s; int v[] = {3,1,4,1,5}, e[] = {1,1,3,4,5};
      for (int i = 0; i < 5; i++) s.push(v[i]);
      s = sortStack(s);
      for (int i = 0; i < 5; i++) { CHECK(s.top() == e[i]); s.pop(); }
      CHECK(s.empty());
      s = sortStack(s); CHECK(s.empty()); }

    /* P42 */
    { int pu[] = {2,1,0}, po[] = {1,2,0}; CHECK(validateStackSequences(pu, po, 3) == 1); }

    /* P43 */
    { MyQueue q;
      q.push(1); q.push(2);
      CHECK(q.front() == 1);
      q.pop(); CHECK(q.empty() == false);
      q.push(3);
      CHECK(q.front() == 2); q.pop();
      CHECK(q.front() == 3); q.pop();
      CHECK(q.empty()); }

    /* P44 */
    { MyStack s;
      s.push(1); s.push(2);
      CHECK(s.top() == 2); s.pop(); CHECK(s.empty() == false);
      CHECK(s.top() == 1); s.pop(); CHECK(s.empty());
      s.push(1); s.push(2); s.push(3);
      CHECK(s.top() == 3); s.pop(); s.push(4);
      CHECK(s.top() == 4); s.pop(); CHECK(s.top() == 2); }

    /* P45 */
    CHECK(josephus(1, 5) == 1);

    /* P46 */
    { int e1[] = {3,2,1,4,5}, e2[] = {5,4,3,2,1}, e3[] = {1,2,3,4,5};
      int e4[] = {50,40,30,20,10,60,70,80,90,100};
      CHECK(qIs(reverseFirstK(range(1, 5, 1), 3), e1, 5));
      CHECK(qIs(reverseFirstK(range(1, 5, 1), 5), e2, 5));
      CHECK(qIs(reverseFirstK(range(1, 5, 1), 0), e3, 5));
      CHECK(qIs(reverseFirstK(range(1, 10, 10), 5), e4, 10)); }

    /* P47 */
    { RecentCounter r;
      CHECK(r.ping(1) == 1 && r.ping(5000) == 1 && r.ping(5001) == 2); }

    /* P48 */
    { int e1[] = {1,5,2,6,3,7,4,8}, e2[] = {11,16,12,17,13,18,14,19,15,20}, e3[] = {1,2};
      CHECK(qIs(interleaveHalves(range(1, 8, 1)), e1, 8));
      CHECK(qIs(interleaveHalves(range(11, 20, 1)), e2, 10));
      CHECK(qIs(interleaveHalves(range(1, 2, 1)), e3, 2)); }

    /* P49 */
    { int a[] = {-8,2,3,-6,10}, e[] = {-8,0,-6,-6}; CHECK(firstNegatives(a, 5, 2, o) == 4 && same(o, e, 4));
      int b[] = {1,2,3}; CHECK(firstNegatives(b, 3, 3, o) == 1 && o[0] == 0); }

    /* P50 */
    { CircularDeque d(3);
      CHECK(d.insertLast(1) && d.insertLast(2) && d.insertFront(3) && !d.insertFront(4));
      CHECK(d.getRear() == 2 && d.isFull() && d.deleteLast() && d.insertFront(4) && d.getFront() == 4);
      CircularDeque e(1);
      CHECK(e.getFront() == -1 && e.insertFront(7) && !e.insertLast(8) && e.getRear() == 7); }

    /* P51 */
    { LinkedDeque d;
      d.push_back(1); d.push_back(2); d.push_front(0);
      CHECK(d.sentinel->next->item == 0 && d.sentinel->next->next->item == 1 && d.sentinel->prev->item == 2);
      CHECK(d.back() == 2); d.pop_back();
      CHECK(d.front() == 0); d.pop_front();
      CHECK(d.front() == 1 && d.back() == 1);
      d.pop_back(); CHECK(d.empty());
      d.pop_back(); CHECK(d.empty() && d.size() == 0);
      d.clear(); }

    /* P52 */
    CHECK(isPalindromeText("A man, a plan, a canal: Panama") == 1 && isPalindromeText("race a car") == 0);

    /* P53 */
    { int a[] = {1,3,-1,-3,5,3,6,7}, e[] = {3,3,5,5,6,7}; CHECK(maxSlidingWindow(a,8,3,o)==6 && same(o,e,6));
      int b[] = {1}; CHECK(maxSlidingWindow(b,1,1,o)==1 && o[0]==1);
      int c[] = {9,1,8,2,7,3}, f[] = {9,8,8,7,7}; CHECK(maxSlidingWindow(c,6,2,o)==5 && same(o,f,5));
      int g[] = {4,2,12,3,8,8,1,5}, h[] = {12,12,12,8,8,8}; CHECK(maxSlidingWindow(g,8,3,o)==6 && same(o,h,6)); }

    /* P55 */
    { FrontMiddleBackQueue q;
      q.pushFront(1); q.pushBack(2); q.pushMiddle(3); q.pushMiddle(4);
      CHECK(q.popFront() == 1); CHECK(q.popMiddle() == 3); CHECK(q.popMiddle() == 4);
      CHECK(q.popBack() == 2); CHECK(q.popFront() == -1); }

    /* P56 */
    { ArrayDeque d;
      d.add(0,1); d.add(1,2); d.add(2,3); d.add(0,0);
      CHECK(d.size()==4 && d.get(0)==0 && d.get(1)==1 && d.get(2)==2 && d.get(3)==3);
      d.add(2,9);
      CHECK(d.size()==5 && d.get(2)==9 && d.get(3)==2 && d.get(4)==3);
      CHECK(d.remove(1)==1 && d.get(1)==9 && d.get(2)==2);
      CHECK(d.add(5,7)==false);
      CHECK(d.remove(3)==3 && d.size()==3 && d.get(0)==0 && d.get(1)==9 && d.get(2)==2); }

    /* P57 */
    { int a[] = {1,-1,-2,4,-7,3}; CHECK(maxResult(a,6,2) == 7); }

    DONE();
}
