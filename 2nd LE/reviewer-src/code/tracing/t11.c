// libs: lib/stackqueue.h
int prec(char op) {
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
}

int main() {
    char *e = "a+b*(c-d)/e";
    char out[50];
    int w = 0, t, maxDepth = 0;
    stack st;
    stInit(&st);
    for (int i = 0; e[i]; i++) {
        char c = e[i];
        if (c >= 'a' && c <= 'z') out[w++] = c;
        else if (c == '(') stPush(&st, c);
        else if (c == ')') {
            while (stTop(&st, &t) && t != '(') {
                stPop(&st, &t);
                out[w++] = (char)t;
            }
            stPop(&st, &t);
        } else {
            while (stTop(&st, &t) && prec((char)t) >= prec(c)) {
                stPop(&st, &t);
                out[w++] = (char)t;
            }
            stPush(&st, c);
        }
        if (stSize(&st) > maxDepth) maxDepth = stSize(&st);
    }
    while (stPop(&st, &t)) out[w++] = (char)t;
    out[w] = '\0';
    printf("%s %d\n", out, maxDepth);
    return 0;
}
