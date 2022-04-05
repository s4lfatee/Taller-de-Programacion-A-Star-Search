all: test_maze test_container test_matrix test_node main

main: Maze.o Container.o Matrix.o Maze.h Node.o main.cpp
	g++ Maze.o Container.o Node.o Matrix.o main.cpp -o main -lm

test_maze: Maze.o test_Maze_1.cpp Maze.h Node.o Container.o Matrix.o
	g++ Maze.o Node.o Container.o Matrix.o test_Maze_1.cpp -g -o test_maze

test_container: Container.o Node.o test_Container_1.cpp
	g++ Container.o Node.o test_Container_1.cpp -o test_container

test_matrix: Matrix.o test_Matrix_1.cpp Matrix.h
	g++ Matrix.o test_Matrix_1.cpp -o test_Matrix

test_node: Node.o test_Node_1.cpp
	g++ Node.o test_Node_1.cpp -o test_node

Matrix.o: Matrix.cpp Matrix.h
	g++ -c Matrix.cpp

Maze.o: Maze.cpp Maze.h
	g++ -c Maze.cpp

Node.o: Node.cpp Node.h
	g++ -c Node.cpp

Container.o: Container.cpp Container.h
	g++ -c Container.cpp