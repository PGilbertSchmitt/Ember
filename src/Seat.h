#ifndef SEAT_H
#define SEAT_H

#include "ofMain.h"
#include "ofxXmlSettings.h"
#include <iostream>

class Seat
{
    private:

        int seatNum;
        static int seatNumSeed;
        std::stringstream ss;
        std::string dataFileName;

        void setNoteVector();

    public:

        Seat();
        string getDataFileName();
        int getSeatNum();
        static int getSeatCount();

        //The following methods and members are used for loading and storing note data from the xml files
        ofxXmlSettings savedNotes;      //XML file to parse for note values
        vector<int> noteList;           //List of notes that will be used by the program
        int numNotes;                   //Number of notes available in this seat's history

        int getNoteListSize();
};

#endif // SEAT_H
