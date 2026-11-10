// Counts the requests in the last 3000 ms. ping(t) is called with strictly
// increasing t and returns how many pings happened in [t - 3000, t].
typedef struct {
    queue times;                     // the pings that are still recent
} recentCounter;

void rcInit(recentCounter *r) {
    qInit(&r->times);
}

int rcPing(recentCounter *r, int t) {
    int old;
    qEnq(&r->times, t);
    // the oldest pings leave first: drop them while they are too old
    while (qFront(&r->times, &old) && old < t - 3000) {
        qDeq(&r->times, &old);
    }
    return qSize(&r->times);
}
