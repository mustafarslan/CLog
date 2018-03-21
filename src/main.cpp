//
// Created by mustafarslan on 3/19/18.
//

#include <iostream>
#include <log4cpp/Category.hh>
#include <log4cpp/Appender.hh>
#include "JournalAppender.h"

int main(){
    std::cout << "Hello World!" << std::endl;
    log4cpp::Category &logger = log4cpp::Category::getRoot();
    log4cpp::Appender *journalAppender = new edgelog::JournalAppender("JournalAppender");

    logger.addAppender(static_cast<log4cpp::Appender*>(journalAppender));
    logger.info("First Log Message");
    return 0;
}
