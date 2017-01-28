

all: min

min: HW6_1.o vertex.o NLWLSnode.o fileio.o
	g++ HW6_1.o vertex.o NLWLSnode.o fileio.o -o min

vertex.o: vertex.h vertex.cpp
	g++ -c -g vertex.cpp

HW6_1.o: HW6_1.cpp
	g++ -c -g HW6_1.cpp

NLWLSnode.o: NLWLSnode.h NLWLSnode.cpp
	g++ -c -g NLWLSnode.cpp

fileio.o: fileio.h fileio.cpp
	g++ -c -g fileio.cpp

clean:
	rm *o min
