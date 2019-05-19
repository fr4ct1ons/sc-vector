# sc-vector
College project, for replicating the std::vector, from C++'s Standard Template Library.  

Subject: Basic Data Structures I  
Teacher: Selan Rodrigues Santos  
Author: Gabriel Paes Landim de Lucena

## About
This project consists of a recreation of STL's vector data type.  It includes most methods included in the original vector data type.  

## How to install
Assuming you have g++ installed, you can simply run the makefile by typing `make` on the terminal, while on the root of the repository.  
This will generate an `a.out` file which you can use to see the library in action. Compare it with the source code to check the methods doing their work.  

## How to use this library
Just move the `sc_vector.h` file to your C++ project, no aditional assembly recquired.  

## Usage License
Do whatever you want with the code. Giving credit is not recquired, but I'll be happy if you do. Other than that, do as you will.  

## Errors
Currently, Valgrind points some memory leaks on the clone, assignment clone and assignment initializer list constructors, despite the presence of memory deallocation.  

## Contact
If you need to contact me, you can do so at https://twitter.com/fr4ct1ons or https://github.com/fr4ct1ons.