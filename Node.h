#include <iostream>

using namespace std;

// Node class that represents a cell state in the maze
// contains i and j axis coordinates, an heuristic value (in maze context) and a pointer to the previous node

class Node {
public:
    Node();
    ~Node();
    Node(Node* node);
    Node(int i, int j, int value, Node* previous);

    // NOT best practice to have a getter for the private member!
    int get_i();
    int get_j();
    Node *getPrevious();
    int getValue();
    int getDepth();
    
    // NOT best practice to have a getter for the private member!
    void setPrevious(Node *previous);
    void setDepth(int depth);
    void setValue(int value);
    
    // main methods
    int isRoot();
    string getPath(); // Traces back the path by accessing the previous nodes
    void print();

private:
    // particular variables of this problem
    int i; // row
    int j; // column
    int value; // a value representing a cost for choosing this node
    int depth; // the depth of this node in the tree

    // structural variables: meaning relationships between nodes
    Node *previous; // the previous node in the path
};  // end class Node

