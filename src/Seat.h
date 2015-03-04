#ifndef SEAT_H
#define SEAT_H

#include "ofMain.h"
#include "ofxXmlSettings.h"
#include <iostream>

class Seat
{
    private:

        int nSeatNum;
        static int nSeatNumSeed;
        std::stringstream ss;
        std::string dataFileName;

        void setNoteVector();
        int nPinNum;                     //Holds the pin number on the Arduino, which starts from 2
        bool bPressState;                //Holds whether or not the seat was being pressed beforehand
        int note;

        /** These variables will be used to retrieve the duration of a button press **/
        unsigned long long nDur;
        unsigned long long nStart;

    public:

        Seat();
        string getDataFileName();       //Returns the name of the XML file where note history should be stored
        int getSeatNum();               //Returns the number of the seat (or seat ID) unique to each seat
        int getPinNum();                //Returns the pin number that this seat accesses from the Arduino
        static int getSeatCount();      //Returns the number of seats currently initiated

        /**The following members are used for loading and storing note data from the XML files*/
        ofxXmlSettings savedNotes;      //XML file to parse for note values
        vector<int> noteList;           //List of notes that will be used by the program
        int numNotesInit;               //Number of notes available in this seat's history when the XML file is first loaded

        int getNoteListSize();
        void saveNoteList();

        /** The following methods handle messages from the Arduino running the StandardFirmata sketch **/

        /** The following methods handle playback of notes from the noteList vector **/
        void playBack();
        void setPressState(bool & state);
        bool getPressState();

        void setStartTime();
        void setDuration();
};

#endif // SEAT_H
