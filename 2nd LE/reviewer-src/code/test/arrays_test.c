#include "../lib/testutil.h"
#include "../sol/p01.c"
#include "../sol/p02.c"
#include "../sol/p03.c"
#include "../sol/p05.c"
#include "../sol/p06.c"
#include "../sol/p07.c"
#include "../sol/p08.c"
#include "../sol/p09.c"
#include "../sol/p10.c"
#include "../sol/p11.c"
#include "../sol/p12.c"

int sameArr(int a[], int b[], int n) { int i; for (i = 0; i < n; i++) if (a[i] != b[i]) return 0; return 1; }

int main(void) {
    char out[200], buf[200];
    int t, it;
    /* P1 */
    CHECK(rleEncode("aaabccdddd", out) == 8 && strcmp(out, "a3b1c2d4") == 0);
    CHECK(rleEncode("wwwwwwwwwwwwbbb", out) == 5 && strcmp(out, "w12b3") == 0);
    strcpy(buf, "aabcccccaaa"); t = compress(buf, 11); buf[t] = 0;
    CHECK(t == 7 && strcmp(buf, "a2bc5a3") == 0);
    strcpy(buf, "abbbbbbbbbbbb"); t = compress(buf, 13); buf[t] = 0;
    CHECK(t == 4 && strcmp(buf, "ab12") == 0);
    CHECK(rleDecode("x3y2z1", out) == 6 && strcmp(out, "xxxyyz") == 0);
    for (it = 0; it < 2000; it++) {          /* encode then decode is the identity */
        char s[120], e[260], d[130]; int n = 1 + rnd(100), i;
        for (i = 0; i < n; i++) s[i] = (char)('a' + rnd(3));
        s[n] = 0; rleEncode(s, e); rleDecode(e, d);
        CHECK(strcmp(s, d) == 0);
    }
    /* P2 */
    { int a[10][10] = {{1,2,3},{4,5,6}}, tt[10][10]; transpose(a, 2, 3, tt);
      CHECK(tt[0][0]==1 && tt[0][1]==4 && tt[1][0]==2 && tt[1][1]==5 && tt[2][0]==3 && tt[2][1]==6);
      int b[10][10] = {{1,2},{3,4}}; transposeInPlace(b, 2);
      CHECK(b[0][0]==1 && b[0][1]==3 && b[1][0]==2 && b[1][1]==4); }
    /* P3 */
    { int a1[] = {1,2,4,5,6,7}, a2[] = {1,2,3,4,5,6,8,9,10}, a3[] = {2}, a4[] = {1};
      CHECK(missingNumber(a1,6)==3 && missingNumber(a2,9)==7 && missingNumber(a3,1)==1 && missingNumber(a4,1)==2);
      CHECK(missingNumberFast(a1,6)==3 && missingNumberFast(a2,9)==7 && missingNumberFast(a3,1)==1 && missingNumberFast(a4,1)==2);
      for (it = 0; it < 2000; it++) { int m = 1 + rnd(50), miss = 1 + rnd(m + 1), a[60], k = 0, v;
        for (v = 1; v <= m + 1; v++) if (v != miss) a[k++] = v;
        CHECK(missingNumber(a, m) == miss && missingNumberFast(a, m) == miss); } }
    /* P5 */
    { int a[] = {1,2,3,4,5,6,7}, e[] = {5,6,7,1,2,3,4}; rotate(a,7,3); CHECK(sameArr(a,e,7));
      int b[] = {1,2}, eb[] = {2,1}; rotate(b,2,5); CHECK(sameArr(b,eb,2));
      int c[] = {1,2,3,4,5,6,7,8,9}, ec[] = {6,7,8,9,1,2,3,4,5}; rotate(c,9,4); CHECK(sameArr(c,ec,9));
      rotate(c, 0, 3);
      for (it = 0; it < 2000; it++) { int n = 1 + rnd(30), k = rnd(1000), x[30], y[30], i;
        for (i = 0; i < n; i++) x[i] = rnd(100);
        for (i = 0; i < n; i++) y[(i + k) % n] = x[i];
        rotate(x, n, k); CHECK(sameArr(x, y, n)); } }
    /* P6 */
    { int a[] = {1,3,5,7}, b[] = {2,3,6}, c[10], e[] = {1,2,3,3,5,6,7};
      CHECK(mergeArrays(a,4,b,3,c)==7 && sameArr(c,e,7));
      int d[] = {4,5}; CHECK(mergeArrays(a,0,d,2,c)==2 && c[0]==4 && c[1]==5);
      int f[] = {1,2}; CHECK(mergeArrays(f,2,d,0,c)==2 && c[0]==1 && c[1]==2); }
    /* P7 */
    { int a[] = {1,1,2,2,2,3,5,5}, e[] = {1,2,3,5}; CHECK(dedupSorted(a,8)==4 && sameArr(a,e,4));
      int b[] = {7}; CHECK(dedupSorted(b,1)==1); CHECK(dedupSorted(b,0)==0); }
    /* P8 */
    { int a[] = {1,3,4,6,8,11}, i, j; CHECK(twoSum(a,6,10,&i,&j)==1 && i==2 && j==3);
      CHECK(twoSum(a,6,20,&i,&j)==0); int b[] = {2,2}; CHECK(twoSum(b,2,4,&i,&j)==1 && i==0 && j==1);
      for (it = 0; it < 2000; it++) { int n = 2 + rnd(20), x[25], k, tg = rnd(60), exist = 0, p, q;
        x[0] = rnd(5); for (k = 1; k < n; k++) x[k] = x[k-1] + rnd(5);
        for (p = 0; p < n; p++) for (q = p + 1; q < n; q++) if (x[p] + x[q] == tg) exist = 1;
        k = twoSum(x, n, tg, &p, &q); CHECK(k == exist && (!k || (p < q && x[p] + x[q] == tg))); } }
    /* P9 */
    { int a[] = {-2,1,-3,4,-1,2,1,-5,4}, b[] = {-3,-1,-2}, c[] = {5};
      CHECK(maxSubarray(a,9)==6 && maxSubarray(b,3)==-1 && maxSubarray(c,1)==5);
      for (it = 0; it < 2000; it++) { int n = 1 + rnd(30), x[30], k;
        for (k = 0; k < n; k++) x[k] = rnd(21) - 10;
        CHECK(maxSubarray(x, n) == maxSubarraySlow(x, n)); } }
    /* P10 */
    { int a[] = {0,1,0,3,12}, e[] = {1,3,12,0,0}; moveZeroes(a,5); CHECK(sameArr(a,e,5));
      int b[] = {0,0}; moveZeroes(b,2); CHECK(b[0]==0 && b[1]==0);
      int c[] = {4,5}; moveZeroes(c,2); CHECK(c[0]==4 && c[1]==5); }
    /* P11 */
    { int a[] = {2,2,1,1,2,2,3,2,2}, b[] = {3,3,4}, c[] = {7};
      CHECK(majority(a,9)==2 && majority(b,3)==3 && majority(c,1)==7);
      for (it = 0; it < 2000; it++) { int n = 1 + rnd(30), x[30], k, m = rnd(5);
        for (k = 0; k < n; k++) x[k] = rnd(5);
        for (k = 0; k < n / 2 + 1; k++) x[rnd(n)] = m;     /* may or may not be a majority */
        if (majoritySlow(x, n) != -1) CHECK(majority(x, n) == majoritySlow(x, n)); } }
    /* P12 */
    { int a[10][10] = {{1,2},{3,4}}; rotate90(a,2); CHECK(a[0][0]==3 && a[0][1]==1 && a[1][0]==4 && a[1][1]==2);
      int b[10][10] = {{1,2,3},{4,5,6},{7,8,9}}; rotate90(b,3);
      CHECK(b[0][0]==7 && b[0][1]==4 && b[0][2]==1 && b[1][0]==8 && b[1][2]==2 && b[2][0]==9 && b[2][2]==3); }
    DONE();
}
