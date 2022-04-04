#include "Container.h"
#include <stdlib.h>
#include <time.h>

int main() {
    int n=20;
    srand(time(NULL));
    Container h(n);

    // inserting random numbers
    for(int i = 0; i < n; i++) {
        int val=rand()%n;
        Node *node = new Node(i, i, val, NULL);
        cout<<"inserting "<<val<<endl;
        h.insert(node);
        delete node;
    }

    // printing heap
    cout << "The Heap" <<endl;
    h.print();

    cout << h.peek() <<endl;
 }