// Interleaves the first half of a queue of even length with the second:
// [1 2 3 4 5 6 7 8] -> [1 5 2 6 3 7 4 8]. Uses one stack.
// Usage:  q = interleaveHalves(q);
queue<int> interleaveHalves(queue<int> q) {
    stack<int> st;
    int half = q.size() / 2;

    for (int i = 0; i < half; i++) {     // 1. first half onto the stack
        st.push(q.front());              //    q: 5 6 7 8   st: 1 2 3 4 (top 4)
        q.pop();
    }
    while (!st.empty()) {                // 2. q: 5 6 7 8 4 3 2 1
        q.push(st.top());
        st.pop();
    }
    for (int i = 0; i < half; i++) {     // 3. q: 4 3 2 1 5 6 7 8
        q.push(q.front());
        q.pop();
    }
    for (int i = 0; i < half; i++) {     // 4. first half onto the stack again
        st.push(q.front());              //    q: 5 6 7 8   st: 4 3 2 1 (top 1)
        q.pop();
    }
    for (int i = 0; i < half; i++) {     // 5. alternate: one from the stack,
        q.push(st.top());                //    one from the front of q
        st.pop();
        q.push(q.front());
        q.pop();
    }
    return q;
}
