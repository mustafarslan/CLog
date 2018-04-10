//
// Created by mustafarslan on 3/19/18.
//

#include <iostream>
#include "LogAPI.h"
#include <memory>

void test();

// lazy coder move
std::shared_ptr<clog::LogAPI> logger = std::make_shared<clog::LogAPI>(clog::LogAPI::getInstance());

int main(){
    std::cout << "Hello World!" << std::endl;

    logger->init();

    logger->info("Hello from LogAPI");

    test();

    return 0;
}

void test(){
    logger->info("Hello From other function");
}