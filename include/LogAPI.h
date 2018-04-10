//
// Created by mustafarslan on 4/10/18.
//

#ifndef CLOG_LOGAPI_H
#define CLOG_LOGAPI_H

#include <log4cpp/Category.hh>
#include "Constant.h"

namespace clog {

    class LogAPI {
        public:
            static LogAPI & getInstance();
            void init();
            void warn(const std::string& message, const std::string & functionName = __builtin_FUNCTION(), int line = __builtin_LINE());
            void info(const std::string& message, const std::string & functionName = __builtin_FUNCTION(), int line = __builtin_LINE());
            void error(const std::string& message, const std::string & functionName = __builtin_FUNCTION(), int line = __builtin_LINE());
            void debug(const std::string& message, const std::string & functionName = __builtin_FUNCTION(), int line = __builtin_LINE());

        private:
            log4cpp::Category & logger = log4cpp::Category::getRoot();


    };

}

#endif //CLOG_LOGAPI_H
