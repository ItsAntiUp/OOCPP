#ifndef UTILITY_H
#define UTILITY_H

#include <chrono>

#define DEFAULT_YEAR                1900
#define DEFAULT_NAME                "Not Found"
#define DEFAULT_RATING              0.0
#define DEFAULT_ISFAVORITE          false

#define INVALID_NAME_EXCEPTION      "Invalid name: "
#define INVALID_YEAR_EXCEPTION      "Invalid year: "
#define INVALID_RATING_EXCEPTION    "Invalid rating: "
#define UNEXPEXTED_EXCEPTION        "Unexpected error occurred."

namespace Util{
    unsigned getCurrentYear();
}

#endif // UTILITY_H
