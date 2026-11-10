// Removes the n-th node from the end (n = 1 is the last) in one pass.
// Returns 1 on success, 0 if n < 1 or n > the length.
int removeNthFromEnd(sll *l, int n) {
    if (n < 1) return 0;
    snode dummy;                     // a dummy in front of the head means
    dummy.next = l->head;            // the head needs no special case

    snode *lead = &dummy;
    for (int i = 0; i < n; i++) {    // lead goes n nodes ahead
        if (lead->next == NULL) return 0;
        lead = lead->next;
    }
    snode *lag = &dummy;
    while (lead->next != NULL) {     // lag stops just before the target
        lead = lead->next;
        lag = lag->next;
    }
    snode *target = lag->next;
    int wasTail = (target == l->tail);
    lag->next = target->next;
    free(target);
    l->size--;

    l->head = dummy.next;
    if (l->head == NULL) l->tail = NULL;
    else if (wasTail) l->tail = lag;
    return 1;
}
