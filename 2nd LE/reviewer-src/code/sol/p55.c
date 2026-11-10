// A queue that can push and pop at the front, the middle and the back.
// left holds the first half, right the second half, and always
//     size(right) == size(left)  or  size(right) == size(left) + 1.
typedef struct {
    deque left;
    deque right;
} fmbQueue;

void fmbInit(fmbQueue *q) {
    dqInit(&q->left);
    dqInit(&q->right);
}

// Restores the size invariant by moving one item across the middle.
void rebalance(fmbQueue *q) {
    int x;
    if (dqSize(&q->left) > dqSize(&q->right)) {
        dqPopBack(&q->left, &x);
        dqPushFront(&q->right, x);
    } else if (dqSize(&q->right) > dqSize(&q->left) + 1) {
        dqPopFront(&q->right, &x);
        dqPushBack(&q->left, x);
    }
}

void fmbPushFront(fmbQueue *q, int x) {
    dqPushFront(&q->left, x);
    rebalance(q);
}

void fmbPushMiddle(fmbQueue *q, int x) {
    if (dqSize(&q->left) == dqSize(&q->right)) dqPushFront(&q->right, x);
    else dqPushBack(&q->left, x);
}

void fmbPushBack(fmbQueue *q, int x) {
    dqPushBack(&q->right, x);
    rebalance(q);
}

// The pops return the removed item, or -1 if the queue is empty.
int fmbPopFront(fmbQueue *q) {
    int x;
    if (dqEmpty(&q->right)) return -1;              // then left is empty too
    if (dqEmpty(&q->left)) dqPopFront(&q->right, &x);
    else dqPopFront(&q->left, &x);
    rebalance(q);
    return x;
}

int fmbPopMiddle(fmbQueue *q) {
    int x;
    if (dqEmpty(&q->right)) return -1;
    // frontmost middle: the back of left if the halves are equal
    if (dqSize(&q->left) == dqSize(&q->right)) dqPopBack(&q->left, &x);
    else dqPopFront(&q->right, &x);
    return x;
}

int fmbPopBack(fmbQueue *q) {
    int x;
    if (dqEmpty(&q->right)) return -1;
    dqPopBack(&q->right, &x);
    rebalance(q);
    return x;
}
