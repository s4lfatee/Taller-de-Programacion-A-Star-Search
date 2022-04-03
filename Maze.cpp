#include "Maze.h"

// Maze class used to generate and solve a maze (Represented as a matrix) with A* search algorithm

Maze::Maze(int dim, int p) {
    srand(time(NULL)); // set seed for random number generator
    Maze::dim = dim;
    Maze::void_percentage=p;
    Maze::generate();
}

Maze::~Maze() {
    for (int i = 0; i < dim; i++) {
        delete[] arr[i];
    }
    delete[] arr;
}

// Creates the maze by randomly assigning walls and voids given the void percentage
void Maze::generate() {
    arr = new int*[dim];
    for (int i = 0; i < dim; i++) {
        arr[i] = new int[dim];
        for (int j = 0; j < dim; j++) {
            arr[i][j] = rand() % 100 < void_percentage ? EMPTY : WALL;
        }
    }

    // set the entrance and exit 
    
    arr[0][0] = IN_DOOR;
    arr[dim-1][dim-1] = OUT_DOOR;
}

// Prints the maze using symbols
void Maze::print(){
    for (int i = 0; i < dim; i++){
        for (int j = 0; j < dim; j++){
            if (arr[i][j] == WALL){
                cout << "#";
            }
            else if (arr[i][j] == IN_DOOR){
                cout << "E";
            }
            else if (arr[i][j] == OUT_DOOR){
                cout << "S";
            }
            else if (arr[i][j] == EMPTY){
                cout << " ";
            }
            else if (arr[i][j] == VISITED){
                cout << BOLDGREEN << "O" << RESET;
            }
        }
        cout << "\n";
    }
}

// Checks if the maze cell is within bounds
bool Maze::isValid(int i, int j){
    if (i < 0 || i >= dim || j < 0 || j >= dim){
        return false;
    }
    return true;
}

void Maze::markPath(Node *node){
    while (node->getPrevious() != NULL){
        int i = node->get_i();
        int j = node->get_j();
        arr[i][j] = VISITED;
        node = node->getPrevious();
    }
}


// Euclidean Distance is our heuristic of choice (There are many others like Manhattan Distance or Diagonal Distance)
int Maze::EuclideanDistance(int i, int j){
    return sqrt(pow(i - dim-1, 2) + pow(j - dim-1, 2));
}   


// Solves the maze using A* algorithm
void Maze::solve(){
    // Heap that will allow us to get the node with the lowest heuristic value
    Heap *open = new Heap(dim*dim);
    // Container that will check if a cell has been visited through a matrix
    Container *closed = new Container(dim);

    // set the entrance
    Node *start = new Node(0, 0, 0, NULL);
    open->insert(start);

    while(!(open->isEmpty())){
        Node *currentNode = open->pull();
        // Check if the current node is the exit, this way we can break out of the while loop and get our path
        if (isValid(currentNode->get_i(), currentNode->get_j())){
            if (arr[currentNode->get_i()][currentNode->get_j()] == OUT_DOOR){
                // It means that we found the exit
                
                // Set the entrance to IN_DOOR for printing purposes (Entrance gets overwritten by a visited node, so this way we will be able to recognize the entrance)
                arr[0][0] = IN_DOOR;
                // Set the exit to OUT_DOOR for printing purposes (Exit gets overwritten by a visited node, so this way we will be able to recognize the exit)
                arr[dim-1][dim-1] = OUT_DOOR;
                // Then we go backwards using every previous node from the current node, so this way we can highlight our path using print()
                markPath(currentNode);
                // If you wish to see the maze solution, uncomment the following lines:
                //cout << currentNode->getPath() << endl;
                //print();
                cout << "Path found!" << endl;
                return;
            }
            
            // if current node is not the exit, proceed with checking the other nodes around it (we call those "moves")
            else if ((arr[currentNode->get_i()][currentNode->get_j()] == EMPTY) || (arr[currentNode->get_i()][currentNode->get_j()] == IN_DOOR)){

                // Mark the current node as visited
                closed->setVisited(currentNode->get_i(), currentNode->get_j());

                // add the four possible moves to the open list (if they are available)
                // it is important to check if the node is within bounds first, otherwise we may get a segfault error at the moment we check the maze[i][j] value!
                // also, we check if the node is a wall or not, as well we also check if the node has already been visited
                // and for every available move we will calculate the Euclidean Distance and add it to the open list

                // west
                if (isValid(currentNode->get_i()-1, currentNode->get_j()) && (!(closed->isVisited(currentNode->get_i()-1, currentNode->get_j())))){
                    if (arr[currentNode->get_i()-1][currentNode->get_j()] != WALL){
                        open->insert(new Node(currentNode->get_i()-1, currentNode->get_j(), EuclideanDistance(currentNode->get_i()-1, currentNode->get_j()), currentNode));
                    }
                }

                // east
                if (isValid(currentNode->get_i()+1, currentNode->get_j()) && (!(closed->isVisited(currentNode->get_i()+1, currentNode->get_j())))){
                    if (arr[currentNode->get_i()+1][currentNode->get_j()] != WALL){
                        open->insert(new Node(currentNode->get_i()+1, currentNode->get_j(), EuclideanDistance(currentNode->get_i()+1, currentNode->get_j()), currentNode));
                    }
                }

                // north
                if (isValid(currentNode->get_i(), currentNode->get_j()+1) && (!(closed->isVisited(currentNode->get_i(), currentNode->get_j()+1)))){
                    if (arr[currentNode->get_i()][currentNode->get_j()+1] != WALL){
                        open->insert(new Node(currentNode->get_i(), currentNode->get_j()+1, EuclideanDistance(currentNode->get_i(), currentNode->get_j()+1), currentNode));
                    }
                }
                // south
                if (isValid(currentNode->get_i(), currentNode->get_j()-1) && (!(closed->isVisited(currentNode->get_i(), currentNode->get_j()-1)))){
                    if (arr[currentNode->get_i()][currentNode->get_j()-1] != WALL){
                        open->insert(new Node(currentNode->get_i(), currentNode->get_j()-1, EuclideanDistance(currentNode->get_i(), currentNode->get_j()-1), currentNode));
                    }
                }
            }
        }
    }
    cout << "There is no solution to this maze" << endl;
}