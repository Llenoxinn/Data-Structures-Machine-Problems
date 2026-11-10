// libs: lib/dll.h sol/p13.c
// The test program around eraseItems (reconstructed from the sample output).
// It processes test cases until the end of the input.
int main() {
    int n, x, item;
    list l;
    while (scanf("%d", &n) == 1) {
        init(&l);
        for (int i = 0; i < n; i++) {
            scanf("%d", &item);
            append(&l, item);
        }
        scanf("%d", &x);
        display(&l);
        eraseItems(&l, x);
        display(&l);
        printf("New size: %d\n", l.size);
        printf("Displaying from tail down to head:\n");
        displayBackward(&l);
        if (l.size == 0) {
            if (l.head == NULL && l.tail == NULL)
                printf("Yes, correct. Both the head and tail are NULL.\n");
            else
                printf("Wrong! The head or tail is not NULL.\n");
        }
        destroy(&l);
        printf("----\n");
    }
    return 0;
}
