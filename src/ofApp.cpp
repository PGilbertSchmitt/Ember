#include "ofApp.h"

using namespace std;

//--------------------------------------------------------------
void ofApp::setup(){
    Seat first; //Creating the first seat
    Seat second; //Creating the second seat
    Seat third; //Creating the third seat

    /*This is a test to show that each seat has its own filename for its respective xml file*/
    cout << "The file for seat " << first.getSeatNum() << " is called " << first.getDataName() << endl;
    cout << "The file for seat " << second.getSeatNum() << " is called " << second.getDataName() << endl;
    cout << "The file for seat " << third.getSeatNum() << " is called " << third.getDataName() << endl;
    /* The seat numbering starts at 0, while the data numbering starts at 1. This is okay, because we'll */
    /* only be looking at either within the class itself                                                 */
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
    if (key == 's')
    {
        cout << "Goodbye" << endl;
        std::exit(1);
    }
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
