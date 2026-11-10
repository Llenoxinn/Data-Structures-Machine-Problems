// libs:
typedef struct { int items[5]; int size; } list;

void init(list *l) { l->size = 0; }
int append(list *l, int x) {
    if (l->size == 5) return 0;
    l->items[l->size++] = x;
    return 1;
}
int insertFront(list *l, int x) {
    int i;
    if (l->size == 5) return 0;
    for (i = l->size; i > 0; i--) l->items[i] = l->items[i - 1];
    l->items[0] = x;
    l->size++;
    return 1;
}
int removeFirst(list *l) {
    int i;
    if (l->size == 0) return 0;
    for (i = 0; i < l->size - 1; i++) l->items[i] = l->items[i + 1];
    l->size--;
    return 1;
}
int removeLast(list *l) { if (l->size == 0) return 0; l->size--; return 1; }
int setItem(list *l, int x, int p) {          /* p is 1-based */
    if (p < 1 || p > l->size) return 0;
    l->items[p - 1] = x;
    return 1;
}
int itemAt(list l, int p) { return l.items[p - 1]; }
void display(list l) {
    int i;
    for (i = 0; i < l.size; i++) printf("%d ", l.items[i]);
    printf("\n");
}

int main() {
    list l;
    int r;
    init(&l);
    r = append(&l, 4);
    r = r + append(&l, 8);
    r = r + append(&l, 15);
    printf("%d\n", r);
    r = insertFront(&l, 16);
    r = r * 10 + insertFront(&l, 23);
    printf("%d\n", r);
    printf("%d\n", append(&l, 42));
    display(l);
    removeLast(&l);
    removeFirst(&l);
    display(l);
    r = setItem(&l, 99, 3);
    printf("%d ", r);
    r = setItem(&l, 77, 4);
    printf("%d\n", r);
    printf("%d\n", itemAt(l, 4));
    append(&l, 5);
    display(l);
    printf("%d\n", itemAt(l, 4));
    return 0;
}
