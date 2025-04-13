#include <iostream>
#include <chrono>
#include <thread>
void someFunction()
{
    std::this_thread::sleep_for(std::chrono::seconds(1));
}

int main()
{
    auto start = std::chrono::high_resolution_clock::now();

    someFunction();

    auto end = std::chrono::high_resolution_clock::now();

    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    std::cout << "Function took " << duration.count() << " milliseconds to execute." << std::endl;

    return 0;
}