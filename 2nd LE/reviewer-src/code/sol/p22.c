// Keeps one node for each value of a sorted list.
void removeDuplicates(list *l) {
    node *cur = l->head;
    while (cur != NULL && cur->next != NULL) {
        if (cur->next->item == cur->item) {
            node *dup = cur->next;            // unlink the duplicate
            cur->next = dup->next;
            if (dup->next != NULL) dup->next->prev = cur;
            else l->tail = cur;
            free(dup);
            l->size--;
        } else {
            cur = cur->next;                  // advance only when no removal
        }
    }
}
