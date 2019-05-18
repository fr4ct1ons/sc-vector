#include"sc_vector.h"
#include<iostream>

int main(int argc, char const *argv[])
{
    sc::Vector<int> myVec(20);
    
    myVec[19] = 76;
    myVec[3] = 51;
    std::cout << "Value: " << myVec[3] << std::endl;

    sc::Vector<int> copyVec(myVec);
    std::cout << "copyVec[3] Value: " << copyVec[3] << std::endl;

    std::cout << "Are the vectors equal? " << (int) (copyVec == myVec) << std::endl;
    std::cout << "Are the vectors unequal? " << (int) (copyVec != myVec) << std::endl;
    copyVec[3] = 9;
    std::cout << "Are the vectors equal? " << (int) (copyVec == myVec) << std::endl;
    std::cout << "Are the vectors unequal? " << (int) (copyVec != myVec) << std::endl;

    sc::Vector<int> assignmentVec = copyVec = myVec;
    std::cout << "Value at assignmentVec[3]: " << assignmentVec[3] << std::endl;
    std::cout << "Value at copyVec[3]: " << copyVec[3] << std::endl;
    std::cout << "Value at myVec[3]: " << myVec[3] << std::endl;

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

    myVec[19] = 56;
    myVec.pop_back();
    std::cout << "Size: " << myVec.size() << std::endl;
    std::cout << "Value at the back: " << myVec.back() << std::endl;
    std::cout << "Capacity: " << myVec.capacity() << std::endl;

    myVec[19] = 86;
    myVec[0] = 40;
    std::cout << "Value at the back: " << myVec.back() << std::endl;
    std::cout << "Value at the front: " << myVec.front() << std::endl;

    myVec.push_back(88);
    myVec.push_front(66);
    std::cout << "Value at the back: " << myVec.back() << std::endl;
    std::cout << "Value at the front: " << myVec.front() << std::endl;
    std::cout << "Size: " << myVec.size() << std::endl;
    std::cout << "Capacity: " << myVec.capacity() << std::endl;

    myVec[3] = 222222;
    std::cout << "***** BEFORE RESERVE *****" << std::endl;
    myVec.reserve(25);
    std::cout << "Value at the back: " << myVec.back() << std::endl;
    std::cout << "Value at the front: " << myVec.front() << std::endl;
    std::cout << "Size: " << myVec.size() << std::endl;
    std::cout << "Capacity: " << myVec.capacity() << std::endl;
    std::cout << "Value at myVec[3]: " << myVec[3] << std::endl;

    std::cout << "***** BEFORE SHRINK TO FIT *****" << std::endl;
    myVec.shrink_to_fit();
    std::cout << "Value at the back: " << myVec.back() << std::endl;
    std::cout << "Value at the front: " << myVec.front() << std::endl;
    std::cout << "Size: " << myVec.size() << std::endl;
    std::cout << "Capacity: " << myVec.capacity() << std::endl;
    std::cout << "Value at myVec[3]: " << myVec[3] << std::endl;

    myVec.clear();
    myVec.push_front(1964);
    std::cout << "Size: " << myVec.size() << std::endl;
    std::cout << "Value at the front: " << myVec.front() << std::endl;

    myVec.push_back(2019);
    std::cout << "Size: " << myVec.size() << std::endl;
    std::cout << "Value at the back: " << myVec.back() << std::endl;

    myVec.assign(10, 44);
    std::cout << "Size: " << myVec.size() << std::endl;
    std::cout << "Value at the back: " << myVec.back() << std::endl;
    std::cout << "Value at the front: " << myVec.front() << std::endl;

    myVec.assign(30, 88);
    std::cout << "Size: " << myVec.size() << std::endl;
    std::cout << "Capacity: " << myVec.capacity() << std::endl;
    std::cout << "Value at the back: " << myVec.back() << std::endl;
    std::cout << "Value at the front: " << myVec.front() << std::endl;

    return 0;
}
