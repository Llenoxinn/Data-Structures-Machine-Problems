// Moves all nodes of m into l, right after node p (p == NULL: at the front).
// No node is created or freed; only pointers change. m becomes empty.
void spliceAfter(sll *l, snode *p, sll *m) {
    if (m->head == NULL) return;                 // nothing to move

    snode *after = (p == NULL) ? l->head : p->next;
    if (p == NULL) l->head = m->head;            // spliced at the front
    else p->next = m->head;
    m->tail->next = after;
    if (after == NULL) l->tail = m->tail;        // spliced at the end

    l->size = l->size + m->size;
    m->head = NULL;
    m->tail = NULL;
    m->size = 0;
}

// Same, but pos nodes of l stay in front (0 <= pos <= size).
// Returns 0 if pos is invalid.
int splice(sll *l, int pos, sll *m) {
    if (pos < 0 || pos > l->size) return 0;
    snode *p = NULL;                             // the node at index pos - 1
    if (pos > 0) {
        p = l->head;
        for (int i = 1; i < pos; i++) p = p->next;
    }
    spliceAfter(l, p, m);
    return 1;
}
