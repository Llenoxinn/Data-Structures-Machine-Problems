// Returns 1 if every bracket in s is closed by the same kind of bracket,
// in the right order.
// s contains only the characters ( ) [ ] { }.
int isBalanced(char s[]) {
    stack<char> st;

    for (int i = 0; s[i] != '\0'; i++) {
        char c = s[i];
        if (c == '(' || c == '[' || c == '{') {
            st.push(c);                     // remember the opener
        } else {
            if (st.empty()) return 0;       // closer with nothing to close
            char open = st.top();
            st.pop();
            if (c == ')' && open != '(') return 0;
            if (c == ']' && open != '[') return 0;
            if (c == '}' && open != '{') return 0;
        }
    }
    return st.empty();                      // leftover openers: not balanced
}
