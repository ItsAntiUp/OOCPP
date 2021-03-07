#include "Record.h"
#include "Utility.h"

#include <iostream>
#include <string>
#include <iomanip>

namespace Rec{
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

    bool Record::operator ==(const Record &i_record){
        if(this->getRating() != i_record.getRating())
            return false;

        return true;
    }

    bool Record::operator !=(const Record &i_record){
        return !(*this == i_record);
    }

    bool Record::operator  >(const Record &i_record){
        return !(*this <= i_record);
    }

    bool Record::operator  <(const Record &i_record){
        return !(*this >= i_record);
    }

    bool Record::operator >=(const Record &i_record){
        if(this->getRating() < i_record.getRating())
            return false;

        return true;
    }

    bool Record::operator <=(const Record &i_record){
        if(this->getRating() > i_record.getRating())
            return false;

        return true;
    }

    Record Record::operator ++(){
        float temp_rating = this->getRating();
        this->setRating(++temp_rating);
        return *this;
    }

    Record Record::operator ++(int){
        Record temp = *this;
        float temp_rating = this->getRating();
        this->setRating(++temp_rating);
        return temp;
    }

    Record Record::operator --(){
        float temp_rating = this->getRating();
        this->setRating(--temp_rating);
        return *this;
    }

    Record Record::operator --(int){
        Record temp = *this;
        float temp_rating = this->getRating();
        this->setRating(--temp_rating);
        return temp;
    }

    std::istream& operator >>(std::istream &i, Record &i_record){
        std::string temp_artist;
        std::string temp_song;
        unsigned temp_year;
        double temp_rating;
        bool temp_isFavorite;

        i >> temp_artist >> temp_song >> temp_year >> temp_rating >> temp_isFavorite;
        i_record.init(temp_artist, temp_song, temp_year, temp_rating, temp_isFavorite);

        return i;
    }

    std::ostream& operator <<(std::ostream &o, const Record &i_record){
        o << i_record.toString();
        return o;
    }

    std::string Record::toString() const{
        std::ostringstream ss;
        ss << std::setw(4) << std::left << getId() << "\t";
        ss << std::setw(20) << std::left << getArtist() << "\t";
        ss << std::setw(20) << std::left << getSong() << "\t";
        ss << std::setw(4) << std::left << getYear() << "\t";
        ss << std::setw(4) << std::left << getRating() << "\t";
        ss << getIsFavorite();

        return ss.str();
    }

    void Record::init(const std::string &i_artist, const std::string &i_song, unsigned i_year, double i_rating, bool i_isFavorite){
        setArtist(i_artist);
        setSong(i_song);
        setYear(i_year);
        setRating(i_rating);
        setIsFavorite(i_isFavorite);
    }

    bool Record::isNameCorrect(const std::string &i_name){
        if(i_name.length() >= 2)
            return true;
        else
            throw std::invalid_argument(INVALID_NAME_EXCEPTION + i_name);
    }

    bool Record::isYearCorrect(unsigned i_year){
        if(i_year >= DEFAULT_YEAR && i_year <= Util::getCurrentYear())
            return true;
        else
            throw std::invalid_argument(INVALID_YEAR_EXCEPTION + std::to_string(i_year));
    }

    bool Record::isRatingCorrect(double i_rating){
        if(i_rating >= 0 && i_rating <= 10)
            return true;
        else{
            std::stringstream ss;
            ss << INVALID_RATING_EXCEPTION << std::fixed << std::setprecision(1) << i_rating;
            throw std::invalid_argument(ss.str());
        }
    }
}
