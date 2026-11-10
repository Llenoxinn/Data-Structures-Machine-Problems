// Rotates the list left by k places: [1 2 3 4 5], k = 2 -> [3 4 5 1 2].
void rotateLeft(sll *l, int k) {
    if (l->size == 0) return;
    k = k % l->size;
    if (k == 0) return;

    snode *newTail = l->head;                // the k-th node
    for (int i = 1; i < k; i++) newTail = newTail->next;

    l->tail->next = l->head;                 // old tail points to old head
    l->head = newTail->next;                 // the node after becomes head
    newTail->next = NULL;
    l->tail = newTail;
}
