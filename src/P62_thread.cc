#include <iostream>
#include <thread>

static bool is_finished = false;
using namespace std::literals::chrono_literals;

void DoWork1()
{
    std::cout << "the thread id is: " << std::this_thread::get_id() << std::endl;

    while (!is_finished)
    {
        std::cout << "Working1...\n";
        std::this_thread::sleep_for(1s);
    }
}

void DoWork2()
{
    std::cout << "the thread id is: " << std::this_thread::get_id() << std::endl;
    while (!is_finished)
    {
        std::cout << "Working2...\n";
        std::this_thread::sleep_for(1s);
    }
}

int main(int argc, char **argv)
{
    std::thread worker1(DoWork1);
    std::thread worker2(DoWork2);

    std::cin.get();
    is_finished = true;

    worker1.join();
    worker2.join();

    std::cin.get();

    return 0;
}