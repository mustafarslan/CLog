//
// Created by mustafarslan on 4/10/18.
//

#include "LogAPI.h"
#include <log4cpp/Category.hh>
#include <log4cpp/Appender.hh>
#include "JournalAppender.h"
#include <log4cpp/FileAppender.hh>
#include <log4cpp/OstreamAppender.hh>
#include <log4cpp/SyslogAppender.hh>
#include "Constant.h"

namespace clog {

    LogAPI & LogAPI::getInstance() {
        static LogAPI instance;
        return instance;
    }

    void LogAPI::init() {
        addAppender(AppenderType::JOURNAL_APPENDER);
        addAppender(AppenderType::FILE_APPENDER);
    }

    void LogAPI::addAppender(clog::AppenderType appenderType) {

        log4cpp::Appender * appender  = nullptr;

        if(AppenderType::CONSOLE_APPENDER == appenderType) {
            appender = new log4cpp::OstreamAppender("Clog", &std::cout);
        } else if(AppenderType::FILE_APPENDER == appenderType) {
            appender = new log4cpp::FileAppender("Clog", "log.txt");
        } else if(AppenderType::JOURNAL_APPENDER == appenderType) {
            appender = new clog::JournalAppender("JournalAppender");
        } else if(AppenderType::SYSLOG_APPENDER == appenderType) {
            appender = new log4cpp::SyslogAppender("Clog", "SyslogAppender");
        } else {
            appender = new clog::JournalAppender("JournalAppender");
        }

        logger.addAppender(appender);

    }

    void LogAPI::warn(const std::string &message, const std::string & functionName, int line) {
        logger.warn("Function: " + functionName + " Line: " + std::to_string(line) + " Message: " + message );
    }

    void LogAPI::info(const std::string &message, const std::string & functionName, int line) {
        logger.info("Function: " + functionName + " Line: " + std::to_string(line) + " Message: " + message );
    }

    void LogAPI::error(const std::string &message, const std::string & functionName, int line) {
        logger.error("Function: " + functionName + " Line: " + std::to_string(line) + " Message: " + message );
    }

    void LogAPI::debug(const std::string &message, const std::string & functionName, int line) {
        logger.debug("Function: " + functionName + " Line: " + std::to_string(line) + " Message: " + message );
    }

}