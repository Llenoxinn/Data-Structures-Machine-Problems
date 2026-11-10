typedef struct snode {
    int item;
    struct snode *next;
} snode;

typedef struct {
    snode *head;
    snode *tail;
    int size;
} sll;

void sinit(sll *l) {
    l->head = NULL;
    l->tail = NULL;
    l->size = 0;
}

// Adds x at the back. Returns 1 on success, 0 if malloc fails.
int pushBack(sll *l, int x) {
    snode *n = (snode *)malloc(sizeof(snode));
    if (n == NULL) return 0;
    n->item = x;
    n->next = NULL;
    if (l->tail == NULL) l->head = n;
    else l->tail->next = n;
    l->tail = n;
    l->size++;
    return 1;
}

// Adds x at the front. Returns 1 on success, 0 if malloc fails.
int pushFront(sll *l, int x) {
    snode *n = (snode *)malloc(sizeof(snode));
    if (n == NULL) return 0;
    n->item = x;
    n->next = l->head;
    l->head = n;
    if (l->tail == NULL) l->tail = n;
    l->size++;
    return 1;
}

// Prints the list as [1 2 3].
void sdisplay(sll *l) {
    snode *c;
    printf("[");
    for (c = l->head; c != NULL; c = c->next) {
        printf("%d", c->item);
        if (c->next != NULL) printf(" ");
    }
    printf("]\n");
}

void sdestroy(sll *l) {
    snode *c = l->head;
    while (c != NULL) {
        snode *nxt = c->next;
        free(c);
        c = nxt;
    }
    sinit(l);
}
