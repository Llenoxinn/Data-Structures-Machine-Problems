// Returns 1 if the list reads the same forwards and backwards.
int isPalindrome(list *l) {
    node *left = l->head;
    node *right = l->tail;

    // stop when the two pointers meet or cross (an empty list skips the loop)
    while (left != right && left->prev != right) {
        if (left->item != right->item) return 0;
        left = left->next;
        right = right->prev;
    }
    return 1;
}
