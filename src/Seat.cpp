#include "Seat.h"

int Seat::nSeatNumSeed = 0;

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

int Seat::getCurrentDur()
{
    return nDur;
}

//----------------------OTHERS-----------------------------------

void Seat::playBack()
{
    std::cout << getPinNum() << endl;
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
