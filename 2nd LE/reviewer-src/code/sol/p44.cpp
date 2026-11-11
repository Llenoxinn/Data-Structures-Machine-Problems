// A stack built from one queue. After each push the new item is rotated to
// the front of the queue, so the front is always the top of the stack.
class MyStack {
public:
    queue<int> q;

    void push(int x) {
        q.push(x);
        int older = q.size() - 1;
        for (int i = 0; i < older; i++) {   // older items go behind x
            q.push(q.front());
            q.pop();
        }
    }

    void pop() { q.pop(); }
    int top() { return q.front(); }
    bool empty() { return q.empty(); }
};
