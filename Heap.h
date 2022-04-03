#include <iostream>
#include <math.h>
#include "Node.h"
using namespace std;

/*
Please document your code here.
*/    
class Heap {
public:
    Heap(int size);
    ~Heap();
    int isEmpty();
    void insert(Node *node);
    Node* pull();
    int peek();
    int getSize();
    void print();
private:
    Node *arr;
    int size;
    int count;
    void swap(int i, int j);
    void bubbleUp();
    void bubbleDown();
};
