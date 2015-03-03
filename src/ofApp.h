#pragma once

#include "ofMain.h"
#include "ofEvents.h"
#include "Seat.h"
#include <iostream>

#define NUM_OF_SEATS 5

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);


        /* Initializing the five seat objects into an array called allSeats */
        Seat allSeats[NUM_OF_SEATS];

        ofArduino ard;
        string buttonState;
        string potValue;
        bool bSetupArduino;

    private:
        const string port = "/dev/ttyACM0";
        void setupArduino(const int & version);
        void digitalPinChanged(const int & pinNum);
        void analogPinChanged(const int & pinNum);
};
