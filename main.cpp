#include <iostream>
#include <thread>

#include "./tester.h"

using namespace std;
int main() {
    int numThreads = std::thread::hardware_concurrency();

    startThreads("aaaaaaaaaaaaaaaaa- ", numThreads, P2, 1000, 100);
    startThreads("zzzzzzzzzzzzzzzzz- ", numThreads, P3, 1000, 100);

    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    setCancelThreads(true);

    joinThreads();
}

