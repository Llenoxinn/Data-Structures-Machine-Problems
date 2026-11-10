// Returns the middle item (the second one if the length is even).
// slow moves 1 node per step, fast moves 2, so slow is halfway when fast ends.
int middleItem(sll *l) {
    snode *slow = l->head;
    snode *fast = l->head;
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow->item;
}

// Stores the k-th item from the end (k = 1 is the last) in *out.
// Returns 1 on success, 0 if k < 1 or k > the length.
int kthFromEnd(sll *l, int k, int *out) {
    if (k < 1) return 0;
    snode *lead = l->head;
    for (int i = 0; i < k; i++) {    // lead goes k nodes ahead
        if (lead == NULL) return 0;
        lead = lead->next;
    }
    snode *lag = l->head;
    while (lead != NULL) {           // both move until lead falls off
        lead = lead->next;
        lag = lag->next;
    }
    *out = lag->item;
    return 1;
}
