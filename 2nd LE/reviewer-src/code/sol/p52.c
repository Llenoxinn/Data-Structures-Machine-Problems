// 1 if s reads the same forwards and backwards when only its letters and
// digits are kept and upper case is treated as lower case.
// "A man, a plan, a canal: Panama" -> 1, "race a car" -> 0.
int isPalindromeText(char s[]) {
    deque d;
    int a, b;
    dqInit(&d);

    for (int i = 0; s[i] != '\0'; i++) {
        char c = s[i];
        if (c >= 'A' && c <= 'Z') c = c - 'A' + 'a';
        if ((c >= 'a' && c <= 'z') || (c >= '0' && c <= '9')) dqPushBack(&d, c);
    }
    while (dqSize(&d) > 1) {             // compare the two ends, then drop them
        dqPopFront(&d, &a);
        dqPopBack(&d, &b);
        if (a != b) return 0;
    }
    return 1;                            // 0 or 1 character left
}
