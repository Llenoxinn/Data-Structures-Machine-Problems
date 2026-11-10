// Precedence of an operator: * and / bind tighter than + and -.
int prec(char op) {
    if (op == '*' || op == '/') return 2;
    return 1;
}

// Converts infix to postfix. Operands are single digits; operators are
// + - * / and parentheses; there are no spaces. "2+3*4" -> "234*+".
void toPostfix(char in[], char out[]) {
    stack ops;                       // operators waiting for their operands
    int k = 0;                       // next free place in out
    stInit(&ops);

    for (int i = 0; in[i] != '\0'; i++) {
        char c = in[i];
        if (c >= '0' && c <= '9') {
            out[k++] = c;            // operands go straight to the output
        } else if (c == '(') {
            stPush(&ops, c);
        } else if (c == ')') {
            int top;                 // pop until the matching '('
            while (stPop(&ops, &top) && top != '(') out[k++] = top;
        } else {
            int top;                 // pop operators that must run first
            while (stTop(&ops, &top) && top != '(' && prec(top) >= prec(c)) {
                stPop(&ops, &top);
                out[k++] = top;
            }
            stPush(&ops, c);
        }
    }
    int top;
    while (stPop(&ops, &top)) out[k++] = top;
    out[k] = '\0';
}

// Evaluates a postfix expression of single digits and + - * /
// (integer division). "234*+" -> 14. The input is always valid.
int evalPostfix(char p[]) {
    stack st;
    stInit(&st);

    for (int i = 0; p[i] != '\0'; i++) {
        char c = p[i];
        if (c >= '0' && c <= '9') {
            stPush(&st, c - '0');
        } else {
            int b, a;                // b was pushed last: the right side
            stPop(&st, &b);
            stPop(&st, &a);
            if (c == '+') stPush(&st, a + b);
            if (c == '-') stPush(&st, a - b);
            if (c == '*') stPush(&st, a * b);
            if (c == '/') stPush(&st, a / b);
        }
    }
    int result;
    stPop(&st, &result);
    return result;
}
