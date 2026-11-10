// libs: lib/stackqueue.h
// evalA pops the right operand first (correct); evalB pops the left first.
int apply(char c, int a, int b) {
    if (c == '+') return a + b;
    if (c == '-') return a - b;
    if (c == '*') return a * b;
    return a / b;
}

int evalA(char p[]) {
    stack st; int a, b;
    stInit(&st);
    for (int i = 0; p[i] != '\0'; i++) {
        if (p[i] >= '0' && p[i] <= '9') stPush(&st, p[i] - '0');
        else { stPop(&st, &b); stPop(&st, &a); stPush(&st, apply(p[i], a, b)); }
    }
    stPop(&st, &a);
    return a;
}

int evalB(char p[]) {
    stack st; int a, b;
    stInit(&st);
    for (int i = 0; p[i] != '\0'; i++) {
        if (p[i] >= '0' && p[i] <= '9') stPush(&st, p[i] - '0');
        else { stPop(&st, &a); stPop(&st, &b); stPush(&st, apply(p[i], a, b)); }
    }
    stPop(&st, &a);
    return a;
}

int main() {
    char *e[] = {"34+", "93-", "82/", "27-3/", "234*-", "92-3-", "52-4*"};
    for (int i = 0; i < 7; i++)
        printf("%-6s %3d %3d\n", e[i], evalA(e[i]), evalB(e[i]));
    return 0;
}
