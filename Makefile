scvector: sc_vector.o main.o
	g++ -std=c++11 -I include/ -Wall -ggdb3 sc_vector.o main.o

main.o: driver/main.cpp
	g++ -std=c++11 -I include/ -Wall -ggdb3 -c driver/main.cpp

sc_vector.o: source/sc_vector.cpp
	g++ -std=c++11 -I include/ -Wall -ggdb3 -c source/sc_vector.cpp