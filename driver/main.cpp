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
    
    myVec[19] = 76;
    myVec[3] = 51;
    std::cout << "Value: " << myVec[3] << std::endl;

    sc::Vector<int, 20> copyVec(myVec);
    std::cout << "copyVec[3] Value: " << copyVec[3] << std::endl;

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
    std::cout << "Front-pushed value: " << myVec[0] << std::endl;
    std::cout << "Value at myVec[4] (previously myVec[3]): " << myVec[4] << std::endl;

    myVec.push_back(777);
    std::cout << "Size: " << myVec.size() << std::endl;
    std::cout << "Back-pushed value: " << myVec[21] << std::endl;

    myVec[1] = 95;
    std::cout << "Value at myVec[1]: " << myVec[1] << std::endl;
    myVec.pop_front();
    std::cout << "Size: " << myVec.size() << std::endl;
    std::cout << "Value at the front: " << myVec[0] << std::endl;

    myVec.pop_back();
    std::cout << "Size: " << myVec.size() << std::endl;

    myVec[19] = 86;
    myVec[0] = 40;
    std::cout << "Value at the back: " << myVec.back() << std::endl;
    std::cout << "Value at the front: " << myVec.front() << std::endl;

    return 0;
}
