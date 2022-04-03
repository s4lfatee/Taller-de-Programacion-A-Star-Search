all: test_maze test_heap test_container test_node main

main: Maze.o Heap.o Container.o Maze.h Node.o main.cpp
	g++ Maze.o Heap.o Node.o Container.o main.cpp -o main -lm

test_maze: Maze.o test_Maze_1.cpp Maze.h Node.o Heap.o Container.o
	g++ Maze.o Node.o Heap.o Container.o test_Maze_1.cpp -g -o test_maze

test_heap: Heap.o Node.o test_Heap_1.cpp
	g++ Heap.o Node.o test_Heap_1.cpp -o test_heap

test_container: Container.o test_Container_1.cpp Container.h
	g++ Container.o test_Container_1.cpp -o test_container

test_node: Node.o test_Node_1.cpp
	g++ Node.o test_Node_1.cpp -o test_node

Container.o: Container.cpp Container.h
	g++ -c Container.cpp

Maze.o: Maze.cpp Maze.h
	g++ -c Maze.cpp

Node.o: Node.cpp Node.h
	g++ -c Node.cpp

Heap.o: Heap.cpp Heap.h
	g++ -c Heap.cpp