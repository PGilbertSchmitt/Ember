#include "ofApp.h"
#define NUM_OF_SEATS 5

using namespace std;

//--------------------------------------------------------------
void ofApp::setup(){

    /*Initializing the five seat objects into an array called allSeats*/
    Seat allSeats[NUM_OF_SEATS];

    /*This is a test to show that each seat has its own filename for its respective xml file*/

    for (int i = 0; i < NUM_OF_SEATS; i++)
    {
        cout << "Seat " << i << " has " << allSeats[i].getNoteListSize() << " saved notes." << endl;
    }
    /* The seat numbering starts at 0, while the data numbering starts at 1. This is okay, because we'll */
    /* only be looking at either within the class itself*/

    cout << "Hit \"s\" to terminate" << endl;
}

//--------------------------------------------------------------
void ofApp::update(){
}

//--------------------------------------------------------------
void ofApp::draw(){

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if (key == 's')
    {
        cout << "Goodbye" << endl;
        std::exit(1);
    }
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
