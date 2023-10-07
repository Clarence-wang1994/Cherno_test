#include <iostream>
#include <vector>
#include <functional>


void static ForEach(const std::vector<int>& vec_num, const std::function<void(int)> & func){
    for(auto num: vec_num){
        func(num);
    }
}

int main(int argc, char** argv){
    std::vector<int> num_array = {1, 2, 3, 4, 5};

    int a = 5;
    auto lambda = [=](int value){std::cout << "value: " << value << std::endl;};
    ForEach(num_array, lambda);
    std::cin.get();
}