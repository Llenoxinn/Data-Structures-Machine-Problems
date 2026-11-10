// Appends a copy of every item of m to the end of l (without append).
// m is a copy of the caller's struct, but its nodes are the caller's nodes,
// so we must create NEW nodes: otherwise destroying m would free l's nodes.
void appendList(list *l, list m) {
    node *src = m.head;

    for (int k = 0; k < m.size; k++) {        // count; do not stop at NULL
        node *copy = (node *)malloc(sizeof(node));
        copy->item = src->item;
        copy->next = NULL;
        copy->prev = l->tail;

        if (l->tail == NULL) l->head = copy;  // l was empty
        else l->tail->next = copy;
        l->tail = copy;
        l->size++;

        src = src->next;
    }
}
