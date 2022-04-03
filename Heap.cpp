#include "Heap.h"

Heap::Heap(int size) {
    Heap::size = size;
    count = 0;
    arr = new Node[size];
}

Heap::~Heap() {
    delete[] arr;
}

int Heap::getSize() {
    return size;
}

void Heap::insert(Node *node) {
    if (count == size) {
        cout << "Heap is full" << endl;
        return;
    }
    
    arr[count] = *node; // Notice: copy the node
    arr[count].setValue(node->getValue()*-1);
    count++;
    bubbleUp ();
}

int Heap::isEmpty() {
    return count == 0;
}

int Heap::peek() {
    if (isEmpty()) {
        cout << "Heap is empty" << endl;
        return(-1);
    }
    return -1*arr[0].getValue();
}

// printing by levels
void Heap::print() {
/* 
    a: index of the level in the heap. Root is at level 0.
    b: index of the column in the level. Root is at column 0.
    k: index of the node in the heap.
    (1<<a) = 2^a. Each row has 2^a nodes.
    (1<<a)-1 + b is the index of the node in the heap.
    k = (1<<a)-1 + b
    The height of the heap is log2(count)=log(count)/log(2).
*/
    int h = (int)(log(count)/log(2));
    
    for(int a=0;a <= h;a++){
        for(int b=0;b<(1<<a) && ((1<<a)-1+b)<count;b++){
            int k=(1<<a)-1+b;
            cout<<arr[k].getValue()<<" ";
        }
        cout << endl;
    }
}

Node* Heap::pull() {
    if (isEmpty()) {
        cout << "Heap is empty" << endl;
        return NULL;
    }
    Node *node = new Node(arr[0]);
    arr[0] = arr[count - 1];
    count--;
    bubbleDown();
    return node;
}

void Heap::swap(int i, int j) {
    Node temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

void Heap::bubbleUp(){
    int index = count - 1;
    int parentIndex =  (index - 1) / 2;
    while (index > 0 &&
        parentIndex >= 0 && 
        arr[index].getValue() > arr[parentIndex].getValue()) {
        swap(index, parentIndex);
        index = parentIndex;
        parentIndex =  (index - 1) / 2;
    }
}

void Heap::bubbleDown(){
    int index = 0;
    int leftChildIndex = 1;
    int rightChildIndex = 2;
    while (leftChildIndex < count) {
        // Find the largest child for swapping
        if (arr[leftChildIndex].getValue() > arr[index].getValue() || 
            arr[rightChildIndex].getValue() > arr[index].getValue()) {
            if (arr[leftChildIndex].getValue() > arr[rightChildIndex].getValue()) {
                swap(index, leftChildIndex);
                index = leftChildIndex; // Move to the left child
            } else {
                swap(index, rightChildIndex);
                index = rightChildIndex; // Move to the right child
            }
            // Update the child index
            leftChildIndex = index * 2 + 1;
            rightChildIndex = index * 2 + 2;        
        } else {
            break; // no need to bubble down
        }
    }
}

