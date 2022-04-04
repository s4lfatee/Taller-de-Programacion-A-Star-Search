#include "Node.h"

int main(){
    Node *node = new Node(1, 1, 1, NULL); // Create a node
    cout << node->get_i() << node->get_j() << endl;  // Print the i and j axis of the node
    cout << node->getValue() << endl; // Print the value of the node
    node->print();
    Node *othernode = new Node(2, 2, 2, node); // Create another node and link it to the first node
    othernode->setValue(19);
    cout << othernode->getPath() << endl; // Trace back to the previous node
    return 0;
}