// Swaps every two adjacent nodes: [1 2 3 4] -> [2 1 4 3].
// The nodes move; the items stay inside their nodes.
void swapPairs(sll *l) {
    snode dummy;
    dummy.next = l->head;
    snode *prev = &dummy;            // the node before the pair

    while (prev->next != NULL && prev->next->next != NULL) {
        snode *a = prev->next;
        snode *b = a->next;
        a->next = b->next;
        b->next = a;
        prev->next = b;
        if (a->next == NULL) l->tail = a;   // the pair was at the end
        prev = a;                    // a is now the node before the next pair
    }
    l->head = dummy.next;
}
