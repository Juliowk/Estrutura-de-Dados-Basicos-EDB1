all: main.o recursion.o ordination.o ordination.o util.o
	g++ -Wall -o main main.o recursion.o ordination.o util.o

main.o: main.cpp headers/recursion.h headers/ordination.h
	g++ -Wall -c main.cpp 

recursion.o: cpp/recursion.cpp headers/recursion.h headers/util.h
	g++ -Wall -c cpp/recursion.cpp -I .

ordination.o: cpp/ordination.cpp headers/ordination.h headers/util.h
	g++ -Wall -c cpp/ordination.cpp -I .

util.o: cpp/util.cpp headers/util.h
	g++ -Wall -c cpp/util.cpp -I .

run: all
	./main

clean:
	rm -f *.o main