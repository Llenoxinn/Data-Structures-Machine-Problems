// libs: lib/sll.h sol/p18.c
int main() {
    sll a, b, c, d;
    int r;
    sinit(&a); sinit(&b); sinit(&c); sinit(&d);
    for (int i = 1; i <= 5; i++) pushBack(&a, i);          // 1 2 3 4 5
    for (int i = 1; i <= 3; i++) pushBack(&b, i * 10);     // 10 20 30
    for (int i = 7; i <= 9; i++) pushBack(&c, i);          // 7 8 9
    pushBack(&d, 100);
    splice(&a, 2, &b);
    sdisplay(&a); sdisplay(&b);
    printf("%d %d\n", a.size, b.size);
    spliceAfter(&a, a.head->next->next, &c);
    sdisplay(&a); sdisplay(&c);
    printf("%d %d tail=%d\n", a.size, c.size, a.tail->item);
    r = splice(&a, 99, &d);
    printf("%d %d\n", r, d.size);
    r = splice(&a, a.size, &d);
    sdisplay(&a);
    printf("%d %d tail=%d\n", r, a.size, a.tail->item);
    return 0;
}
