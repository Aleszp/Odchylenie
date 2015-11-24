odchyl:	main.o
	g++ -o odchyl main.o -lm -pedantic -Wall
main.o:	main.cpp
	g++ -o main.o -c main.cpp  -pedantic -Wall