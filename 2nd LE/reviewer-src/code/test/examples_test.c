/* Checks every sample-test row of Problems 33-57 that the other tests do not. */
#include "../lib/stackqueue.h"
#include "../lib/deque.h"
#include "../sol/p33.c"
#include "../sol/p34.c"
#include "../sol/p36.c"
#include "../sol/p37.c"
#include "../sol/p40.c"
#include "../sol/p41.c"
#include "../sol/p42.c"
#include "../sol/p43.c"
#include "../sol/p44.c"
#include "../sol/p45.c"
#include "../sol/p46.c"
#include "../sol/p47.c"
#include "../sol/p48.c"
#include "../sol/p49.c"
#include "../sol/p50.c"
#include "../sol/p51.c"
#include "../sol/p52.c"
#include "../sol/p53.c"
#include "../sol/p55.c"
#include "../sol/p56.c"
#include "../sol/p57.c"

int same(int a[], int b[], int n) {
    for (int i = 0; i < n; i++) if (a[i] != b[i]) return 0;
    return 1;
}

/* the queue from front to back equals e[0..n-1] (queue is left unchanged) */
int qIs(queue *q, int e[], int n) {
    int ok = qSize(q) == n, x;
    for (int i = 0; i < qSize(q); i++) {
        qDeq(q, &x);
        if (i < n && x != e[i]) ok = 0;
        qEnq(q, x);
    }
    return ok;
}

