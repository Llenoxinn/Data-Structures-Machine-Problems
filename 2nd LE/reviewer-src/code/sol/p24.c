typedef struct mnode {
    int item;
    struct mnode *next;
} mnode;

typedef struct {
    mnode *head;
    mnode *mid;          // the node at index (size - 1) / 2
    mnode *tail;
    int size;
} mlist;

void minit(mlist *l) {
    l->head = NULL;
    l->mid = NULL;
    l->tail = NULL;
    l->size = 0;
}

// O(1)
int middle(mlist *l) {
    return l->mid->item;
}

// O(1): the new node is after mid; mid moves right when size was even.
void mPushBack(mlist *l, int x) {
    mnode *n = (mnode *)malloc(sizeof(mnode));
    n->item = x;
    n->next = NULL;
    if (l->size == 0) {
        l->head = n;
        l->mid = n;
    } else {
        l->tail->next = n;
        if (l->size % 2 == 0) l->mid = l->mid->next;
    }
    l->tail = n;
    l->size++;
}

// O(1) if size is even; O(n) if odd, because mid must move one node LEFT.
void mPushFront(mlist *l, int x) {
    mnode *n = (mnode *)malloc(sizeof(mnode));
    n->item = x;
    n->next = l->head;
    l->head = n;
    if (l->size == 0) {
        l->mid = n;
        l->tail = n;
    } else if (l->size % 2 == 1) {
        l->mid = l->head;                    // walk from the head
        for (int i = 0; i < l->size / 2; i++) l->mid = l->mid->next;
    }
    l->size++;
}

// O(1): mid moves right when size was even.
int mPopFront(mlist *l, int *x) {
    if (l->size == 0) return 0;
    mnode *old = l->head;
    *x = old->item;
    l->head = old->next;
    if (l->size == 1) {
        l->mid = NULL;
        l->tail = NULL;
    } else if (l->size % 2 == 0) {
        l->mid = l->mid->next;
    }
    free(old);
    l->size--;
    return 1;
}

// O(n): the new tail is the node before the old tail, which needs a walk.
// If size was odd, mid also moves one node LEFT.
int mPopBack(mlist *l, int *x) {
    if (l->size == 0) return 0;
    *x = l->tail->item;
    if (l->size == 1) {
        free(l->head);
        l->head = NULL;
        l->mid = NULL;
        l->tail = NULL;
    } else {
        mnode *prev = l->head;               // will be the node before tail
        while (prev->next != l->tail) prev = prev->next;
        free(l->tail);
        prev->next = NULL;
        l->tail = prev;
        if (l->size % 2 == 1) {              // recompute mid from the head
            l->mid = l->head;
            for (int i = 0; i < (l->size - 2) / 2; i++) l->mid = l->mid->next;
        }
    }
    l->size--;
    return 1;
}
