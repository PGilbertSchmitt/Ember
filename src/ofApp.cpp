#include "ofApp.h"
#define NUM_OF_SEATS 5

using namespace std;

//--------------------------------------------------------------
void ofApp::setup(){

    if (ard.connect(port, 57600))
    {
        if (ard.isArduinoReady())
        {
            cout << "Successful connection established." << endl;
        }
    }

    ofAddListener(ard.EInitialized, this, &ofApp::setupArduino);
	bSetupArduino	= false;

    cout << "Hit \"s\" to terminate" << endl;
}

//--------------------------------------------------------------
void ofApp::update(){
    ard.update();
    if (ard.isInitialized())
    {
        cout << buttonState << endl;
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if (key == 's')
    {
        allSeats[1].saveNoteList();
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
    bSetupArduino = true;

    cout << ard.getFirmwareName();
    cout << "firmata v" << ard.getMajorFirmwareVersion() << "." << ard.getMinorFirmwareVersion();

    for (int i = 0; i < 10; i++)
    {
        ard.sendDigitalPinMode((i+2),ARD_INPUT);
    }

    ofAddListener(ard.EDigitalPinChanged, this, &ofApp::digitalPinChanged);
    ofAddListener(ard.EAnalogPinChanged, this, &ofApp::analogPinChanged);
}

//--------------------------------------------------------------

void ofApp::digitalPinChanged(const int & pinNum)
{
    buttonState = "digital pin: " + ofToString(pinNum) + " = " + ofToString(ard.getDigital(pinNum));
}

//--------------------------------------------------------------

void ofApp::analogPinChanged(const int & pinNum)
{
    potValue = "analog pin: " + ofToString(pinNum) + " = " + ofToString(ard.getAnalog(pinNum));
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
