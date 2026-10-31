#include <iostream>
#define MAX 20

class array{
private:
    int items[MAX], size;
public:
    array();
    int getItem(int);
    bool setItem(int,int);
    bool insert(int,int);
    bool append(int);
    bool insertFront(int);
    int getSize();
    void display();
    int rem(int);
};