//
// Created by allan on 3/28/20.
//
#include <iostream>
#include <vector>
#include <thread>
#include <chrono>
#include "tester.h"
#include "./print_ts.h"


using namespace std;
vector<thread> threads;
/**if true threads running cancelableFunction will cease to run,
 * if false threads will continue to run until their work is complete*/
bool canceled = false;
void cancelableFunction(std::string s, WHICH_PRINT wp, int numTimesToPrint, int millisecond_delay){
    for(int i = 0; i<numTimesToPrint; i++){
        if(canceled){
            string cancelString;
            cancelString.assign(USER_CHOSE_TO_CANCEL);//cant put const into non const function
            PRINT1(cancelString);
            return;
        }
        switch(wp){
            case P1: PRINT1(s); break;
            case P2: PRINT2(s,s); break;
            case P3: PRINT3(s,s,s); break;
            case P4: PRINT4(s,s,s,s); break;
            case P5: PRINT5(s,s,s,s,s); break;
        }
        this_thread::sleep_for(chrono::milliseconds(millisecond_delay));
    }

}
void startThreads(std::string s, int numThreads, WHICH_PRINT wp, int numTimesToPrint, int millisecond_delay) {
    for(int i =0;i<numThreads;i++){
        threads.push_back(thread(cancelableFunction, s, wp, numTimesToPrint, millisecond_delay));
    }
}

void setCancelThreads(bool bCancel) {
    canceled = bCancel;
}

void joinThreads() {
    for(thread &t: threads){
        t.join();
    }
}

