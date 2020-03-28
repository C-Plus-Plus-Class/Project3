//
// Created by allan on 3/28/20.
//
#include <vector>
#include <thread>
#include <time.h>
#include <chrono>
#include "tester.h"
#include "./print_ts.h"


using namespace std;

vector<thread> threads;
bool canceled = false;
void cancelableFunction(std::string s, WHICH_PRINT wp, int numTimesToPrint, int millisecond_delay){
    switch(wp){//could do this with switch and set a function variable to a specific function and have only 1 for loop, but this was easier and we already have 5 redundant print functions so eh
        case P1:
            for(int i = 0; i<numTimesToPrint && !canceled; i++){
                PRINT1(s);
                this_thread::sleep_for(chrono::milliseconds(millisecond_delay));
            }
            break;
        case P2:
            for(int i = 0; i<numTimesToPrint && !canceled; i++){
                PRINT2(s,s);
                this_thread::sleep_for(chrono::milliseconds(millisecond_delay));
            }
            break;
        case P3:
            for(int i = 0; i<numTimesToPrint && !canceled; i++){
                PRINT3(s,s,s);
                this_thread::sleep_for(chrono::milliseconds(millisecond_delay))
            }
            break;
        case P4:
            for(int i = 0; i<numTimesToPrint && !canceled; i++){
                PRINT4(s,s,s,s);
                this_thread::sleep_for(chrono::milliseconds(millisecond_delay));
            }
            break;
        case P5:
            for(int i = 0; i<numTimesToPrint && !canceled; i++){
                PRINT5(s,s,s,s,s);
                this_thread::sleep_for(chrono::milliseconds(millisecond_delay));
            }
            break;
    }
}
void startThreads(std::string s, int numThreads, WHICH_PRINT wp, int numTimesToPrint, int millisecond_delay) {
    for(int i =0;i<numThreads;i++){
        threads.push_back(thread(cancelableFunction,s,wp,numTimesToPrint,millisecond_delay));
    }
}

void setCancelThreads(bool bCancel) {
    canceled = bCancel
}

void joinThreads() {
    for(thread &t: threads){
        t.join();
    }
}

