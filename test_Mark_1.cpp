#include "Mark.h"

int main(){
    Mark c(50);
    c.setVisited(1,1);
    c.setVisited(5,10);
    c.print();

    if (c.isVisited(1,1)){
        cout << "Visited" << endl;
    }
    else{
        cout << "Not visited" << endl;
    }
    return 0;
}