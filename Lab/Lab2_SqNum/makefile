all:main

SquareNumber.o:SquareNumber.cpp
	g++ -std=c++11 -c SquareNumber.cpp

main:SquareNumber.o
	g++ -o main SquareNumber.o

clean:
	rm -f *.o main
