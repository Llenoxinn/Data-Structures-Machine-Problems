// libs:
typedef struct node { int item; struct node *next; } node;

void appendA(node *h, int x) {           /* single pointer */
    node *n = (node *)malloc(sizeof(node));
    n->item = x; n->next = NULL;
    if (h == NULL) { h = n; return; }
    while (h->next != NULL) h = h->next;
    h->next = n;
}
void appendB(node **h, int x) {          /* double pointer */
    node *n = (node *)malloc(sizeof(node));
    n->item = x; n->next = NULL;
    if (*h == NULL) { *h = n; return; }
    node *cur = *h;
    while (cur->next != NULL) cur = cur->next;
    cur->next = n;
}
int length(node *h) { return h == NULL ? 0 : 1 + length(h->next); }

int main() {
    node *a = NULL, *b = NULL, *c = NULL, *d = NULL;
    for (int i = 1; i <= 3; i++) { appendA(a, i); appendB(&b, i); }
    printf("%d %d\n", length(a), length(b));
    appendB(&c, 7);
    appendB(&d, 7);
    for (int i = 1; i <= 3; i++) { appendA(c, i); appendB(&d, i); }
    printf("%d %d\n", length(c), length(d));
    return 0;
}
