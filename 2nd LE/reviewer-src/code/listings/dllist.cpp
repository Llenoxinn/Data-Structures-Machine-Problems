// DLList with a DUMMY node (a circular list), after the course notes.
// dummy.next is the head, dummy.prev is the tail; an empty list points to
// itself, so no pointer is ever NULL and the special cases disappear.
struct dnode {
    int x;
    dnode *next, *prev;
};
class DLList {
    dnode dummy;
    int n;
public:
    DLList() { dummy.next = &dummy; dummy.prev = &dummy; n = 0; }
    ~DLList() { while (n > 0) remove(0); }
    int size() { return n; }

    // getNode(i): start from the nearer end. Cost O(1 + min(i, n-i)).
    dnode *getNode(int i) {
        dnode *p;
        int j;
        if (i < n / 2) {
            p = dummy.next;
            for (j = 0; j < i; j++) p = p->next;
        } else {
            p = &dummy;
            for (j = n; j > i; j--) p = p->prev;
        }
        return p;
    }
    int get(int i) { return getNode(i)->x; }
    int set(int i, int x) {
        dnode *u = getNode(i);
        int y = u->x;
        u->x = x;
        return y;
    }

    // addBefore(w, x): link a new node u between w->prev and w. O(1).
    dnode *addBefore(dnode *w, int x) {
        dnode *u = new dnode;
        u->x = x;
        u->prev = w->prev;
        u->next = w;
        u->next->prev = u;
        u->prev->next = u;
        n++;
        return u;
    }
    void add(int i, int x) { addBefore(getNode(i), x); }   // i in 0..n

    // remove(w): make the neighbours skip w. O(1) once w is known.
    void remove(dnode *w) {
        w->prev->next = w->next;
        w->next->prev = w->prev;
        delete w;
        n--;
    }
    int remove(int i) {
        dnode *w = getNode(i);
        int x = w->x;
        remove(w);
        return x;
    }
};
