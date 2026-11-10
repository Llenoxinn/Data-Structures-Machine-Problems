// Returns 1 if every bracket in s is closed by the same kind of bracket,
// in the right order.
// s contains only the characters ( ) [ ] { }.
int isBalanced(char s[]) {
    stack st;
    stInit(&st);

    for (int i = 0; s[i] != '\0'; i++) {
        char c = s[i];
        if (c == '(' || c == '[' || c == '{') {
            stPush(&st, c);                     // remember the opener
        } else {
            int open;
            if (!stPop(&st, &open)) return 0;   // closer with nothing to close
            if (c == ')' && open != '(') return 0;
            if (c == ']' && open != '[') return 0;
            if (c == '}' && open != '{') return 0;
        }
    }
    return stEmpty(&st);                        // leftover openers: not balanced
}
