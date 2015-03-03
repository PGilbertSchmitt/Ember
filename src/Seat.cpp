#include "Seat.h"

int Seat::seatNumSeed = 0;

Seat::Seat()
{
    seatNum = ++seatNumSeed;
    ss << "data" << (seatNum) << ".xml";
    dataFileName = ss.str();
    numNotesInit = 0;
    setNoteVector();
}

string Seat::getDataFileName()
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

int Seat::getNoteListSize()
{
    return noteList.size();
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
