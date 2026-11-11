// Returns the stack s sorted so that the smallest item is on top (popping
// gives 1, 2, 3, ...). Only one extra stack is used.
// Usage:  s = sortStack(s);
stack<int> sortStack(stack<int> s) {
    stack<int> r;                    // sorted, largest on top

    while (!s.empty()) {
        int x = s.top();
        s.pop();
        // items in r larger than x must go back to s so that x fits below them
        while (!r.empty() && r.top() > x) {
            s.push(r.top());
            r.pop();
        }
        r.push(x);
    }
    while (!r.empty()) {             // moving back reverses the order
        s.push(r.top());
        r.pop();
    }
    return s;
}
