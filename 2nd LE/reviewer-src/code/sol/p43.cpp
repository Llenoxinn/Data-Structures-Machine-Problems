// A queue built from two stacks. Items enter through "in" and leave through
// "out"; moving everything from in to out reverses the order, which turns
// last-in-first-out into first-in-first-out.
class MyQueue {
public:
    stack<int> in;
    stack<int> out;

    void push(int x) {
        in.push(x);
    }

    // Moves items only when out is empty, so each item moves at most once.
    void shift() {
        if (out.empty()) {
            while (!in.empty()) {
                out.push(in.top());
                in.pop();
            }
        }
    }

    void pop() {                     // removes the front
        shift();
        out.pop();
    }

    int front() {                    // the front item, not removed
        shift();
        return out.top();
    }

    bool empty() {
        return in.empty() && out.empty();
    }
};
