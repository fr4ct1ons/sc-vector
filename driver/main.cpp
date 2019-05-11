#include"sc_vector.h"
#include<iostream>

int main(int argc, char const *argv[])
{
    sc::Vector<int, 20> myVec;

    try
    {
        sc::Vector<int, 0> newVec;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    

    myVec[3] = 51;
    std::cout << "Value: " << myVec[3] << std::endl;
    try
    {
        std::cout << "INVALID value: " << myVec.at(99) << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    myVec.push_front(666);
    std::cout << "Size: " << myVec.size() << std::endl;
    std::cout << "Front-pushed value: " << myVec[20] << std::endl;
    std::cout << "Value at myVec[3]: " << myVec[3] << std::endl;

    return 0;
}
