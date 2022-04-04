#include <iostream>

using namespace std;

class Mark{
public:
	Mark(int size);
	~Mark();
	void print();
	bool isVisited(int i, int j);
	void setVisited(int i, int j);
private:
	int size;
	int **arr;
};
