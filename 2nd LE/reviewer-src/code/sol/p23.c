// Inserts x into the sorted list, after any equal items.
void insertSorted(list *l, int x) {
    node *n = (node *)malloc(sizeof(node));
    n->item = x;

    node *cur = l->head;
    while (cur != NULL && cur->item <= x) {   // first node greater than x
        cur = cur->next;
    }
    // n goes between cur->prev and cur
    n->next = cur;
    if (cur != NULL) {
        n->prev = cur->prev;
        cur->prev = n;
    } else {                                  // x is the new maximum
        n->prev = l->tail;
        l->tail = n;
    }
    if (n->prev != NULL) n->prev->next = n;
    else l->head = n;                         // x is the new minimum
    l->size++;
}
