//
// Created by mustafarslan on 3/19/18.
//

#include <iostream>
#include <log4cpp/Category.hh>
#include "JournalAppender.h"

int main(){
    std::cout << "Hello World!" << std::endl;
    log4cpp::Category &logger = log4cpp::Category::getRoot();
    log4cpp::Appender *journalAppender = new edgelog::JournalAppender(std::string("Journal"));

    logger.addAppender(journalAppender);
    logger.info("TESTDSADSADsa");
    return 0;
}