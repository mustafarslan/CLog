//
// Created by mustafarslan on 4/10/18.
//

#ifndef CLOG_CONSTANT_H
#define CLOG_CONSTANT_H

namespace clog {

    enum class PriorityLevel {
        EMERG = 0,
        FATAL = 0,
        ALERT = 100,
        CRIT = 200,
        ERROR = 300,
        WARN = 400,
        NOTICE = 500,
        INFO = 600,
        DEBUG = 700,
        NOTSET = 800
    };

    enum class AppenderType {
        CONSOLE_APPENDER,
        FILE_APPENDER,
        JOURNAL_APPENDER,
        SYSLOG_APPENDER
    };

}

#endif //CLOG_CONSTANT_H
