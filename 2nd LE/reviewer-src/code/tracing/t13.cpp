// libs:
// evalA pops the right operand first (correct); evalB pops the left first.
int apply(char c, int a, int b) {
    if (c == '+') return a + b;
    if (c == '-') return a - b;
    if (c == '*') return a * b;
    return a / b;
}

int evalA(const char p[]) {
    stack<int> st;
    for (int i = 0; p[i] != '\0'; i++) {
        if (p[i] >= '0' && p[i] <= '9') st.push(p[i] - '0');
        else {
            int b = st.top(); st.pop();
            int a = st.top(); st.pop();
            st.push(apply(p[i], a, b));
        }
    }
    return st.top();
}

int evalB(const char p[]) {
    stack<int> st;
    for (int i = 0; p[i] != '\0'; i++) {
        if (p[i] >= '0' && p[i] <= '9') st.push(p[i] - '0');
        else {
            int a = st.top(); st.pop();
            int b = st.top(); st.pop();
            st.push(apply(p[i], a, b));
        }
    }
    return st.top();
}

int main() {
    const char *e[] = {"34+", "93-", "82/", "27-3/", "234*-", "92-3-", "52-4*"};
    for (int i = 0; i < 7; i++)
        printf("%-6s %3d %3d\n", e[i], evalA(e[i]), evalB(e[i]));
    return 0;
}
