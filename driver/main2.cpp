#include"sc_vector.h"
#include<iostream>

int main(int argc, char const *argv[])
{
    sc::Vector<int> myVec = {1, 2, 3, 4, 5};
    std::cout << myVec[4] << std::endl;
    //delete &myVec;
    return 0;
}
