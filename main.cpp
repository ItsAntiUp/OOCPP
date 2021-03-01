#include "Record.h"

#include <iostream>

using namespace Rec;

int main(){
    try{
        Record r1;
        std::cout << r1.toString() << "\n";

        r1.setArtist("Artist");
        r1.setSong("Song");
        r1.setYear(2021);
        r1.setRating(6.4);
        r1.setIsFavorite(false);

        std::cout << r1.toString() << "\n";

        Record r2("First", "Second", 2015, 8.5, false);
        std::cout << r2.toString() << "\n";

        Record *r3 = new Record[3];
        r3[0].setArtist("Dynamic Artist");
        r3[0].setSong("Dynamic Song");
        r3[0].setYear(-100); //Throws exception

        r3[2].setYear(2021);
        r3[2].setRating(10);
        r3[2].setIsFavorite(true);

        std::cout << r3[0].toString() << "\n";
        std::cout << r3[1].toString() << "\n";
        std::cout << r3[2].toString() << "\n";

        delete []r3;
    }
    catch(std::exception &e){
        std::cerr << e.what() << "\n";
    }
    catch(...){
        std::cerr << "Unexpected error occurred." << "\n";
    }

    return 0;
}
