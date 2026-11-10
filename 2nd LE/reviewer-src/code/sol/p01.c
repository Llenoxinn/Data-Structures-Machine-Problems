// Writes the encoding of s into out (a letter followed by its run length).
// Returns the length of the encoding.
int rleEncode(char *s, char *out) {
    int i = 0;                       // read position in s
    int w = 0;                       // write position in out

    while (s[i] != '\0') {
        char c = s[i];
        int run = 0;
        while (s[i] == c) {          // count the run of c
            run++;
            i++;
        }
        out[w] = c;
        w++;

        int digits = 0;              // how many digits does run have?
        int t = run;
        while (t > 0) {
            digits++;
            t = t / 10;
        }
        for (int d = digits - 1; d >= 0; d--) {
            out[w + d] = '0' + run % 10;   // fill the digits from the right
            run = run / 10;
        }
        w = w + digits;
    }
    out[w] = '\0';
    return w;
}

// Compresses a[0..n-1] in place; a run of length 1 keeps no number.
// Returns the new length.
int compress(char *a, int n) {
    int r = 0;                       // read position
    int w = 0;                       // write position (never passes r)

    while (r < n) {
        char c = a[r];
        int run = 0;
        while (r < n && a[r] == c) {
            run++;
            r++;
        }
        a[w] = c;
        w++;

        if (run > 1) {
            int digits = 0;
            int t = run;
            while (t > 0) {
                digits++;
                t = t / 10;
            }
            for (int d = digits - 1; d >= 0; d--) {
                a[w + d] = '0' + run % 10;
                run = run / 10;
            }
            w = w + digits;
        }
    }
    return w;
}

// Bonus: decodes "a3b1" into "aaab". Returns the decoded length.
int rleDecode(char *e, char *out) {
    int i = 0;
    int w = 0;

    while (e[i] != '\0') {
        char c = e[i];
        i++;
        int count = 0;
        while (e[i] >= '0' && e[i] <= '9') {
            count = count * 10 + (e[i] - '0');
            i++;
        }
        for (int k = 0; k < count; k++) {
            out[w] = c;
            w++;
        }
    }
    out[w] = '\0';
    return w;
}
