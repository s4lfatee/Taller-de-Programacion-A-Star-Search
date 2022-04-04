#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "Container.h"
#include "Mark.h"
#include <cstdlib>
using namespace std;

// best practice:
#define IN_DOOR 2
#define OUT_DOOR 3
#define WALL 1
#define EMPTY 0
#define VISITED 4
// Both of the following are used to print the path in green colour!
#define BOLDGREEN   "\033[1m\033[32m"   
#define RESET   "\033[0m"

class Maze {
public: 
    Maze(int dim, int p);
    ~Maze();
    void print();
    void solve(); // solve best path
    void generate(); // generate random maze
    bool isValid(int i, int j);
    int EuclideanDistance(int i, int j);
    void markPath(Node *node);
private:
    int dim;
    int **arr;
    int void_percentage;
};