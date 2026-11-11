// libs:
// a queue built from two stacks:
// enq pushes onto in; deq pops from out (refilled from in when out is empty)
class TwoQ {
public:
    stack<int> in;
    stack<int> out;

    void enq(int x) { in.push(x); }

    int deq() {                     // returns -1 if both stacks are empty
        if (out.empty()) {
            while (!in.empty()) { out.push(in.top()); in.pop(); }
        }
        if (out.empty()) return -1;
        int x = out.top();
        out.pop();
        return x;
    }
};

int main() {
    TwoQ q;
    int a;
    q.enq(1); q.enq(2); q.enq(3);
    a = q.deq(); printf("%d ", a);
    q.enq(4);
    a = q.deq(); printf("%d ", a);
    q.enq(5); q.enq(6);
    a = q.deq(); printf("%d ", a);
    a = q.deq(); printf("%d ", a);
    a = q.deq(); printf("%d ", a);
    a = q.deq(); printf("%d ", a);
    a = q.deq(); printf("%d\n", a);
    printf("in=%d out=%d\n", (int)q.in.size(), (int)q.out.size());
    return 0;
}
