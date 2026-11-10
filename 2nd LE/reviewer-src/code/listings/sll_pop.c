int popFront(sll *l, int *out) {
    snode *old;
    if (l->head == NULL) return 0;          /* underflow                  */
    old = l->head;
    *out = old->item;
    l->head = old->next;                    /* unlink                     */
    if (l->head == NULL) l->tail = NULL;    /* list became empty          */
    free(old);
    l->size--;
    return 1;
}
int popBack(sll *l, int *out) {
    snode *cur;
    if (l->head == NULL) return 0;
    *out = l->tail->item;
    if (l->head == l->tail) {               /* exactly one node           */
        free(l->head);
        l->head = l->tail = NULL;
    } else {
        cur = l->head;                      /* walk to the SECOND-TO-LAST */
        while (cur->next != l->tail) cur = cur->next;
        free(l->tail);
        cur->next = NULL;
        l->tail = cur;
    }
    l->size--;
    return 1;
}
