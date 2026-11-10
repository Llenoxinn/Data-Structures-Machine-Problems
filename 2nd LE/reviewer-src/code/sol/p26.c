// Moves nodes with item < x in front of the others; order inside each group
// is kept. Two chains are built and joined; no node is created.
void partitionList(sll *l, int x) {
    snode smallDummy;                // dummy heads remove the empty cases
    snode bigDummy;
    snode *small = &smallDummy;      // last node of each chain
    snode *big = &bigDummy;
    smallDummy.next = NULL;
    bigDummy.next = NULL;

    snode *cur = l->head;
    while (cur != NULL) {
        if (cur->item < x) {
            small->next = cur;
            small = cur;
        } else {
            big->next = cur;
            big = cur;
        }
        cur = cur->next;
    }
    big->next = NULL;                // end of the second chain
    small->next = bigDummy.next;     // join the two chains

    l->head = smallDummy.next;
    if (big != &bigDummy) l->tail = big;
    else if (small != &smallDummy) l->tail = small;
    else l->tail = NULL;
}
