scvector: sc_vector.o main.o
	g++ -std=c++11 -I include/ -Wall sc_vector.o main.o

main.o: driver/main.cpp
	g++ -std=c++11 -I include/ -Wall -c driver/main.cpp

sc_vector.o: source/sc_vector.cpp
	g++ -std=c++11 -I include/ -Wall -c source/sc_vector.cpp