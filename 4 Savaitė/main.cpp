#include "Record.h"
#include "Utility.h"

#include <iostream>

int main(){
    try{
        Rec::Record r1("Artist1", "Song1", 2021, 7.7, false);
        Rec::Record r2("Artist2", "Song2", 2018, 4.3, false);
        Rec::Record r3("Artist3", "Song3", 2017, 7.8, true);

        std::cout << (r1++ > r3) << "\n";
        std::cout << (r1 > r3) << "\n";
        std::cout << (--r1 > r3) << "\n";

        std::cout << r1 << "\n";
        std::cout << r2 << "\n";
        std::cout << r3 << "\n";
    }
    catch(std::exception &e){
        std::cerr << e.what() << "\n";
    }
    catch(...){
        std::cerr << Util::Exceptions::UNEXPECTED_EXCEPTION << "\n";
    }

    return 0;
}
