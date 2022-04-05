#include "Node.h"

int main(){
    Node *node = new Node(1, 1, 1, NULL); // Create a node
    cout << node->get_i() << node->get_j() << endl;  // Print the i and j axis of the node
    cout << node->getValue() << endl; // Print the value of the node
    node->print();
    Node *othernode = new Node(2, 2, 2, node); // Create another node and link it to the first node
    othernode->setValue(19);
    cout << othernode->getPath() << endl; // Trace back to the previous node
    cout << othernode->getPrevious() << endl;
    othernode->setDepth(2);
    cout <<  othernode->getDepth() << endl;

    if (othernode->isRoot()){
        cout << "This node is the root" << endl;
    }
    else{
        cout << "This node is not the root" << endl;
    }
    
    Node *thirdnode = new Node(3, 3, 3, othernode);
    thirdnode->setPrevious(node);
    cout << thirdnode->getPath() << endl;
    return 0;
}