// Tests of the C++ listings of Part I (IntVector, DLList) against a model.
#include "../lib/testutil.h"
#include "../listings/intvector.cpp"
#include "../listings/dllist.cpp"

int main() {
    int it, op, i, m[300], mn;
    for (it = 0; it < 200; it++) {
        IntVector v; DLList d; mn = 0;
        for (op = 0; op < 300; op++) {
            int r = rnd(3), x = rnd(100);
            if (r < 2 && mn < 250) { int pos = rnd(mn + 1);
                v.add(pos, x); d.add(pos, x);
                for (i = mn; i > pos; i--) m[i] = m[i-1]; m[pos] = x; mn++; }
            else if (mn > 0) { int pos = rnd(mn);
                CHECK(v.remove(pos) == m[pos]); CHECK(d.remove(pos) == m[pos]);
                for (i = pos; i < mn - 1; i++) m[i] = m[i+1]; mn--; }
            CHECK(v.size() == mn && d.size() == mn);
            CHECK(v.capacity() >= mn && (mn == 0 || v.capacity() < 3 * mn));
            for (i = 0; i < mn; i++) CHECK(v.get(i) == m[i] && d.get(i) == m[i]);
        }
    }
    DONE();
}
