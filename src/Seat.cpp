#include "Seat.h"

int Seat::seatNumSeed = 0;

Seat::Seat()
{
    seatNum = seatNumSeed++;
    ss << "data" << (seatNum + 1) << ".xml";
    dataFileName = ss.str();
}

string Seat::getDataName()
{
    return dataFileName;
}

int Seat::getSeatNum()
{
    return seatNum;
}

int Seat::getSeatCount()
{
    return seatNumSeed + 1;
}
