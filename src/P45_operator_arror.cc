#include <iostream>
#include <string>

class Entity{
};

class ScopedEntity{
    private:
        Entity* ptr_Entity;

    public:
        ScopedEntity(Entity* e):ptr_Entity(e){
            std::cout << "ctor" << std::endl;
        }
        ~ScopedEntity(){
            delete ptr_Entity;
            std::cout << "dtor" << std::endl;
        }
};

int main(){
    {
        ScopedEntity e = new Entity();
    }
    
    std::cin.get();
} 