#include <chrono>
#include <iostream>

class Timer{
    private:
        std::chrono::_V2::system_clock::time_point start;
        std::chrono::_V2::system_clock::time_point end;
    public:
        Timer(){
            start = std::chrono::high_resolution_clock::now();
        }

        ~Timer(){
            end = std::chrono::high_resolution_clock::now();
            auto duration = end -  start;
            float ms = duration.count() * 1000.0f;
            std::cout << "the duration is: " << ms << " ms."<< std::endl;
        }

};

int Function(){
    Timer time;
}

int main (){
    Function();
    std::cin.get();
}