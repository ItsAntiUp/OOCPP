#include "Record.h"
#include "Utility.h"

#include <iostream>
#include <string>
#include <iomanip>

using namespace Util::Defaults;
using namespace Util::Exceptions;

namespace Rec{
    class Record::Inner{
        private:
            unsigned id;
            static unsigned idCounter;
            std::string artist;
            std::string song;
            unsigned year;
            double rating;
            bool isFavorite;

            bool isNameCorrect(const std::string&);
            bool isYearCorrect(unsigned);
            bool isRatingCorrect(double);

            friend class Record;
    };

    unsigned Record::Inner::idCounter = 0;

    bool Record::Inner::isNameCorrect(const std::string &i_name){
        if(i_name.length() >= 2)
            return true;
        else
            throw CustomException(INVALID_NAME_EXCEPTION + i_name);
    }

    bool Record::Inner::isYearCorrect(unsigned i_year){
        if(i_year >= DEFAULT_YEAR && i_year <= Util::getCurrentYear())
            return true;
        else
            throw CustomException(INVALID_YEAR_EXCEPTION + std::to_string(i_year));
    }

    bool Record::Inner::isRatingCorrect(double i_rating){
        if(i_rating >= 0 && i_rating <= 10)
            return true;
        else{
            std::ostringstream ss;
            ss << INVALID_RATING_EXCEPTION << std::fixed << std::setprecision(1) << i_rating;
            throw CustomException(ss.str());
        }
    }

    Record::Record(){
        rec_ptr = NULL;
        /*rec_ptr = new Inner();
        init(++Inner::idCounter, DEFAULT_NAME, DEFAULT_NAME, DEFAULT_YEAR, DEFAULT_RATING, DEFAULT_ISFAVORITE);*/
    }

    Record::Record(const std::string &i_artist, const std::string &i_song, unsigned i_year, double i_rating, bool i_isFavorite){
        rec_ptr = new Inner();
        init(++Inner::idCounter, i_artist, i_song, i_year, i_rating, i_isFavorite);
    }

    Record::Record(const Record &i_record){
        Inner *temp = new Inner();

        temp->id = i_record.getId();
        temp->artist = i_record.getArtist();
        temp->song = i_record.getSong();
        temp->year = i_record.getYear();
        temp->rating = i_record.getRating();
        temp->isFavorite = i_record.getIsFavorite();

        this->rec_ptr = temp;
    }

    Record& Record::operator =(const Record &i_record){
        if(rec_ptr == NULL || i_record.rec_ptr == NULL)
            throw CustomException(OBJECT_NOT_INITIALIZED_EXCEPTION);

        if(this->rec_ptr == i_record.rec_ptr)
            return *this;

        Inner *temp = new Inner();

        temp->id = i_record.getId();
        temp->artist = i_record.getArtist();
        temp->song = i_record.getSong();
        temp->year = i_record.getYear();
        temp->rating = i_record.getRating();
        temp->isFavorite = i_record.getIsFavorite();

        delete this->rec_ptr;
        this->rec_ptr = temp;

        return *this;
    }

    void Record::init(unsigned i_id, const std::string &i_artist, const std::string &i_song, unsigned i_year, double i_rating, bool i_isFavorite){
        setId(i_id);
        setArtist(i_artist);
        setSong(i_song);
        setYear(i_year);
        setRating(i_rating);
        setIsFavorite(i_isFavorite);
    }

    Record::~Record(){
        --Inner::idCounter;
        delete rec_ptr;
    }

    void Record::setId(unsigned i_id){
        if(rec_ptr == NULL)
            rec_ptr = new Inner();

        rec_ptr->id = i_id;
    }

    void Record::setArtist(const std::string &i_artist){
        if(rec_ptr == NULL)
            rec_ptr = new Inner();

        rec_ptr->artist = rec_ptr->isNameCorrect(i_artist) ? i_artist : DEFAULT_NAME;
    }

    void Record::setSong(const std::string &i_song){
        if(rec_ptr == NULL)
            rec_ptr = new Inner();

        rec_ptr->song = rec_ptr->isNameCorrect(i_song) ? i_song : DEFAULT_NAME;
    }

