// Counts the requests in the last 3000 ms. ping(t) is called with strictly
// increasing t and returns how many pings happened in [t - 3000, t].
class RecentCounter {
public:
    queue<int> times;                // the pings that are still recent

    int ping(int t) {
        times.push(t);
        // the oldest pings leave first: drop them while they are too old
        while (times.front() < t - 3000) {
            times.pop();
        }
        return times.size();
    }
};
