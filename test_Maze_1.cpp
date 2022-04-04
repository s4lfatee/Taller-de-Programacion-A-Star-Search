#include "Maze.h"

int main() {
    Maze m(100, 80);
    m.print();
    m.solve(); // Solve the maze
    return 0;
}