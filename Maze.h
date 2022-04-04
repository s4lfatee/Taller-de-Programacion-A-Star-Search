#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "Container.h"
#include "Mark.h"
#include <cstdlib>
using namespace std;

// Numeric constants
#define IN_DOOR 2
#define OUT_DOOR 3
#define WALL 1
#define EMPTY 0
#define VISITED 4

// Maze class that represents the maze that needs to be solved using the A* algorithm
// It consists of a matrix that randomly generates "walls" and "doors"

class Maze {
public: 
    Maze(int dim, int p);
    ~Maze();
    void print(); // Prints the maze using symbols (WALL: #, EMPTY: , IN_DOOR: E, OUT_DOOR: S)
    void solve(); // solves the maze for the best path using the A* algorithm
    void generate(); // generates random maze
    bool isValid(int i, int j); // Checks if the maze cell is within bounds
    int EuclideanDistance(int i, int j); // Heuristic used for A*
private:
    int dim;
    int **arr;
    int void_percentage;
};