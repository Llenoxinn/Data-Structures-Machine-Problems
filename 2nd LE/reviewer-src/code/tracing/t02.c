// libs:
typedef struct { int items[3]; int size; } alist;          /* array inside   */
typedef struct node { int item; struct node *next; } node;
typedef struct { node *head; int size; } slist;            /* pointer inside */

void arrByValue(alist l) { l.items[0] = 100; l.size = 9; }
void arrByPtr(alist *l)  { l->items[0] = 100; l->size = 9; }
void rawArray(int a[])   { a[0] = 100; }
void llByValue(slist l)  { l.head->item = 100; l.head = NULL; l.size = 0; }

int main() {
    alist a = {{1, 2, 3}, 3};
    int raw[3] = {1, 2, 3};
    slist s;
    node *n2 = (node *)malloc(sizeof(node));
    node *n1 = (node *)malloc(sizeof(node));
    n2->item = 2; n2->next = NULL;
    n1->item = 1; n1->next = n2;
    s.head = n1; s.size = 2;

    arrByValue(a);
    printf("A: %d %d\n", a.items[0], a.size);
    arrByPtr(&a);
    printf("B: %d %d\n", a.items[0], a.size);
    a.items[0] = 1; a.size = 3;
    rawArray(a.items);
    printf("C: %d %d\n", a.items[0], a.size);
    rawArray(raw);
    printf("D: %d\n", raw[0]);
    llByValue(s);
    printf("E: %d %d %d\n", s.head == NULL, s.size, n1->item);
    return 0;
}
