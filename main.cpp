#include "Maze.h"
#include <ctime>

// main function of the whole assignment, it will measure the average time to solve 100 mazes

int main() {
    unsigned t0, t1;
    int iterations;
    double time;
    cout << "Please enter the amount of iterations to execute: ";
    cin >> iterations;
    Maze m(1000, 90);
    double acum = 0; // acumulated time in double type for time accuracy
    for (int i = 0; i < iterations; i++){
        t0 = clock();
        m.solve();
        t1 = clock();
        time = (double(t1 - t0) / CLOCKS_PER_SEC);
        cout << "["<<i+1<<"]" <<"Solved in: " << time << "[s] - "<< endl;
        acum += time;
        m.generate(); // create another maze to solve for the next iteration
    }
    cout << "Average time to solve: " << acum/iterations << "[s]" << endl;
    return 0;
}
