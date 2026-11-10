// Merges the sorted lists a and b by relinking nodes. a gets all nodes, b is
// left empty. On equal items the node of a goes first.
void mergeSorted(list *a, list *b) {
    node *x = a->head;
    node *y = b->head;
    node *head = NULL;               // head and last build the merged chain
    node *last = NULL;

    while (x != NULL || y != NULL) {
        node *take;
        if (y == NULL || (x != NULL && x->item <= y->item)) {
            take = x;
            x = x->next;
        } else {
            take = y;
            y = y->next;
        }
        take->prev = last;
        take->next = NULL;
        if (last == NULL) head = take;
        else last->next = take;
        last = take;
    }
    a->head = head;
    a->tail = last;
    a->size = a->size + b->size;
    b->head = NULL;
    b->tail = NULL;
    b->size = 0;
}
