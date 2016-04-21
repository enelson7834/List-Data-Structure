all:	List.o main.o
	g++ List.o main.o -o ListTest
List.o:	listnode.cpp listnode.h
	g++ -c listnode.cpp -o List.o
main.o:	main.cpp
	g++ -c main.cpp -o main.o