#include "Maze.h"
#include <ctime>

int main() {
    unsigned t0, t1;
    int n, option, k, perc;
    double time;
    cout<< "Enter one number that will be distance of the maze: ";
    cin >> n;
    cout << "Enter void percentage of the maze: ";
    cin >> perc;
    Maze m(n, perc);
    double acum = 0;
    for (int i = 0; i < 100; i++){
        t0 = clock();
        m.solve();
        t1 = clock();
        time = (double(t1 - t0) / CLOCKS_PER_SEC);
        cout << "["<<i+1<<"]" <<"Solved in: " << time << "[s] - "<< endl;
        acum += time;
        m.generate();
    }
    cout << "Average time to solve: " << acum/100 << "[s]" << endl;
    return 0;
}