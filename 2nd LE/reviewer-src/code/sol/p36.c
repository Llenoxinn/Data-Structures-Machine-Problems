// wait[i] = number of days after day i until a strictly warmer day,
// or 0 if there is none.   [73 74 75 71 69 72 76 73] -> [1 1 4 2 1 1 0 0]
void dailyTemperatures(int t[], int n, int wait[]) {
    stack cold;                      // days still waiting, temperatures
    stInit(&cold);                   // non-increasing from bottom to top

    for (int i = 0; i < n; i++) {
        int j;
        while (stTop(&cold, &j) && t[j] < t[i]) {
            wait[j] = i - j;         // day i is the first warmer day for j
            stPop(&cold, &j);
        }
        stPush(&cold, i);
    }
    int j;
    while (stPop(&cold, &j)) wait[j] = 0;   // never got warmer
}
