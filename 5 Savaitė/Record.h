#ifndef RECORD_H
#define RECORD_H

#include <iostream>
#include <string>

namespace Rec{
    class Record{
        private:
            class Inner;
            Inner *rec_ptr;

        public:
            Record();
            Record(const std::string&, const std::string&, unsigned, double, bool);
            void init(unsigned, const std::string&, const std::string&, unsigned, double, bool);
            ~Record();

            void setId(unsigned);
            void setArtist(const std::string&);
            void setSong(const std::string&);
            void setYear(unsigned);
            void setRating(double);
            void setIsFavorite(bool);

            int getId() const;
            std::string getArtist() const;
            std::string getSong() const;
            unsigned getYear() const;
            double getRating() const;
            bool getIsFavorite() const;

            bool operator ==(const Record&);
            bool operator !=(const Record&);
            bool operator  >(const Record&);
            bool operator  <(const Record&);
            bool operator >=(const Record&);
            bool operator <=(const Record&);

            Record& operator ++();
            Record operator ++(int);
            Record& operator --();
            Record operator --(int);

            friend std::istream& operator >>(std::istream&, Record&);
            friend std::ostream& operator <<(std::ostream&, const Record&);

            std::string toString() const;

            /*friend class Record_inner;*/
    };
}

#endif // RECORD_H
