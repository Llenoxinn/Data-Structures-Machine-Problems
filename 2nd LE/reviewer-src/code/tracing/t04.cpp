// libs:
class ArrayList {
    int items[8];
    int size;
public:
    ArrayList() { size = 0; for (int i = 0; i < 8; i++) items[i] = 0; }
    bool push_back(int x) {
        if (size == 8) return false;
        items[size++] = x;
        return true;
    }
    bool erase(int pos) {                     /* 0-based */
        if (pos < 0 || pos >= size) return false;
        for (int i = pos; i < size - 1; i++) items[i] = items[i + 1];
        size--;
        return true;
    }
    bool insert(int pos, int x) {             /* 0-based */
        if (size == 8 || pos < 0 || pos > size) return false;
        for (int i = size; i > pos; i--) items[i] = items[i - 1];
        items[pos] = x;
        size++;
        return true;
    }
    void raw() {
        printf("size=%d  [", size);
        for (int i = 0; i < 8; i++)
            printf("%d%s", items[i], i < 8 - 1 ? " " : "");
        printf("]\n");
    }
};

int main() {
    ArrayList l;
    for (int i = 1; i <= 6; i++) l.push_back(i * 10);
    l.raw();
    l.erase(1);
    l.raw();
    l.insert(3, 99);
    l.raw();
    int r = l.erase(5);
    r = r + l.erase(5);
    printf("%d\n", r);
    l.raw();
    l.insert(0, 7);
    l.insert(0, 8);
    l.raw();
    r = l.insert(9, 1);
    printf("%d ", r);
    r = l.insert(8, 1);
    printf("%d\n", r);
    l.raw();
    return 0;
}
