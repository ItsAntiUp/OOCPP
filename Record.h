#ifndef RECORD_H
#define RECORD_H

#include <iostream>
#include <string>
#include <cctype>
#include <chrono>
#include <iomanip>

#define DEFAULT_YEAR 1900
#define DEFAULT_NAME "Not Found"
#define DEFAULT_RATING 0.0
#define DEFAULT_ISFAVORITE false

namespace rec{
    class Record
    {
        private:
            const unsigned id;
            static unsigned idCounter;

            std::string artist;
            std::string song;
            unsigned year;
            double rating;
            bool isFavorite;

        public:
            Record();
            Record(const std::string&, const std::string&, unsigned, double, bool);
            virtual ~Record();

            //Setters
            void setArtist(const std::string&);
            void setSong(const std::string&);
            void setYear(unsigned);
            void setRating(double);
            void setIsFavorite(bool);

            //Getters
            std::string getSong() const;
            std::string getArtist() const;
            unsigned getYear() const;
            double getRating() const;
            bool getIsFavorite() const;

            //Other methods
            std::string toString() const;

        private:
            bool isNameCorrect(const std::string&);
            bool isYearCorrect(unsigned);
            bool isRatingCorrect(double);
            unsigned getCurrentYear();
    };
}

#endif // RECORD_H
