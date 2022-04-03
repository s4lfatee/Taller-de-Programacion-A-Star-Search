#include <iostream>

using namespace std;

class Container{
public:
	Container(int size);
	~Container();
	void print();
	bool isVisited(int i, int j);
	void setVisited(int i, int j);
private:
	int size;
	int **arr;
};
