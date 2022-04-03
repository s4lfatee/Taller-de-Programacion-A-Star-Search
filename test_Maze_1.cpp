#include "Maze.h"

int main() {
    Maze m(100, 80);
    m.print();
    m.solve();
    return 0;
}