// libs: lib/stackqueue.h sol/p37.c
// show() looks inside the two stacks only to print them (bottom to top).
void show(stockSpanner *s) {
    printf("[");
    for (int i = 0; i < s->prices.size; i++)
        printf("%s%d:%d", i ? " " : "", s->prices.items[i], s->spans.items[i]);
    printf("]\n");
}

int main() {
    int p[] = {100, 80, 60, 70, 60, 75, 85, 85};
    stockSpanner s;
    ssInit(&s);
    for (int i = 0; i < 8; i++) {
        int span = ssNext(&s, p[i]);
        printf("%3d -> %d  ", p[i], span);
        show(&s);
    }
    return 0;
}
