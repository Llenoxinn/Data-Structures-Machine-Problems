// Appends x at the end of a list that has no tail pointer.
// h is the address of the pointer that points to the rest of the list.
void append(snode **h, int x) {
    if (*h == NULL) {                // reached the end: put the node here
        snode *n = (snode *)malloc(sizeof(snode));
        n->item = x;
        n->next = NULL;
        *h = n;
    } else {                         // otherwise append to the rest
        append(&((*h)->next), x);
    }
}

// Bonus: the same with a loop. h walks from &head to the last next field.
void appendLoop(snode **h, int x) {
    while (*h != NULL) h = &((*h)->next);
    *h = (snode *)malloc(sizeof(snode));
    (*h)->item = x;
    (*h)->next = NULL;
}
