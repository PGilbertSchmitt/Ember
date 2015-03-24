#include "ofApp.h"
#define NUM_OF_SEATS 3
#define SENSITIVITY 800

using namespace std;

//--------------------------------------------------------------
void ofApp::setup(){
    const string port = "/dev/ttyACM0";  //Stores the port name for the Arduino

    if (ard.connect(port, 57600))
    {
        if (ard.isArduinoReady())
        {
            cout << "Successful connection established." << endl;
        }
    }
    ofAddListener(ard.EInitialized, this, &ofApp::setupArduino);
    bSetupArduino	= false;

    nSeatLoop = 0;      //The update function will perform actions with each seat via allSeats[nSeatLoop]

    ring.loadSound("zenbell.wav");
    ring.play();

    cout << "Hit \"s\" to terminate Ember" << endl;
}

//--------------------------------------------------------------
void ofApp::update(){
    ard.update();
    /*if (ard.isInitialized())
    {
        cout << buttonState;
    }*/

    seatsOccupied = 0;

    for (int i = 0; i < NUM_OF_SEATS; i++)
    {
        if (allSeats[i].getLastState())
        {
            seatsOccupied++;
        }
    }

    if (!seatsOccupied)
    {
        ring.stop();
    }

    if (allSeats[nSeatLoop].getLastState())
    {
        allSeats[nSeatLoop].playBack(seatsOccupied, ring);
    }

    if (nSeatLoop < (NUM_OF_SEATS-1))
    {
        nSeatLoop++;
    }
    else
    {
        nSeatLoop=0;
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if (key == 's')
    {
        for (int i = 0; i < NUM_OF_SEATS; i++)
        {
            allSeats[i].saveNoteList();
        }
        cout << "Saving ..." << endl;
        std::exit(1);
    }

    if (key == '1')
    {
        cout << "PinNum 2 is " << ard.getDigital(2) << endl;
    }

    if (key == '2')
    {
        cout << "PinNum 3 is " << ard.getDigital(3) << endl;
    }
}

//--------------------------------------------------------------

void ofApp::setupArduino(const int & version)
{
    ofRemoveListener(ard.EInitialized, this, &ofApp::setupArduino);

    cout << ard.getFirmwareName();
    cout << "firmata v" << ard.getMajorFirmwareVersion() << "." << ard.getMinorFirmwareVersion() << endl;

    /*for (int i = 0; i < NUM_OF_SEATS; i++)
    {
        ard.sendDigitalPinMode((i+2),ARD_INPUT);
    }*/

    ard.sendAnalogPinReporting(0,ARD_ANALOG);

    ofAddListener(ard.EDigitalPinChanged, this, &ofApp::digitalPinChanged);
    ofAddListener(ard.EAnalogPinChanged, this, &ofApp::analogPinChanged);

    bSetupArduino = true;
}

//--------------------------------------------------------------

void ofApp::digitalPinChanged(const int & pinNum)
{

}

//--------------------------------------------------------------

void ofApp::analogPinChanged(const int & pinNum)
{
    if (bSetupArduino)
    {
        //potValue = "analog pin: " + ofToString(pinNum) + " = " + ofToString(ard.getAnalog(pinNum));

        bool state;
        if (ard.getAnalog(pinNum) > SENSITIVITY && allSeats[pinNum].getLastState() == false)
        {
            allSeats[pinNum].setStartTime();
            state = true;
            allSeats[pinNum].setLastState(state);

            cout << "Seat " << pinNum << " was pressed" << endl;
        }
        else if (ard.getAnalog(pinNum) <= SENSITIVITY && allSeats[pinNum].getLastState() == true)
        {
            allSeats[pinNum].setDuration();
            int duration = allSeats[pinNum].getCurrentDur();
            int value = duration / 1000;
            if (value < 7)
            {
                allSeats[pinNum].addNote(value);
            } else
            {
                allSeats[pinNum].addNote(7);
            }
            allSeats[pinNum].setNote(false);
            state = false;
            allSeats[pinNum].setLastState(state);

            cout << "Seat " << pinNum << " was released" << endl;
        }
    }
}

//--------------------------------------------------------------
void ofApp::draw(){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){

}
