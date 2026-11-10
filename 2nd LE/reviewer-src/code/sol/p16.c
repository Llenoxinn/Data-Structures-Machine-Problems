// Reverses the list in place by changing the links.
void reverseList(sll *l) {
    snode *prev = NULL;
    snode *cur = l->head;

    while (cur != NULL) {
        snode *nxt = cur->next;      // remember the rest
        cur->next = prev;            // point backwards
        prev = cur;
        cur = nxt;
    }
    l->tail = l->head;               // the old head is the new tail
    l->head = prev;
}

// Bonus: recursive version. Returns the new head of the reversed list.
snode *reverseRec(snode *h) {
    if (h == NULL || h->next == NULL) return h;
    snode *newHead = reverseRec(h->next);
    h->next->next = h;               // the next node now points back to h
    h->next = NULL;
    return newHead;
}
