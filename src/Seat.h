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
        static unsigned long long nLastTime;   //Holds the last time a note was played
        std::stringstream ss;
        std::string dataFileName;

        void setNoteVector();
        int nPinNum;                     //Holds the pin number on the Arduino, which starts from 2
        bool bPressState;                //Holds whether or not the seat was being pressed beforehand
        bool bLastState;

        /** These variables will be used to retrieve the duration of a button press **/
        unsigned long long nDur;
        unsigned long long nStart;

        /** These variables will be used by the playback function **/
        int nNote;                      //Holds the current note that needs to be played next

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

        /** The following methods handle notes to and from the noteList vector **/
        void playBack(const int seatsOccupied, ofSoundPlayer & ring);
        void setPressState(bool & state);
        bool getPressState();
        void setLastState(bool state);
        bool getLastState();

        void setStartTime();
        void setDuration();
        int getCurrentDur();

        void addNote(int value);        //Adds a new note to the noteList array
        void setNote(bool state);        //If the seat is occupied, the note switches to the next one by decrementing
                                        //If note, the note is reset to the end of the noteList vector
};

#endif // SEAT_H
