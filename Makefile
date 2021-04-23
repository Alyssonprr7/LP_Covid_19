# Makefile

main: main.o state.o country.o utils.o
	g++ -Wall -o  main main.o state.o country.o utils.o

main.o: main.cpp state.h country.h
	g++ -Wall -c -o  main.o main.cpp

country.o: country.cpp country.h state.h utils.h 
	g++ -Wall -c -o  country.o country.cpp


state.o: state.cpp state.h utils.h
	g++ -Wall -c -o  state.o state.cpp

utils.o: utils.cpp utils.h
	g++ -Wall -c -o  utils.o utils.cpp

clean:
	rm -f main *.o