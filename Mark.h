#include <iostream>
using namespace std;

// Mark class that represents a matrix of zeros and ones
// It also represents the maze but in another way
// Is used to set or check visited spots of the maze

class Mark{
public:
	Mark(int size);
	~Mark();
	void print(); // Print method for testing purposes
	bool isVisited(int i, int j); // Sets a cell of the maze to visited
	void setVisited(int i, int j); // Checks if a cell of the maze is visited
private:
	int size;
	int **arr; // The matrix of zeros and ones
};