    void Record::setYear(unsigned i_year){
        if(rec_ptr == NULL)
            rec_ptr = new Inner();

        rec_ptr->year = rec_ptr->isYearCorrect(i_year) ? i_year : DEFAULT_YEAR;
    }

    void Record::setRating(double i_rating){
        if(rec_ptr == NULL)
            rec_ptr = new Inner();

        rec_ptr->rating = rec_ptr->isRatingCorrect(i_rating) ? i_rating : DEFAULT_RATING;
    }

    void Record::setIsFavorite(bool i_isFavorite){
        if(rec_ptr == NULL)
            rec_ptr = new Inner();

        rec_ptr->isFavorite = i_isFavorite;
    }

    int Record::getId() const{
        if(rec_ptr == NULL)
            throw CustomException(OBJECT_NOT_INITIALIZED_EXCEPTION);

        return rec_ptr->id;
    }

    std::string Record::getArtist() const{
        if(rec_ptr == NULL)
            throw CustomException(OBJECT_NOT_INITIALIZED_EXCEPTION);

        return rec_ptr->artist;
    }

    std::string Record::getSong() const{
        if(rec_ptr == NULL)
            throw CustomException(OBJECT_NOT_INITIALIZED_EXCEPTION);

        return rec_ptr->song;
    }

    unsigned Record::getYear() const{
        if(rec_ptr == NULL)
            throw CustomException(OBJECT_NOT_INITIALIZED_EXCEPTION);

        return rec_ptr->year;
    }

    double Record::getRating() const{
        if(rec_ptr == NULL)
            throw CustomException(OBJECT_NOT_INITIALIZED_EXCEPTION);

        return rec_ptr->rating;
    }

    bool Record::getIsFavorite() const{
        if(rec_ptr == NULL)
            throw CustomException(OBJECT_NOT_INITIALIZED_EXCEPTION);

        return rec_ptr->isFavorite;
    }

    bool Record::operator ==(const Record &i_record){
        if(rec_ptr == NULL)
            throw CustomException(OBJECT_NOT_INITIALIZED_EXCEPTION);

        return (this->getRating() == i_record.getRating());
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
        if(rec_ptr == NULL)
            throw CustomException(OBJECT_NOT_INITIALIZED_EXCEPTION);

        return (this->getRating() >= i_record.getRating());
    }

    bool Record::operator <=(const Record &i_record){
        if(rec_ptr == NULL)
            throw CustomException(OBJECT_NOT_INITIALIZED_EXCEPTION);

        return (this->getRating() <= i_record.getRating());
    }

    Record& Record::operator ++(){
        if(rec_ptr == NULL)
            throw CustomException(OBJECT_NOT_INITIALIZED_EXCEPTION);

        float temp_rating = this->getRating();
        this->setRating(++temp_rating);
        return *this;
    }

    Record Record::operator ++(int){
        if(rec_ptr == NULL)
            throw CustomException(OBJECT_NOT_INITIALIZED_EXCEPTION);

        Record temp = *this;
        float temp_rating = this->getRating();
        this->setRating(++temp_rating);
        return temp;
    }

    Record& Record::operator --(){
        if(rec_ptr == NULL)
            throw CustomException(OBJECT_NOT_INITIALIZED_EXCEPTION);

        float temp_rating = this->getRating();
        this->setRating(--temp_rating);
        return *this;
    }

    Record Record::operator --(int){
        if(rec_ptr == NULL)
            throw CustomException(OBJECT_NOT_INITIALIZED_EXCEPTION);

        Record temp = *this;
        float temp_rating = this->getRating();
        this->setRating(--temp_rating);
        return temp;
    }

    std::istream& operator >>(std::istream &i, Record &i_record){
        unsigned temp_id;
        std::string temp_artist;
        std::string temp_song;
        unsigned temp_year;
        double temp_rating;
        bool temp_isFavorite;

        i >> temp_id >> temp_artist >> temp_song >> temp_year >> temp_rating >> temp_isFavorite;
        i_record.init(temp_id, temp_artist, temp_song, temp_year, temp_rating, temp_isFavorite);

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
}
