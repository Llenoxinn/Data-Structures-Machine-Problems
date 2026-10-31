#include <iostream>
#include "arrayOfLight.h"

int main() {
    int t;
    int items[20];
    std::cin >> t;
    while(t--) {
        array araykopo;
        int n;
        std::cin >> n;
        for(int i=0;i<n; i++) {
            int val;
            std::cin>>val;
            araykopo.append(val);
        }
        int c;
        std::cin >> c;
        switch(c) {
            case 1: {
                int a;
                std::cin >> a;
                araykopo.append(a);
                araykopo.display();
                break;
            }
            case 2: {
                int a;
                std::cin >> a;
                araykopo.insertFront(a);
                araykopo.display();
                break;
            }
            case 3: {
                int a, b;
                std::cin >> a >> b;
                araykopo.insert(a, b);
                araykopo.display();
                break;
            }
            case 4: {
                int a;
                std::cin >> a;
                araykopo.rem(a);
                araykopo.display();
                break;
            }
            default:
                break;
        }
    }
    return 0;
}

array::array() {
    size = 0;
}

int array::getItem(int p) {
    if(p>=0 && p<size) return items[p];
    return -1;
}

bool array::setItem(int x, int p) {
    if(p>=0 && p<size) {
        items[p]=x;
        return true;
    }
    return false;
}

bool array::insert(int x, int p) {
    if(size>=MAX || p<0 || p > size) return false;
    for(int i = size; i>p; i--) {
        items[i] = items[i-1];
    }
    items[p]=x;
    size++;
    return true;
}

bool array::append(int x) {
    if(size>=MAX) return false;
    items[size++]=x;
    return true;
}

bool array::insertFront(int x) {
    if(size>=MAX) return false;
    for(int i=size;i>0;i--) {
        items[i]=items[i-1];
    }
    items[0] = x;
    size++;
    return true;
}

int array::getSize() {
    return size;
}

void array::display() {
    for(int i = 0; i<size; i++) {
        std::cout << items[i] << " ";
    }
    std::cout << std::endl;
}

int array::rem(int p) {
    if(p<0||p>=size) return -1;
    else {
        int rVal = items[p];
        for(int i = p; i<size-1; i++) {
            items[i] = items[i+1];
        }
        size--;
        return rVal;
    }
}