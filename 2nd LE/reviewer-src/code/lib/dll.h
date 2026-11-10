typedef struct node {
    int item;
    struct node *next;
    struct node *prev;
} node;

typedef struct {
    node *head;
    node *tail;
    int size;
} list;

void init(list *l) {
    l->head = NULL;
    l->tail = NULL;
    l->size = 0;
}

// Adds x at the tail. Returns 1 on success, 0 if malloc fails.
int append(list *l, int x) {
    node *n = (node *)malloc(sizeof(node));
    if (n == NULL) return 0;
    n->item = x;
    n->next = NULL;
    n->prev = l->tail;
    if (l->tail == NULL) l->head = n;
    else l->tail->next = n;
    l->tail = n;
    l->size++;
    return 1;
}

// Prints head to tail, separated by spaces.
void display(list *l) {
    node *c;
    for (c = l->head; c != NULL; c = c->next) {
        printf("%d", c->item);
        if (c->next != NULL) printf(" ");
    }
    printf("\n");
}

// Prints tail to head, separated by spaces.
void displayBackward(list *l) {
    node *c;
    for (c = l->tail; c != NULL; c = c->prev) {
        printf("%d", c->item);
        if (c->prev != NULL) printf(" ");
    }
    printf("\n");
}

void destroy(list *l) {
    node *c = l->head;
    while (c != NULL) {
        node *nxt = c->next;
        free(c);
        c = nxt;
    }
    init(l);
}
