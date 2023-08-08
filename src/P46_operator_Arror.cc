#include <iostream>
// #include <opencv2/opencv.hpp>

extern "C" {
    Mat cv::imread(const char *filename, int flags);
}

struct Vector3
{
   float x, y, z;
};

int main(int argc, char** argv){
    cv::Mat img = imread("C:\\Users\\clare\\Desktop\\2023-06-03_191203.bmp", 1);
    int offset = reinterpret_cast<int>(&((Vector3*)nullptr)->x);
    std::cout << offset << std::endl;
    // cv::imshow("img", img);
    // cv::waitKey(0);
    std::cin.get();
}