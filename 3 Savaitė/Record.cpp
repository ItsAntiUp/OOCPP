#include "Record.h"

#include <iostream>
#include <string>
#include <cctype>
#include <chrono>
#include <iomanip>

using namespace Rec;

unsigned Record::idCounter = 0;

Record::Record() : id(++idCounter){
    init(DEFAULT_NAME, DEFAULT_NAME, DEFAULT_YEAR, DEFAULT_RATING, DEFAULT_ISFAVORITE);
}

Record::Record(const std::string &i_artist, const std::string &i_song, unsigned i_year, double i_rating, bool i_isFavorite) : id(++idCounter){
    init(i_artist, i_song, i_year, i_rating, i_isFavorite);
}

Record::~Record(){
    --idCounter;
}

//Setters

void Record::setArtist(const std::string &i_artist){
    artist = isNameCorrect(i_artist) ? i_artist : DEFAULT_NAME;
}

void Record::setSong(const std::string &i_song){
    song = isNameCorrect(i_song) ? i_song : DEFAULT_NAME;
}

void Record::setYear(unsigned i_year){
    year = isYearCorrect(i_year) ? i_year : DEFAULT_YEAR;
}

void Record::setRating(double i_rating){
    rating = isRatingCorrect(i_rating) ? i_rating : DEFAULT_RATING;
}

void Record::setIsFavorite(bool i_isFavorite){
    isFavorite = i_isFavorite;
}


//Getters

int Record::getId() const{
    return id;
}

std::string Record::getArtist() const{
    return artist;
}

std::string Record::getSong() const{
    return song;
}

unsigned Record::getYear() const{
    return year;
}

double Record::getRating() const{
    return rating;
}

bool Record::getIsFavorite() const{
    return isFavorite;
}

//Other methods

void Record::init(const std::string &i_artist, const std::string &i_song, unsigned i_year, double i_rating, bool i_isFavorite){
    setArtist(i_artist);
    setSong(i_song);
    setYear(i_year);
    setRating(i_rating);
    setIsFavorite(i_isFavorite);
}

std::string Record::toString() const{
    std::ostringstream ss;
    ss << std::setw(4) << std::left << getId() << "\t" << std::setw(20) << std::left << getArtist() << "\t" << std::setw(20) << std::left << getSong() << "\t";
    ss << std::setw(4) << std::left << getYear() << "\t" << std::setw(4) << std::left << getRating() << "\t" << getIsFavorite();
    return ss.str();
}

bool Record::isNameCorrect(const std::string &str){
    if(str.length() >= 2)
        return true;
    else
        throw std::invalid_argument(std::string("Invalid name: ") + str);
}

bool Record::isYearCorrect(unsigned year){
    if(year >= DEFAULT_YEAR && year <= getCurrentYear())
        return true;
    else
        throw std::invalid_argument(std::string("Invalid year: ") + std::to_string(year));
}

bool Record::isRatingCorrect(double rating){
    if(rating >= 0 && rating <= 10)
        return true;
    else{
        std::stringstream ss;
        ss << "Invalid rating: " << std::fixed << std::setprecision(1) << rating;
        throw std::invalid_argument(ss.str());
    }
}

unsigned Record::getCurrentYear(){
    auto now = std::chrono::system_clock::now();
    std::time_t now_c = std::chrono::system_clock::to_time_t(now);
    struct tm *tnow = std::gmtime(&now_c);
    return tnow->tm_year + DEFAULT_YEAR;
}
