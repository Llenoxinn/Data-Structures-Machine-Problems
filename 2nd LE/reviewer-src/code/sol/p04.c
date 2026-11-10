typedef struct { int items[100]; int size; } slist;

// Index of the first item >= x (size if every item is smaller).
int lowerBound(slist *l, int x) {
    int lo = 0;
    int hi = l->size;
    while (lo < hi) {
        int mid = lo + (hi - lo) / 2;
        if (l->items[mid] < x) lo = mid + 1;
        else hi = mid;
    }
    return lo;
}

// Index of the first item > x (size if no item is larger).
int upperBound(slist *l, int x) {
    int lo = 0;
    int hi = l->size;
    while (lo < hi) {
        int mid = lo + (hi - lo) / 2;
        if (l->items[mid] <= x) lo = mid + 1;
        else hi = mid;
    }
    return lo;
}

// Index of the first occurrence of x, or -1.
int search(slist *l, int x) {
    int p = lowerBound(l, x);
    if (p < l->size && l->items[p] == x) return p;
    return -1;
}

// Inserts x so the list stays sorted. Returns 0 if the list is full.
int insert(slist *l, int x) {
    if (l->size == 100) return 0;
    int p = upperBound(l, x);                 // slot after equal items
    for (int i = l->size; i > p; i--) {       // shift the tail right
        l->items[i] = l->items[i - 1];
    }
    l->items[p] = x;
    l->size++;
    return 1;
}

// Removes one occurrence of x. Returns 1 if x was found, else 0.
int erase(slist *l, int x) {
    int p = search(l, x);
    if (p == -1) return 0;
    for (int i = p; i < l->size - 1; i++) {   // shift the tail left
        l->items[i] = l->items[i + 1];
    }
    l->size--;
    return 1;
}

// Number of occurrences of x in O(log n).
int count(slist *l, int x) {
    return upperBound(l, x) - lowerBound(l, x);
}
