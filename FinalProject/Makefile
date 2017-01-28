
all: flu

flu: planet.o population.o individual.o Simulation.o disease.o pandemic.o
	g++ -std=c++11 planet.o population.o individual.o Simulation.o disease.o pandemic.o -o flu

pandemic.o: pandemic.h pandemic.cpp population.h disease.h
	g++ -c -g -std=c++11 pandemic.cpp

disease.o: disease.h disease.cpp
	g++ -c -g -std=c++11 disease.cpp

Simulation.o: Simulation.cpp planet.h
	g++ -c -g -std=c++11 Simulation.cpp

planet.o: planet.h planet.cpp population.h
	g++ -c -g -std=c++11 planet.cpp

population.o: population.h population.cpp individual.h
	g++ -c -g -std=c++11 population.cpp

individual.o: individual.h individual.cpp
	g++ -c -g -std=c++11 individual.cpp

clean:
	rm *o flu
