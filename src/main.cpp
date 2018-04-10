//
// Created by mustafarslan on 3/19/18.
//

#include <iostream>
#include "LogAPI.h"

void test();

int main(){
    std::cout << "Hello World!" << std::endl;

    clog::LogAPI & logger = clog::LogAPI::getInstance();

    logger.init();

    logger.info("Hello from LogAPI");

    test();

    return 0;
}


void test(){
    clog::LogAPI & logger = clog::LogAPI::getInstance();
    logger.info("Hello From other function");
}