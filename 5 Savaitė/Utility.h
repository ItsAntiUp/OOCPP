#ifndef UTILITY_H
#define UTILITY_H

#include <chrono>
#include <string>
#include <sstream>
#include <exception>
#include <stdexcept>

#define CustomException(arg) \
    CustomExceptionClass(arg, __FILE__, __LINE__)

namespace Util{
    namespace Defaults{
        const unsigned DEFAULT_YEAR = 1900;
        const std::string DEFAULT_NAME = "Not Found";
        const float DEFAULT_RATING = 0.0;
        const bool DEFAULT_ISFAVORITE  = false;
    }

    namespace Exceptions{
        class CustomExceptionClass : public std::exception{
            private:
                std::string msg;

            public:
                CustomExceptionClass(const std::string &arg, const char *file, int line);
                const char* what() const throw();
        };

        const std::string OBJECT_NOT_INITIALIZED_EXCEPTION = "Object is not initialized!";
        const std::string INVALID_NAME_EXCEPTION = "Invalid name: ";
        const std::string INVALID_YEAR_EXCEPTION = "Invalid year: ";
        const std::string INVALID_RATING_EXCEPTION = "Invalid rating: ";
        const std::string UNEXPECTED_EXCEPTION = "Unexpected error occurred.";
    }

    unsigned getCurrentYear();
}

#endif // UTILITY_H
