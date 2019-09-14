
project: list.o source.o
	gcc list.p source.o -o project

list.o: list.cpp list.h
	gcc -c list.cpp -o list.o

source.o: Source.cpp
	gcc -c Source.cpp -o source.o
clean:
	rm *.o *.a
