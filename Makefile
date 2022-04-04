all: test_maze test_container test_mark test_node main

main: Maze.o Container.o Mark.o Maze.h Node.o main.cpp
	g++ Maze.o Container.o Node.o Mark.o main.cpp -o main -lm

test_maze: Maze.o test_Maze_1.cpp Maze.h Node.o Container.o Mark.o
	g++ Maze.o Node.o Container.o Mark.o test_Maze_1.cpp -g -o test_maze

test_container: Container.o Node.o test_Container_1.cpp
	g++ Container.o Node.o test_Container_1.cpp -o test_container

test_mark: Mark.o test_Mark_1.cpp Mark.h
	g++ Mark.o test_Mark_1.cpp -o test_mark

test_node: Node.o test_Node_1.cpp
	g++ Node.o test_Node_1.cpp -o test_node

Mark.o: Mark.cpp Mark.h
	g++ -c Mark.cpp

Maze.o: Maze.cpp Maze.h
	g++ -c Maze.cpp

Node.o: Node.cpp Node.h
	g++ -c Node.cpp

Container.o: Container.cpp Container.h
	g++ -c Container.cpp