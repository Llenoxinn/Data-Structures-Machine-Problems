// wait[i] = number of days after day i until a strictly warmer day,
// or 0 if there is none.   [73 74 75 71 69 72 76 73] -> [1 1 4 2 1 1 0 0]
void dailyTemperatures(int t[], int n, int wait[]) {
    stack<int> cold;                 // days still waiting; their temperatures
                                     // are non-increasing from bottom to top
    for (int i = 0; i < n; i++) {
        while (!cold.empty() && t[cold.top()] < t[i]) {
            int j = cold.top();
            wait[j] = i - j;         // day i is the first warmer day for j
            cold.pop();
        }
        cold.push(i);
    }
    while (!cold.empty()) {          // never got warmer
        wait[cold.top()] = 0;
        cold.pop();
    }
}
