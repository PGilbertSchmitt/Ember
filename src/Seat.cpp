#include "Seat.h"

int Seat::nSeatNumSeed = 0;
unsigned long long Seat::nLastTime = 0;

Seat::Seat()
{
    nSeatNum = ++nSeatNumSeed;
    nPinNum = nSeatNum+1;
    ss << "data" << (nSeatNum) << ".xml";
    dataFileName = ss.str();
    numNotesInit = 0;
    setNoteVector();

    setStartTime();
    setDuration();
    setNote(false);
    setLastState(false);
}

void Seat::setNoteVector()
{
    savedNotes.load(dataFileName);

    int numHistoryTags = savedNotes.getNumTags("history:note");

	if (numHistoryTags > 0)
	{
        savedNotes.pushTag("history");

        int numNoteTags = savedNotes.getNumTags("note");
        if (numNoteTags > 0)
        {
            for (int i = 0; i < numNoteTags; i++)
            {
                int noteVal = savedNotes.getValue("note:value",0,i);
                noteList.push_back(noteVal);
                numNotesInit++;
            }
        }
	}

	savedNotes.popTag();
}

//----------------------SETTERS----------------------------------

void Seat::setPressState(bool & state)
{
    bPressState = state;
}

void Seat::setLastState(bool state)
{
    bLastState = state;
}
void Seat::setStartTime()
{
    nStart = ofGetSystemTime();
}

void Seat::setDuration()
{
    nDur = ofGetSystemTime() - nStart;
}

void Seat::addNote(int value)
{
    noteList.push_back(value);
}

void Seat::setNote(bool state)
{
    if (state)
    {
        if (nNote > 0)
        {
            nNote--;
        }
        else
        {
            nNote = 0;
        }
    }
    else
    {
        nNote = noteList.size() - 1;
    }
}

//----------------------GETTERS----------------------------------

string Seat::getDataFileName()
{
    return dataFileName;
}

int Seat::getSeatNum()
{
    return nSeatNum;
}

int Seat::getSeatCount()
{
    return nSeatNumSeed + 1;
}

int Seat::getNoteListSize()
{
    return noteList.size();
}

int Seat::getPinNum()
{
    return nPinNum;
}

bool Seat::getPressState()
{
    return bPressState;
}

bool Seat::getLastState()
{
    return bLastState;
}

int Seat::getCurrentDur()
{
    return nDur;
}

//----------------------OTHERS-----------------------------------

void Seat::playBack(const int seatsOccupied, ofSoundPlayer & ring)
{
    /* Setting the time between note plays by checking the number of seats currently occupied.
     * The more people, the faster the notes.
     */
    int noteLength;
    if (seatsOccupied == 0)
    {
        noteLength = 1000;
    }
    else
    {
        noteLength = 1000 / seatsOccupied;
    }

    if ((noteLength + nLastTime) < ofGetSystemTime())
    {
        setNote(true);

        switch(noteList[nNote])
        {
        case 0 :
            ring.setSpeed( 0.75f );
            break;
        case 1 :
            ring.setSpeed( 0.92f );
            break;
        case 2 :
            ring.setSpeed( 1.0f );
            break;
        case 3 :
            ring.setSpeed( 1.12f);
            break;
        case 4 :
            ring.setSpeed( 1.25f );
            break;
        case 5 :
            ring.setSpeed( 1.36f );
            break;
        case 6 :
            ring.setSpeed( 1.50 );
            break;
        case 7 :
            ring.setSpeed( 1.62 );
            break;
        default:
            ring.setSpeed( 0.75f );
            break;
        }
        nLastTime = ofGetSystemTime();
        ring.play();
        std::cout << "Playing seat " << getSeatNum() << endl;
    }
}

void Seat::saveNoteList()
{
    savedNotes.pushTag("history");

    for (int i = numNotesInit; i < getNoteListSize(); i++)
    {
        savedNotes.setValue("note:value",noteList[i],i);
    }

    savedNotes.popTag();
    savedNotes.save(dataFileName);
}
