// A queue that can push and pop at the front, the middle and the back.
// left holds the first half, right the second half, and always
//     right.size() == left.size()  or  right.size() == left.size() + 1.
class FrontMiddleBackQueue {
public:
    deque<int> left;
    deque<int> right;

    // Restores the size rule by moving one item across the middle.
    void rebalance() {
        if (left.size() > right.size()) {
            right.push_front(left.back());
            left.pop_back();
        } else if (right.size() > left.size() + 1) {
            left.push_back(right.front());
            right.pop_front();
        }
    }

    void pushFront(int x) {
        left.push_front(x);
        rebalance();
    }

    void pushMiddle(int x) {
        if (left.size() == right.size()) right.push_front(x);
        else left.push_back(x);
    }

    void pushBack(int x) {
        right.push_back(x);
        rebalance();
    }

    // The pops return the removed item, or -1 if the queue is empty.
    int popFront() {
        if (right.empty()) return -1;            // then left is empty too
        int x;
        if (left.empty()) { x = right.front(); right.pop_front(); }
        else { x = left.front(); left.pop_front(); }
        rebalance();
        return x;
    }

    int popMiddle() {
        if (right.empty()) return -1;
        int x;
        // frontmost middle: the back of left if the halves are equal
        if (left.size() == right.size()) { x = left.back(); left.pop_back(); }
        else { x = right.front(); right.pop_front(); }
        return x;
    }

    int popBack() {
        if (right.empty()) return -1;
        int x = right.back();
        right.pop_back();
        rebalance();
        return x;
    }
};
