// A deque on a circular doubly linked list with one sentinel node.
// sentinel->next is the first item, sentinel->prev the last; when the deque
// is empty both point back to the sentinel, so no pointer is ever NULL.
class dqnode {
public:
    int item;
    dqnode *prev;
    dqnode *next;
    dqnode(int x) {
        item = x;
        prev = next = NULL;
    }
};

class LinkedDeque {
public:
    dqnode *sentinel;                // a dummy node; its item is never used
    int count;

    LinkedDeque() {
        sentinel = new dqnode(0);
        sentinel->next = sentinel;
        sentinel->prev = sentinel;
        count = 0;
    }

    bool empty() { return count == 0; }
    int size() { return count; }

    // Links a new node with item x between the neighbours a and b.
    void linkBetween(dqnode *a, dqnode *b, int x) {
        dqnode *n = new dqnode(x);
        n->prev = a;
        n->next = b;
        a->next = n;
        b->prev = n;
        count++;
    }

    // Unlinks node n from its two neighbours and deletes it.
    void unlink(dqnode *n) {
        n->prev->next = n->next;
        n->next->prev = n->prev;
        delete n;
        count--;
    }

    void push_front(int x) { linkBetween(sentinel, sentinel->next, x); }
    void push_back(int x) { linkBetween(sentinel->prev, sentinel, x); }

    void pop_front() {
        if (empty()) return;
        unlink(sentinel->next);
    }

    void pop_back() {
        if (empty()) return;
        unlink(sentinel->prev);
    }

    int front() { return sentinel->next->item; }     // check empty() first!
    int back() { return sentinel->prev->item; }      // check empty() first!

    void clear() {                   // deletes every node except the sentinel
        while (!empty()) pop_front();
    }
};
