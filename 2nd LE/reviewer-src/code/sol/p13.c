// Removes every node whose item equals x from the doubly linked list.
void eraseItems(list *l, int x) {
    node *cur = l->head;

    while (cur != NULL) {
        node *nxt = cur->next;       // save it: cur may be freed below

        if (cur->item == x) {
            // make the node before cur skip it (or move the head)
            if (cur->prev != NULL) cur->prev->next = cur->next;
            else l->head = cur->next;

            // make the node after cur skip it (or move the tail)
            if (cur->next != NULL) cur->next->prev = cur->prev;
            else l->tail = cur->prev;

            free(cur);
            l->size--;
        }
        cur = nxt;
    }
}
