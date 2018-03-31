//
// Created by mustafarslan on 3/19/18.
//

#include "JournalAppender.h"

namespace clog {

    JournalAppender::JournalAppender(std::string name): LayoutAppender(name) {

    }

    JournalAppender::~JournalAppender() {

    }

    void JournalAppender::close() {

    }

    bool JournalAppender::requiresLayout() const{

    }

    bool JournalAppender::reopen() {

    }

    void JournalAppender::Append(const log4cpp::LoggingEvent &event) {
        _append(event);
    }

    void JournalAppender::_append(const log4cpp::LoggingEvent &event){
        std::string message;
        message.append("MESSAGE=").append(event.message);

        sd_journal_send(message.c_str(),NULL);
    }

}
