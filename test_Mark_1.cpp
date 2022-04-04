#include "Mark.h"

int main(){
    Mark c(50);
    // Set both 1,1 and 5,10 to be visited
    c.setVisited(1,1);
    c.setVisited(5,10);
    // Print the matrix
    c.print();

    // Print the visited state of 1,1
    if (c.isVisited(1,1)){
        cout << "Visited" << endl;
    }
    else{
        cout << "Not visited" << endl;
    }
    return 0;
}