// Precedence of an operator: * and / bind tighter than + and -.
int prec(char op) {
    if (op == '*' || op == '/') return 2;
    return 1;
}

// Converts infix to postfix. Operands are single digits; operators are
// + - * / and parentheses; there are no spaces. "2+3*4" -> "234*+".
void toPostfix(char in[], char out[]) {
    stack<char> ops;                 // operators waiting for their operands
    int k = 0;                       // next free place in out

    for (int i = 0; in[i] != '\0'; i++) {
        char c = in[i];
        if (c >= '0' && c <= '9') {
            out[k++] = c;            // operands go straight to the output
        } else if (c == '(') {
            ops.push(c);
        } else if (c == ')') {
            while (ops.top() != '(') {      // pop until the matching '('
                out[k++] = ops.top();
                ops.pop();
            }
            ops.pop();                      // throw the '(' away
        } else {
            // pop the operators that must run first
            while (!ops.empty() && ops.top() != '(' && prec(ops.top()) >= prec(c)) {
                out[k++] = ops.top();
                ops.pop();
            }
            ops.push(c);
        }
    }
    while (!ops.empty()) {
        out[k++] = ops.top();
        ops.pop();
    }
    out[k] = '\0';
}

// Evaluates a postfix expression of single digits and + - * /
// (integer division). "234*+" -> 14. The input is always valid.
int evalPostfix(char p[]) {
    stack<int> st;

    for (int i = 0; p[i] != '\0'; i++) {
        char c = p[i];
        if (c >= '0' && c <= '9') {
            st.push(c - '0');
        } else {
            int b = st.top(); st.pop();     // b was pushed last: the right side
            int a = st.top(); st.pop();
            if (c == '+') st.push(a + b);
            if (c == '-') st.push(a - b);
            if (c == '*') st.push(a * b);
            if (c == '/') st.push(a / b);
        }
    }
    return st.top();
}
