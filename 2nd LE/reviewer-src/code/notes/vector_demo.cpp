// libs: listings/intvector.cpp
int main() {
    IntVector v;
    for (int i = 1; i <= 20; i++) {
        v.push_back(i);
        printf("%d/%d%s", v.size(), v.capacity(), i % 10 == 0 ? "\n" : " ");
    }
    for (int i = 1; i <= 20; i++) {
        v.pop_back();
        printf("%d/%d%s", v.size(), v.capacity(), i % 10 == 0 ? "\n" : " ");
    }
    return 0;
}
