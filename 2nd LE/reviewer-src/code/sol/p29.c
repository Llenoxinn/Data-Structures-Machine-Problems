// Returns 1 if the list starting at head has a cycle, 0 otherwise.
// Floyd: if fast ever meets slow, there is a cycle.
int hasCycle(snode *head) {
    snode *slow = head;
    snode *fast = head;
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) return 1;
    }
    return 0;
}

// Bonus: returns the first node of the cycle, or NULL if there is none.
snode *cycleStart(snode *head) {
    snode *slow = head;
    snode *fast = head;
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {
            snode *p = head;             // walk from the head and from the meeting
            while (p != slow) {          // point; they meet at the cycle start
                p = p->next;
                slow = slow->next;
            }
            return p;
        }
    }
    return NULL;
}
