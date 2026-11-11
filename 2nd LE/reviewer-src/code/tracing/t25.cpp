// libs: sol/p51.cpp
void forward(LinkedDeque d) {
    for (dqnode *c = d.sentinel->next; c != d.sentinel; c = c->next)
        printf("%d ", c->item);
    printf("| size %d\n", d.size());
}

int main() {
    LinkedDeque d;
    printf("%d %d\n", d.sentinel->next == d.sentinel, d.size());
    d.push_back(1); d.push_back(2); d.push_front(0); d.push_back(3);
    forward(d);
    printf("%d ", d.back());  d.pop_back();
    printf("%d\n", d.front()); d.pop_front();
    forward(d);
    printf("%d %d\n", d.sentinel->prev->item, d.sentinel->next->prev == d.sentinel);

    LinkedDeque e = d;                 // copies the members: the sentinel POINTER
    printf("%d %d\n", e.sentinel == d.sentinel, e.size());   // and the count
    d.push_front(9);
    printf("%d %d %d\n", d.front(), e.front(), e.size());
    d.clear();
    printf("%d %d %d\n", d.size(), e.size(), e.sentinel->next == e.sentinel);
    return 0;
}
