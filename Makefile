scvector: main.o
	g++ -std=c++11 -I include/ -Wall -ggdb3 main.o

main.o: driver/main.cpp
	g++ -std=c++11 -I include/ -Wall -ggdb3 -c driver/main.cpp