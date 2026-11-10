// Puts the nodes at odd positions (1st, 3rd, ...) before those at even
// positions: [1 2 3 4 5] -> [1 3 5 2 4]. Positions, not values.
void oddEvenList(sll *l) {
    if (l->head == NULL || l->head->next == NULL) return;

    snode *odd = l->head;                // last node of the odd chain
    snode *even = l->head->next;         // last node of the even chain
    snode *evenHead = even;
    while (even->next != NULL) {
        odd->next = even->next;          // odd chain takes the next odd node
        odd = odd->next;
        even->next = odd->next;          // even chain takes the next even node
        if (even->next != NULL) even = even->next;
    }
    odd->next = evenHead;                // odd chain, then even chain
    l->tail = even;                      // the even chain ends the whole list
}
