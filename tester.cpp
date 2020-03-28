//
// Created by allan on 3/28/20.
//
#include <vector>
#include <thread>
#include "tester.h"
#include "./print_ts.h"


using namespace std;

vector<thread> threads;

void startThreads(std::string s, int numThreads, WHICH_PRINT wp, int numTimesToPrint, int millisecond_delay) {
    auto sRef = ref(s);
    switch(wp){
        case P1:
            for(int i =0;i<numThreads;i++){
                threads.push_back(thread(PRINT1,sRef));
            }
            break;
        case P2:
            for(int i =0;i<numThreads;i++) {
                threads.push_back(thread(PRINT2,sRef,sRef));
            }
            break;
        case P3:
            for(int i =0;i<numThreads;i++) {
                threads.push_back(thread(PRINT3,sRef,sRef,sRef));
            }
            break;
        case P4:
            for(int i =0;i<numThreads;i++) {
                threads.push_back(thread(PRINT4,sRef,sRef,sRef,sRef));
            }
            break;
        case P5:
            for(int i =0;i<numThreads;i++) {
                threads.push_back(thread(PRINT5,sRef,sRef,sRef,sRef,sRef));
            }
            break;
    }
}

void setCancelThreads(bool bCancel) {
    for(thread &t: threads){
        t.
    }}

void joinThreads() {
    for(thread &t: threads){
        t.join();
    }
}

