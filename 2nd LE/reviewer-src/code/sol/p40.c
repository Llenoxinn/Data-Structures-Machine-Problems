// Repeatedly removes two equal neighbouring letters. "abbaca" -> "ca".
// Result is written to out.
void removeAdjacent(char s[], char out[]) {
    stack st;
    int top;
    stInit(&st);

    for (int i = 0; s[i] != '\0'; i++) {
        if (stTop(&st, &top) && top == s[i]) {
            stPop(&st, &top);        // equal to the top: both vanish
        } else {
            stPush(&st, s[i]);
        }
    }
    int k = stSize(&st);             // the stack holds the answer
    out[k] = '\0';
    while (stPop(&st, &top)) out[--k] = top;
}
