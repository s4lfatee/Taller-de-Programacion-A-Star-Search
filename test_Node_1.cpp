#include "Node.h"

int main(){
    Node *node = new Node(1, 1, 1, NULL);
    cout << node->get_i() << endl;
    cout << node->get_j() << endl;
    cout << node->getValue() << endl;
    node->print();

    Node *othernode = new Node(2, 2, 2, node);
    othernode->setValue(19);
    cout << othernode->getPath() << endl;

    return 0;
}