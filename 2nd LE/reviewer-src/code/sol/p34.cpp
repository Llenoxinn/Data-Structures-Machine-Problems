// A stack that also returns its minimum in O(1).
// "mins" holds, for every level of "all", the smallest value at or below it.
class MinStack {
public:
    stack<int> all;
    stack<int> mins;

    void push(int x) {
        all.push(x);
        if (!mins.empty() && mins.top() < x) {
            mins.push(mins.top());       // the old minimum still wins
        } else {
            mins.push(x);                // x is the new minimum
        }
    }

    void pop() {
        all.pop();
        mins.pop();                      // keep the two stacks in step
    }

    int top() { return all.top(); }
    int getMin() { return mins.top(); }
    bool empty() { return all.empty(); }
};
