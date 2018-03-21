//
// Created by mustafarslan on 3/19/18.
//

#ifndef EDGELOG_JOURNALAPPENDER_H
#define EDGELOG_JOURNALAPPENDER_H

#include <systemd/sd-journal.h>
#include <log4cpp/Layout.hh>
#include <log4cpp/LayoutAppender.hh>
#include <log4cpp/LoggingEvent.hh>

namespace edgelog {

    class JournalAppender: public log4cpp::LayoutAppender {
        public:
            JournalAppender();
            JournalAppender(const std::string& name);
            ~JournalAppender();
            void reopen();
            void close();
            bool requiresLayout() const;
            void Append(const log4cpp::LoggingEvent & event);

        protected:
            void _append(const log4cpp::LoggingEvent& event);

    };

}

#endif //EDGELOG_JOURNALAPPENDER_H
