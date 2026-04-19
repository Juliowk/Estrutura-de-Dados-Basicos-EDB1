all: main.o recursion.o ordination.o ordination.o util.o
	g++ -Wall -o main main.o recursion.o ordination.o util.o

main.o: main.cpp recursion.h ordination.h
	g++ -Wall -c main.cpp 

recursion.o: recursion.cpp recursion.h util.h
	g++ -Wall -c recursion.cpp

ordination.o: ordination.cpp ordination.h util.h
	g++ -Wall -c ordination.cpp

util.o: util.cpp util.h
	g++ -Wall -c util.cpp

run: all
	./main

clean:
	rm -f *.o main