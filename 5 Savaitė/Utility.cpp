#include "Utility.h"

namespace Util{
    unsigned getCurrentYear(){
        auto now = std::chrono::system_clock::now();
        std::time_t time = std::chrono::system_clock::to_time_t(now);
        struct tm *tnow = std::gmtime(&time);
        return tnow->tm_year + Defaults::DEFAULT_YEAR;
    }

    namespace Exceptions{
        CustomExceptionClass::CustomExceptionClass(const std::string &arg, const char *file, int line){
            std::ostringstream ss;
            ss << file << "  In line: " << line << " - " << arg;
            msg = ss.str();
        }

        const char *CustomExceptionClass::what() const throw(){
            return msg.c_str();
        }
    };
}
