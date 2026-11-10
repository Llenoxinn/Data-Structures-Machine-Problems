// libs: lib/dll.h sol/p14.c
// The test program around appendList (reconstructed from the sample output).
int main() {
    int n, item;
    list l, m;
    while (scanf("%d", &n) == 1) {
        init(&l);
        init(&m);
        for (int i = 0; i < n; i++) { scanf("%d", &item); append(&l, item); }
        scanf("%d", &n);
        for (int i = 0; i < n; i++) { scanf("%d", &item); append(&m, item); }
        printf("list l:\n");
        display(&l);
        printf("list m:\n");
        display(&m);
        appendList(&l, m);
        destroy(&m);              // l must not be affected
        display(&l);
        destroy(&l);
        printf("----\n");
    }
    return 0;
}