int main(void) {
    char out[200];
    int x, o[20];

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
    { minStack m; msInit(&m);
      CHECK(msMin(&m, &x) == 0);
      msPush(&m, 5); msPush(&m, 3); msPush(&m, 7); msPush(&m, 3); msPush(&m, 1);
      CHECK(msMin(&m, &x) && x == 1);
      msPop(&m, &x); msPop(&m, &x); CHECK(msMin(&m, &x) && x == 3);
      msPush(&m, 2); CHECK(msMin(&m, &x) && x == 2);
      msPop(&m, &x); CHECK(msMin(&m, &x) && x == 3); }

    /* P36 */
    { int t1[] = {30,40,50,60}, e1[] = {1,1,1,0}; dailyTemperatures(t1, 4, o); CHECK(same(o, e1, 4));
      int t2[] = {30,60,90}, e2[] = {1,1,0};      dailyTemperatures(t2, 3, o); CHECK(same(o, e2, 3));
      int t3[] = {50,50}, e3[] = {0,0};           dailyTemperatures(t3, 2, o); CHECK(same(o, e3, 2)); }

    /* P37 */
    { int p[] = {100,80,60,70,60,75,85}, e[] = {1,1,1,2,1,4,6};
      stockSpanner s; ssInit(&s);
      for (int i = 0; i < 7; i++) CHECK(ssNext(&s, p[i]) == e[i]);
      ssInit(&s); CHECK(ssNext(&s,10)==1 && ssNext(&s,10)==2 && ssNext(&s,10)==3);
      ssInit(&s); for (int i = 5; i >= 1; i--) CHECK(ssNext(&s, i) == 1); }

    /* P40 */
    removeAdjacent("abbaca", out); CHECK(strcmp(out, "ca") == 0);
    removeAdjacent("azxxzy", out); CHECK(strcmp(out, "ay") == 0);
    removeAdjacent("aa", out); CHECK(strcmp(out, "") == 0);
    removeAdjacent("abc", out); CHECK(strcmp(out, "abc") == 0);

    /* P41 */
    { stack s; int v[] = {3,1,4,1,5}, e[] = {1,1,3,4,5}; stInit(&s);
      for (int i = 0; i < 5; i++) stPush(&s, v[i]);
      sortStack(&s);
      for (int i = 0; i < 5; i++) { CHECK(stPop(&s, &x) && x == e[i]); }
      CHECK(stEmpty(&s));
      sortStack(&s); CHECK(stEmpty(&s)); }

    /* P42 */
    { int pu[] = {2,1,0}, po[] = {1,2,0}; CHECK(validateStackSequences(pu, po, 3) == 1); }

    /* P43 */
    { twoStackQueue q; tsqInit(&q);
      tsqPush(&q, 1); tsqPush(&q, 2);
      CHECK(tsqPeek(&q, &x) && x == 1);
      CHECK(tsqPop(&q, &x) && x == 1);
      CHECK(tsqEmpty(&q) == 0);
      tsqPush(&q, 3);
      CHECK(tsqPop(&q, &x) && x == 2);
      CHECK(tsqPop(&q, &x) && x == 3);
      CHECK(tsqPop(&q, &x) == 0); }

    /* P44 */
    { queueStack s; qsInit(&s);
      qsPush(&s, 1); qsPush(&s, 2);
      CHECK(qsTop(&s, &x) && x == 2); CHECK(qsPop(&s, &x) && x == 2); CHECK(qsEmpty(&s) == 0);
      CHECK(qsPop(&s, &x) && x == 1); CHECK(qsEmpty(&s) == 1);
      qsPush(&s, 1); qsPush(&s, 2); qsPush(&s, 3);
      CHECK(qsPop(&s, &x) && x == 3); qsPush(&s, 4);
      CHECK(qsPop(&s, &x) && x == 4); CHECK(qsPop(&s, &x) && x == 2); }

    /* P45 */
    CHECK(josephus(1, 5) == 1);

    /* P46 */
    { queue q; int e1[] = {3,2,1,4,5}, e2[] = {5,4,3,2,1}, e3[] = {1,2,3,4,5};
      int e4[] = {50,40,30,20,10,60,70,80,90,100};
      qInit(&q); for (int i = 1; i <= 5; i++) qEnq(&q, i); reverseFirstK(&q, 3); CHECK(qIs(&q, e1, 5));
      qInit(&q); for (int i = 1; i <= 5; i++) qEnq(&q, i); reverseFirstK(&q, 5); CHECK(qIs(&q, e2, 5));
      qInit(&q); for (int i = 1; i <= 5; i++) qEnq(&q, i); reverseFirstK(&q, 0); CHECK(qIs(&q, e3, 5));
      qInit(&q); for (int i = 1; i <= 10; i++) qEnq(&q, 10 * i); reverseFirstK(&q, 5); CHECK(qIs(&q, e4, 10)); }

    /* P47 */
    { recentCounter r; rcInit(&r);
      CHECK(rcPing(&r, 1) == 1 && rcPing(&r, 5000) == 1 && rcPing(&r, 5001) == 2); }

    /* P48 */
    { queue q; int e1[] = {1,5,2,6,3,7,4,8}, e2[] = {11,16,12,17,13,18,14,19,15,20}, e3[] = {1,2};
      qInit(&q); for (int i = 1; i <= 8; i++) qEnq(&q, i); interleaveHalves(&q); CHECK(qIs(&q, e1, 8));
      qInit(&q); for (int i = 11; i <= 20; i++) qEnq(&q, i); interleaveHalves(&q); CHECK(qIs(&q, e2, 10));
      qInit(&q); qEnq(&q, 1); qEnq(&q, 2); interleaveHalves(&q); CHECK(qIs(&q, e3, 2)); }

    /* P49 */
    { int a[] = {-8,2,3,-6,10}, e[] = {-8,0,-6,-6}; CHECK(firstNegatives(a, 5, 2, o) == 4 && same(o, e, 4));
      int b[] = {1,2,3}; CHECK(firstNegatives(b, 3, 3, o) == 1 && o[0] == 0); }

    /* P50 */
    { circularDeque d; cdInit(&d, 3);
      CHECK(cdInsertLast(&d,1)==1 && cdInsertLast(&d,2)==1 && cdInsertFront(&d,3)==1 && cdInsertFront(&d,4)==0);
      CHECK(cdGetRear(&d)==2 && cdIsFull(&d)==1 && cdDeleteLast(&d)==1 && cdInsertFront(&d,4)==1 && cdGetFront(&d)==4);
      cdInit(&d, 1);
      CHECK(cdGetFront(&d)==-1 && cdInsertFront(&d,7)==1 && cdInsertLast(&d,8)==0 && cdGetRear(&d)==7); }

    /* P51 */
    { linkedDeque d; ldInit(&d);
      ldPushBack(&d, 1); ldPushBack(&d, 2); ldPushFront(&d, 0);
      CHECK(d.sentinel.next->item == 0 && d.sentinel.next->next->item == 1 && d.sentinel.prev->item == 2);
      CHECK(ldPopBack(&d, &x) && x == 2); CHECK(ldPopFront(&d, &x) && x == 0);
      CHECK(ldFront(&d, &x) && x == 1); CHECK(ldBack(&d, &x) && x == 1);
      CHECK(ldPopBack(&d, &x) && x == 1); CHECK(ldPopBack(&d, &x) == 0);
      ldFree(&d); }

    /* P53 */
    { int a[] = {1,3,-1,-3,5,3,6,7}, e[] = {3,3,5,5,6,7}; CHECK(maxSlidingWindow(a,8,3,o)==6 && same(o,e,6));
      int b[] = {1}; CHECK(maxSlidingWindow(b,1,1,o)==1 && o[0]==1);
      int c[] = {9,1,8,2,7,3}, f[] = {9,8,8,7,7}; CHECK(maxSlidingWindow(c,6,2,o)==5 && same(o,f,5));
      int g[] = {4,2,12,3,8,8,1,5}, h[] = {12,12,12,8,8,8}; CHECK(maxSlidingWindow(g,8,3,o)==6 && same(o,h,6)); }

    /* P55 */
    { fmbQueue q; fmbInit(&q);
      fmbPushFront(&q, 1); fmbPushBack(&q, 2); fmbPushMiddle(&q, 3); fmbPushMiddle(&q, 4);
      CHECK(fmbPopFront(&q) == 1); CHECK(fmbPopMiddle(&q) == 3); CHECK(fmbPopMiddle(&q) == 4);
      CHECK(fmbPopBack(&q) == 2); CHECK(fmbPopFront(&q) == -1); }

    /* P56 */
    { arrayDeque d; adInit(&d);
      adAdd(&d,0,1); adAdd(&d,1,2); adAdd(&d,2,3); adAdd(&d,0,0);
      CHECK(d.n==4 && adGet(&d,0)==0 && adGet(&d,1)==1 && adGet(&d,2)==2 && adGet(&d,3)==3);
      adAdd(&d,2,9);
      CHECK(d.n==5 && adGet(&d,2)==9 && adGet(&d,3)==2 && adGet(&d,4)==3);
      CHECK(adRemove(&d,1,&x) && x==1 && adGet(&d,1)==9 && adGet(&d,2)==2);
      CHECK(adAdd(&d,5,7)==0);
      CHECK(adRemove(&d,3,&x) && x==3 && d.n==3 && adGet(&d,0)==0 && adGet(&d,1)==9 && adGet(&d,2)==2); }

    /* P57 */
    { int a[] = {1,-1,-2,4,-7,3}; CHECK(maxResult(a,6,2) == 7); }

    DONE();
}
