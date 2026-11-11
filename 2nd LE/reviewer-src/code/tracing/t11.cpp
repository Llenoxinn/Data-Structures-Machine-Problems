// libs:
int prec(char op) {
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
}

int main() {
    char e[] = "a+b*(c-d)/e";
    char out[50];
    int w = 0, maxDepth = 0;
    stack<char> st;
    for (int i = 0; e[i]; i++) {
        char c = e[i];
        if (c >= 'a' && c <= 'z') out[w++] = c;
        else if (c == '(') st.push(c);
        else if (c == ')') {
            while (st.top() != '(') {
                out[w++] = st.top();
                st.pop();
            }
            st.pop();
        } else {
            while (!st.empty() && prec(st.top()) >= prec(c)) {
                out[w++] = st.top();
                st.pop();
            }
            st.push(c);
        }
        if ((int)st.size() > maxDepth) maxDepth = st.size();
    }
    while (!st.empty()) { out[w++] = st.top(); st.pop(); }
    out[w] = '\0';
    printf("%s %d\n", out, maxDepth);
    return 0;
}
