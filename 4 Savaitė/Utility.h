#ifndef UTILITY_H
#define UTILITY_H

#include <chrono>
#include <string>

namespace Util{
    namespace Defaults{
        const unsigned DEFAULT_YEAR = 1900;
        const std::string DEFAULT_NAME = "Not Found";
        const float DEFAULT_RATING = 0.0;
        const bool DEFAULT_ISFAVORITE  = false;
    }

    namespace Exceptions{
        const std::string INVALID_NAME_EXCEPTION = "Invalid name: ";
        const std::string INVALID_YEAR_EXCEPTION = "Invalid year: ";
        const std::string INVALID_RATING_EXCEPTION = "Invalid rating: ";
        const std::string UNEXPECTED_EXCEPTION = "Unexpected error occurred.";
    }

    unsigned getCurrentYear();
}

#endif // UTILITY_H
