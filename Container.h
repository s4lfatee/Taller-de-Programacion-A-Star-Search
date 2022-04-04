#include <iostream>
#include <math.h>
#include "Node.h"
using namespace std;


// Container class that implements a Min-Heap of Nodes
// It is one of the main tools for solving the maze because it is a priority queue

class Container {
public:
    Container(int size);
    ~Container();
    int isEmpty();
    void insert(Node *node);
    Node* pull(); // Pulls the node with the lowest value (Min-heap property) and returns it
    int peek(); // Returns the value of the node with the lowest value (Min-heap property)
    int getSize();
    void print(); // Print method for testing purposes
private:
    Node *arr; // The heap is implemented as an array
    int size; // The size of the heap
    int count; // The number of nodes in the heap

    // These methods are use to sort and set the heap's order
    void swap(int i, int j);
    void bubbleUp();
    void bubbleDown();
};
