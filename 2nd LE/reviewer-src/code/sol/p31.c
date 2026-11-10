// Adds two numbers stored as lists of digits, least significant digit first.
// [2 4 3] + [5 6 4] -> [7 0 8]   (342 + 465 = 807). The sum goes to *out.
void addNumbers(sll *a, sll *b, sll *out) {
    snode *x = a->head;
    snode *y = b->head;
    int carry = 0;
    sinit(out);

    while (x != NULL || y != NULL || carry > 0) {
        int sum = carry;
        if (x != NULL) {
            sum = sum + x->item;
            x = x->next;
        }
        if (y != NULL) {
            sum = sum + y->item;
            y = y->next;
        }
        pushBack(out, sum % 10);
        carry = sum / 10;
    }
}
