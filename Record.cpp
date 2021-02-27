#include "Record.h"

unsigned rec::Record::idCounter = 0;

rec::Record::Record() : id(++idCounter){
    setArtist(DEFAULT_NAME);
    setSong(DEFAULT_NAME);
    setYear(DEFAULT_YEAR);
    setRating(DEFAULT_RATING);
    setIsFavorite(DEFAULT_ISFAVORITE);
}

rec::Record::Record(const std::string &i_artist, const std::string &i_song, unsigned i_year, double i_rating, bool i_isFavorite) : id(++idCounter){
    setArtist(i_artist);
    setSong(i_song);
    setYear(i_year);
    setRating(i_rating);
    setIsFavorite(i_isFavorite);
}

rec::Record::~Record(){
    --idCounter;
}

//Setters

void rec::Record::setArtist(const std::string &i_artist){
    artist = isNameCorrect(i_artist) ? i_artist : DEFAULT_NAME;
}

void rec::Record::setSong(const std::string &i_song){
    song = isNameCorrect(i_song) ? i_song : DEFAULT_NAME;
}

void rec::Record::setYear(unsigned i_year){
    year = isYearCorrect(i_year) ? i_year : DEFAULT_YEAR;
}

void rec::Record::setRating(double i_rating){
    rating = isRatingCorrect(i_rating) ? i_rating : DEFAULT_RATING;
}

void rec::Record::setIsFavorite(bool i_isFavorite){
    isFavorite = i_isFavorite;
}


//Getters

std::string rec::Record::getSong() const{
    return song;
}

std::string rec::Record::getArtist() const{
    return artist;
}

unsigned rec::Record::getYear() const{
    return year;
}

double rec::Record::getRating() const{
    return rating;
}

bool rec::Record::getIsFavorite() const{
    return isFavorite;
}

//Other methods

std::string rec::Record::toString() const{
    std::stringstream ss;

    std::string idStr = "ID: " + std::to_string(id);
    std::string suffix = getIsFavorite() ? "Yes" : "No";
    std::string favStr = "Is favorite: " + suffix;
    std::string yearStr = "(" + std::to_string(getYear()) + ")";
    ss << "Rating: " << std::fixed << std::setprecision(1) << getRating();
    std::string ratingStr = ss.str();

    return idStr + " " + getArtist() + " - " + getSong() + " " + yearStr + " " + ratingStr + " " + favStr;
}

bool rec::Record::isNameCorrect(const std::string &str){
    if(str.length() < 2)
        throw std::invalid_argument(std::string("Invalid name: ") + str);

    return true;
}

bool rec::Record::isYearCorrect(unsigned year){
    if(year < DEFAULT_YEAR || year > getCurrentYear())
        throw std::invalid_argument(std::string("Invalid year: ") + std::to_string(year));

    return true;
}

bool rec::Record::isRatingCorrect(double rating){
    if(rating < 0 || rating > 10){
        std::stringstream ss;
        ss << "Invalid rating: " << std::fixed << std::setprecision(1) << rating;
        throw std::invalid_argument(ss.str());
    }

    return true;
}

unsigned rec::Record::getCurrentYear(){
    auto now = std::chrono::system_clock::now();
    std::time_t now_c = std::chrono::system_clock::to_time_t(now);
    struct tm * tnow = std::gmtime(&now_c);
    return tnow->tm_year + DEFAULT_YEAR;
}
