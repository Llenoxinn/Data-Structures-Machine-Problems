// libs: lib/dll.h sol/p13.c
int main() {
    int v[] = {2, 2, 5, 2, 7, 2, 2}, i;
    list l;
    init(&l);
    for (i = 0; i < 7; i++) append(&l, v[i]);
    eraseItems(&l, 2);
    display(&l);
    printf("size=%d head=%d tail=%d\n", l.size, l.head->item, l.tail->item);
    displayBackward(&l);
    eraseItems(&l, 9);
    printf("size=%d\n", l.size);
    eraseItems(&l, 7);
    printf("size=%d head=%d tail=%d ", l.size, l.head->item, l.tail->item);
    printf("prev=%d\n", l.tail->prev == NULL);
    eraseItems(&l, 5);
    printf("size=%d ", l.size);
    printf("headIsNULL=%d tailIsNULL=%d\n", l.head == NULL, l.tail == NULL);
    return 0;
}
