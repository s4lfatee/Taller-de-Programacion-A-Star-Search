#include "Node.h"

Node::Node() {
    this->i = 0;
    this->j = 0;
    this->value = 0;
    this->depth = -1;
    this->previous = NULL;
}

Node::Node(Node* node) {
    this->i = node->i;
    this->j = node->j;
    this->value = node->value;
    this->depth = node->depth;
    this->previous = node->previous;
}

Node::Node(int i, int j, int value, Node* parent) {
    this->i = i;
    this->j = j;
    this->value = value;
    this->previous = parent;
}

Node::~Node () {
}

int Node::get_i() {
    return this->i;
}

int Node::get_j() {
    return this->j;
}

Node* Node::getPrevious() {
    return this->previous;
}

int Node::getValue() {
    return this->value;
}

void Node::setPrevious(Node* previous) {
    this->previous = previous;
}

void Node::setDepth(int depth) {
    this->depth = depth;
}

int Node::isRoot() {
    return this->previous == NULL;
}

void Node::print() {
    cout << "(" << this->i << "," << this->j << ")[" << this->value << "]" << endl;
}

int Node::getDepth() {
    return(this->depth);    
}

// the path from the root to the current node as a string
string Node::getPath() {
    string s="("+to_string(this->i)+","+to_string(this->j)+")";
    if (this->previous != NULL) {
        s=s+this->previous->getPath();
    }
    return(s); 
}

void Node::setValue(int value) {
    this->value = value;
}