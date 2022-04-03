#include "Maze.h"
#include <ctime>


int main(){
    unsigned t0, t1;

    double time;
    Maze m(1000, 90);
    t0 = clock();
    m.solve();
    t1 = clock();
    time = (double(t1 - t0) / CLOCKS_PER_SEC);
    cout << "Solved in: " << time << "[s]" << endl;
}
