

all: tsp

tsp: genetic.o city.o cityTraversals.o population.o cityio.o
	g++ -std=c++11 genetic.o city.o cityTraversals.o population.o cityio.o -o tsp

genetic.o: genetic.h city.h cityTraversals.h population.h genetic.cpp
	g++ -c -g -std=c++11 genetic.cpp

city.o: city.h city.cpp
	g++ -c -g -std=c++11 city.cpp

cityTraversals.o: cityTraversals.h cityTraversals.cpp city.h
	g++ -c -g -std=c++11 cityTraversals.cpp

population.o: population.h population.cpp cityTraversals.h city.h
	g++ -c -g -std=c++11 population.cpp

cityio.o: cityio.h cityio.cpp city.h
	g++ -c -g -std=c++11 cityio.cpp

clean:
	rm *o tsp
