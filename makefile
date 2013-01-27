CPP=g++ -O3

all: Main.exe

Main.exe: RedBlackTree.o RedBlackLeaf.o Forest.o Driver.o
	$(CPP) RedBlackTree.o RedBlackLeaf.o Forest.o Driver.o -o Main.exe

RedBlackTree.o: RedBlackTree.cpp
	$(CPP) -c RedBlackTree.cpp 

RedBlackLeaf.o: RedBlackLeaf.cpp
	$(CPP) -c RedBlackLeaf.cpp

Forest.o: Forest.cpp
	$(CPP) -c Forest.cpp

Driver.o: Driver.cpp
	$(CPP) -c Driver.cpp

clean:
	rm -f *.o *~ *.exe *.out
