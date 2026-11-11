// out[i] = the first value to the right of a[i] that is greater than a[i],
// or -1 if there is none.   [2 1 5 3] -> [5 5 -1 -1]
// The stack holds indices whose answer is still unknown; their values
// decrease from bottom to top.
void nextGreater(int a[], int n, int out[]) {
    stack<int> waiting;

    for (int i = 0; i < n; i++) out[i] = -1;

    for (int i = 0; i < n; i++) {
        // a[i] answers every waiting index whose value is smaller
        while (!waiting.empty() && a[waiting.top()] < a[i]) {
            out[waiting.top()] = a[i];
            waiting.pop();
        }
        waiting.push(i);
    }
}
