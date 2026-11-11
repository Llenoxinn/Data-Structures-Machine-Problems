// a[i] > 0 moves right, a[i] < 0 moves left; |a[i]| is the size. When two
// meet, the smaller explodes (both if equal). Writes the survivors, left to
// right, into out and returns how many there are.
int asteroidCollision(int a[], int n, int out[]) {
    stack<int> st;                   // survivors so far, left to right

    for (int i = 0; i < n; i++) {
        int x = a[i];
        bool alive = true;
        // only a right-mover on the stack and a left-mover x can meet
        while (alive && x < 0 && !st.empty() && st.top() > 0) {
            if (st.top() < -x) {
                st.pop();            // the top explodes, x keeps going
            } else if (st.top() == -x) {
                st.pop();            // both explode
                alive = false;
            } else {
                alive = false;       // x explodes
            }
        }
        if (alive) st.push(x);
    }

    int m = st.size();               // the stack holds the answer, last on top
    for (int k = m - 1; k >= 0; k--) {
        out[k] = st.top();
        st.pop();
    }
    return m;
}
