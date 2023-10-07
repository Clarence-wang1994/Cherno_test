#include <iostream>

struct Array
{
    /* data */
    int x = 1, y = 2;
    void* GetPosition(){
        return this;
    }
};


int main(int argc, char** argv){

    int* ptr;
    char* ptr_char;
    double* ptr_double;

    std::cout << "Size of pointer " << sizeof(ptr) << std::endl;
    std::cout << "Size of ptr_char " << sizeof(ptr_char) << std::endl;
    std::cout << "Size of ptr_double " << sizeof(ptr_double) << std::endl;

    Array e;

    
    std::cout << "Size of GetPosition " << *((char*)e.GetPosition() + 4) << std::endl;

    std::cin.get();
}