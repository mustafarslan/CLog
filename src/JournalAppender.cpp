//
// Created by mustafarslan on 3/19/18.
//

#include "JournalAppender.h"

namespace edgelog {

    JournalAppender::JournalAppender(const std::string& name) {}

    void JournalAppender::close() {

    }

    bool JournalAppender::requiresLayout() const{

    }

    void JournalAppender::setLayout(log4cpp::Layout *layout){

    }

    void JournalAppender::_append(const log4cpp::LoggingEvent &event){
        std::cout << "TEST" << std::endl;
    }

}