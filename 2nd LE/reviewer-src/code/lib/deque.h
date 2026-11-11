// A deque of ints in a circular array. Used exactly like deque<int> from <deque>:
//     Deque d;   d.push_front(1);   d.push_back(2);   d.front();   d.back();
//     d.pop_front();   d.pop_back();   d.empty();   d.size();
class Deque {
public:
    int items[100];
    int first;                 // index of the front item
    int count;                 // item i is at items[(first + i) % 100]

    Deque() { first = 0; count = 0; }

    bool empty() { return count == 0; }
    int size() { return count; }

    void push_front(int x) {               // adds x before the first item
        if (count == 100) return;
        first = (first - 1 + 100) % 100;   // one step back, wrapping to 99
        items[first] = x;
        count++;
    }

    void push_back(int x) {                // adds x after the last item
        if (count == 100) return;
        items[(first + count) % 100] = x;
        count++;
    }

    void pop_front() {                     // removes the first item
        if (count == 0) return;
        first = (first + 1) % 100;
        count--;
    }

    void pop_back() {                      // removes the last item
        if (count == 0) return;
        count--;
    }

    int front() { return items[first]; }                       // check empty() first!
    int back() { return items[(first + count - 1) % 100]; }    // check empty() first!
};
