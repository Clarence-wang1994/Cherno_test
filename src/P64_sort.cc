#include <iostream>
#include <functional>
#include <algorithm>
#include <vector>

struct FuncSort
{
    bool operator() (int a, int b) const{
        return a > b;
    }
} ;


int main(int argc, char** argv){

    FuncSort sort_array;

    std::vector<int> array_num = {3,3,4,2,1,5};
    // std::sort(array_num.begin(), array_num.end(), [](int a, int b){
    //     return a > b;
    // });

    std::sort(array_num.begin(), array_num.end(), sort_array);

    for(auto value : array_num){
        std::cout << value << std::endl;
    }
    std::cin.get();
}