//
// Created by mustafarslan on 4/10/18.
//

#include "LogAPI.h"
#include <log4cpp/Category.hh>
#include <log4cpp/Appender.hh>
#include "JournalAppender.h"
#include <log4cpp/FileAppender.hh>
namespace clog {

    LogAPI & LogAPI::getInstance() {
        static LogAPI instance;
        return instance;
    }

    void LogAPI::init() {
        log4cpp::Appender * appender = nullptr;


        // Add FileAppender
        appender = new log4cpp::FileAppender("AppManager", "log.txt");
        logger.addAppender(appender);


        // Add JournalAppender
        appender = new clog::JournalAppender("JournalAppender");
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