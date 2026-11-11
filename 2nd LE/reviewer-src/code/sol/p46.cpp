// Returns q with the order of its first k items reversed; the rest stay.
// [1 2 3 4 5], k = 3 -> [3 2 1 4 5]. Assumes 0 <= k <= size.
// Usage:  q = reverseFirstK(q, 3);
queue<int> reverseFirstK(queue<int> q, int k) {
    stack<int> st;

    for (int i = 0; i < k; i++) {           // the stack reverses the first k
        st.push(q.front());
        q.pop();
    }
    while (!st.empty()) {                   // put them back at the end
        q.push(st.top());
        st.pop();
    }

    int rest = q.size() - k;                // read the size once
    for (int i = 0; i < rest; i++) {        // rotate the other items
        q.push(q.front());                  // behind the reversed ones
        q.pop();
    }
    return q;
}
