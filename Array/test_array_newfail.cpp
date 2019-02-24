// Implement a version of `new` that fails on command
// Based on https://stackoverflow.com/questions/1923664/simulating-low-memory-using-c
#include <memory>
#include <iostream>
#include "array.h"
// Global flag that sets whether or not `new` will fail
bool memoryAllocFail = false; // Succeed by default

// Custom implementation of new
void* operator new(std::size_t size)
{
    std::cout << "New allocation of size " << size << std::endl;
    if (memoryAllocFail)
    {
       throw std::bad_alloc();
    }

    return ::malloc(size);
}

void operator delete(void* block)
{
    std::cout << "Freed allocation" << std::endl;
    ::free(block);
}


int main(int argc, char* argv[])
{
    
    Array<int> arr(3, 0);
    Array<int> atoo(5, 2);
    Array<int> rthree(1,3);
    
    memoryAllocFail = true; 
    int tmp[4] = {99,98,97,96};
    int *ptr = tmp;

    cout<<"now size of arr is: "<<arr.size()<<endl;
    cout<<"now size of rthree is: "<<rthree.size()<<endl;


    try {
      std::cout << "The fourth number is: " << arr[3] << std::endl;
    }
    catch (const std::exception& e){
      std::cout << "There was an error: " << e.what() << std::endl;
    }

    try {
        arr.append(80);
    }
    catch (const std::exception& ba){
        std::cout << "There was an error: " << ba.what() << std::endl;
    }
    cout<<"now size of arr is: "<<arr.size()<<endl;


    try {
        arr.append(atoo);
    }
    catch (const std::exception& ba){
        std::cout << "There was an error: " << ba.what() << std::endl;
    }
    cout<<"now size of arr is: "<<arr.size()<<endl;

    try {
        Array<int> arr(2,ptr);
    }
    catch (const std::exception& ba){
        std::cout << "There was an error: " << ba.what() << std::endl;
    }
    cout<<"now size of arr is: "<<arr.size()<<endl;

    try {
        rthree = arr + atoo;
    }
    catch (const std::exception& ba){
        std::cout << "There was an error: " << ba.what() << std::endl;
    }
    cout<<"now size of rthree is: "<<rthree.size()<<endl;




    //int* b = new int[10];
    //delete b;
    

    return(0);

}

