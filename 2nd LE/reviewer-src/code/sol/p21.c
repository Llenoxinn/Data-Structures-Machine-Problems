// Reverses the list in place: every node swaps its next and prev.
void reverseDLL(list *l) {
    node *cur = l->head;
    while (cur != NULL) {
        node *nxt = cur->next;       // read before swapping
        cur->next = cur->prev;
        cur->prev = nxt;
        cur = nxt;
    }
    node *tmp = l->head;             // head and tail trade places
    l->head = l->tail;
    l->tail = tmp;
}
