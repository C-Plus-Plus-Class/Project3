#include <iostream>
#include <thread>

#include "./print_ts.h"
#include "./tester.h"

using namespace std;
int main() {
    string s1 = "some";
    string s2 = "data";

    PRINT2(s1,s2);
    PRINT3(s1,s1,s1);

    startThreads("print this",4,P3,200,90);
    setCancelThreads(true);
    joinThreads();
}
