#include <iostream>
#include <vector>

class Base{
    public:
    Base(){
        std::cout << "Base Ctor" << std::endl;
    }
    ~Base(){
        std::cout << "Base Dtor" << std::endl;
    }
};

class Drive : public Base{
    public:
    Drive(){
        std::cout << "Drive Ctor" << std::endl;
    }
    ~Drive(){
        std::cout << "Drive Dtor" << std::endl;
    }
};

int main(){
    Base* Base_obj = new Base();
    delete Base_obj;
    std::cout << "------------" << std::endl;
    Drive* Drive_obj = new Drive();
    delete Drive_obj;
    std::cout << "------------" << std::endl;
    Base* Polymophy_obj = new Drive();
    delete Polymophy_obj;
    // std::vector<int> array;
    // array.reserve(100);
    // for (int i = 0; i < 100; i++){
    //     array.emplace_back(i);
    //     std::cout << i << std::endl;
    // }

    std::cin.get();
}   
