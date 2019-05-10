#include"sc_vector.h"
#include<iostream>

int main(int argc, char const *argv[])
{
    sc::Vector<int, 20> myVec;

    myVec[3] = 50;
    std::cout << "Value: " << myVec[3] << std::endl;
    std::cout << "INVALID value: " << myVec.at(99) << std::endl;
    std::cout << "Size: " << myVec.GetSize() << std::endl;

    return 0;
}
