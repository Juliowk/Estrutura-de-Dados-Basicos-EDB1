all: main.o recursion.o
	g++ -Wall -o main main.o recursion.o

main.o: main.cpp recursion.h
	g++ -Wall -c main.cpp 

recursion.o: recursion.cpp recursion.h
	g++ -Wall -c recursion.cpp

run: all
	./main

clean:
	rm -f *.o main