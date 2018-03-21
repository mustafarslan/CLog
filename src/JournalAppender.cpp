//
// Created by mustafarslan on 3/19/18.
//

#include "JournalAppender.h"

namespace edgelog {

    JournalAppender::JournalAppender(const std::string& name): LayoutAppender(name) {

    }

    void JournalAppender::close() {

    }

    bool JournalAppender::requiresLayout() const{

    }

    void JournalAppender::Append(const log4cpp::LoggingEvent &event) {
        _append(event);
    }

    void JournalAppender::_append(const log4cpp::LoggingEvent &event){
        std::string message;
        message.append(event.message);

        sd_journal_send(message.c_str(),NULL);
    }

}