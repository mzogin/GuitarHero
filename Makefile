CC= g++
CFLAGS= -g -Wall -Werror -pedantic -O3 -std=c++14
SFLAGS= -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio
Boost= -lboost_unit_test_framework

all:	KSGuitarSim test

KSGuitarSim:	KSGuitarSim.o StringSound.o CircularBuffer.o
	$(CC) KSGuitarSim.o StringSound.o CircularBuffer.o -o KSGuitarSim $(SFLAGS)

test: test2.o StringSound.o CircularBuffer.o
	$(CC) test2.o StringSound.o CircularBuffer.o -o test $(Boost)

KSGuitarSim.o:	KSGuitarSim.cpp StringSound.h
	$(CC) -c KSGuitarSim.cpp StringSound.h $(CFLAGS)

StringSound.o:	StringSound.cpp StringSound.h
	$(CC) -c StringSound.cpp StringSound.h $(CFLAGS)

CircularBuffer.o:	CircularBuffer.cpp CircularBuffer.h
	$(CC) -c CircularBuffer.cpp CircularBuffer.h $(CFLAGS)

test2.o:	test2.cpp
	$(CC) -c test2.cpp $(Boost)

clean:
	rm *.o
	rm *.gch
	rm KSGuitarSim
	rm test


