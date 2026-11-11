// Repeatedly removes two equal neighbouring letters. "abbaca" -> "ca".
// Result is written to out.
void removeAdjacent(char s[], char out[]) {
    stack<char> st;

    for (int i = 0; s[i] != '\0'; i++) {
        if (!st.empty() && st.top() == s[i]) {
            st.pop();                // equal to the top: both vanish
        } else {
            st.push(s[i]);
        }
    }
    int k = st.size();               // the stack holds the answer
    out[k] = '\0';
    while (!st.empty()) {            // the top is the LAST letter
        k--;
        out[k] = st.top();
        st.pop();
    }
}
