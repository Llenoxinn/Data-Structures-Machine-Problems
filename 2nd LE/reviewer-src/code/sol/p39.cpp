// Decodes k[...] (repeat the bracketed part k times), with nesting:
// "3[a]2[bc]" -> "aaabcbc", "3[a2[c]]" -> "accaccacc".
// The answer is built directly in out; the stacks remember, for every open
// bracket, its repeat count and where its part starts in out.
void decodeString(char s[], char out[]) {
    stack<int> counts;
    stack<int> starts;
    int len = 0;                     // current length of out
    int k = 0;                       // number being read

    for (int i = 0; s[i] != '\0'; i++) {
        char c = s[i];
        if (c >= '0' && c <= '9') {
            k = k * 10 + (c - '0');
        } else if (c == '[') {
            counts.push(k);
            starts.push(len);
            k = 0;
        } else if (c == ']') {
            int times = counts.top();
            int start = starts.top();
            counts.pop();
            starts.pop();
            int partLen = len - start;           // out[start..len-1] is the part
            for (int t = 1; t < times; t++) {    // it is already there once
                for (int j = 0; j < partLen; j++) {
                    out[len] = out[start + j];
                    len++;
                }
            }
        } else {
            out[len] = c;
            len++;
        }
    }
    out[len] = '\0';
}
