// A stack of ints in an array. It is used exactly like stack<int> from <stack>:
//     Stack st;   st.push(5);   st.top();   st.pop();   st.empty();   st.size();
class Stack {
public:
    int items[100];
    int count;                 // number of items; the top is items[count - 1]

    Stack() { count = 0; }

    bool empty() { return count == 0; }
    int size() { return count; }

    void push(int x) {
        if (count == 100) return;          // full: nothing happens
        items[count] = x;
        count++;
    }

    void pop() {                           // removes the top (returns nothing)
        if (count == 0) return;            // empty: nothing happens
        count--;
    }

    int top() {                            // the top item, NOT removed
        return items[count - 1];           // check empty() first!
    }
};

// A queue of ints in a circular array. Used exactly like queue<int> from <queue>:
//     Queue q;   q.push(5);   q.front();   q.back();   q.pop();   q.empty();   q.size();
class Queue {
public:
    int items[100];
    int first;                 // index of the front item
    int count;                 // item i is at items[(first + i) % 100]

    Queue() { first = 0; count = 0; }

    bool empty() { return count == 0; }
    int size() { return count; }

    void push(int x) {                     // adds x at the back
        if (count == 100) return;
        items[(first + count) % 100] = x;
        count++;
    }

    void pop() {                           // removes the front (returns nothing)
        if (count == 0) return;
        first = (first + 1) % 100;
        count--;
    }

    int front() { return items[first]; }                       // check empty() first!
    int back() { return items[(first + count - 1) % 100]; }    // check empty() first!
};
