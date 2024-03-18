main: vector.o funkcijos.o
	g++ -o main vector.o funkcijos.o

vector.o: vector.cpp funkcijos.h
	g++ -c vector.cpp -o vector.o

funkcijos.o: funkcijos.cpp funkcijos.h
	g++ -c funkcijos.cpp -o funkcijos.o

clean:
	del *.o main
