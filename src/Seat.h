#ifndef SEAT_H
#define SEAT_H

#include "ofMain.h"
#include "DateTime.h"

class Seat
{
    private:

        int seatNum;
        static int seatNumSeed;
        std::stringstream ss;
        std::string dataFileName;

    public:

        Seat();
        string getDataName();
        int getSeatNum();
        static int getSeatCount();
};

#endif // SEAT_H
