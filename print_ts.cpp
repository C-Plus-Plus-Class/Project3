//
// Created by allan on 3/28/20.
//

#include <iostream>
#include <mutex>
#include "print_ts.h"

std::mutex mtx;
bool canceled = false;
void PRINT1(std::string &txt) {
    if(!canceled){
        std::lock_guard<std::mutex> guard(mtx);
        std:: cout <<txt<<"\n";
    }
}

void PRINT2(std::string &txt, std::string &txt1) {
    if(!canceled) {
        std::lock_guard<std::mutex> guard(mtx);
        std::cout << txt << txt1 << "\n";
    }
}

void PRINT3(std::string &txt, std::string &txt1, std::string &txt2) {
    if(!canceled) {
        std::lock_guard<std::mutex> guard(mtx);
        std::cout << txt << txt1 << txt2 << "\n";
    }
}

void PRINT4(std::string &txt, std::string &txt1, std::string &txt2, std::string &txt3) {
    if(!canceled) {
        std::lock_guard<std::mutex> guard(mtx);
        std::cout << txt << txt1 << txt2 << txt3 << "\n";
    }
}

void PRINT5(std::string &txt, std::string &txt1, std::string &txt2, std::string &txt3, std::string &txt4) {
    if(!canceled) {
        std::lock_guard<std::mutex> guard(mtx);
        std::cout << txt << txt1 << txt2 << txt3 << txt4 << "\n";
    }
}

