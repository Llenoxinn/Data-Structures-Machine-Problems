// A deque of capacity k (1 <= k <= 1000) in a circular array.
// Item i of the deque lives at items[(first + i) % cap].
class CircularDeque {
public:
    int items[1000];
    int cap;
    int first;                       // index of the first item
    int count;                       // number of items

    CircularDeque(int k) {
        cap = k;
        first = 0;
        count = 0;
    }

    bool isEmpty() { return count == 0; }
    bool isFull() { return count == cap; }

    bool insertFront(int x) {
        if (isFull()) return false;
        first = (first - 1 + cap) % cap;     // NOT (first - 1) % cap
        items[first] = x;
        count++;
        return true;
    }

    bool insertLast(int x) {
        if (isFull()) return false;
        items[(first + count) % cap] = x;
        count++;
        return true;
    }

    bool deleteFront() {
        if (isEmpty()) return false;
        first = (first + 1) % cap;
        count--;
        return true;
    }

    bool deleteLast() {
        if (isEmpty()) return false;
        count--;                     // the last cell simply stops counting
        return true;
    }

    // The first / last item, or -1 if the deque is empty.
    int getFront() {
        if (isEmpty()) return -1;
        return items[first];
    }

    int getRear() {
        if (isEmpty()) return -1;
        return items[(first + count - 1) % cap];
    }
};
