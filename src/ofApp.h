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


        /* Initializing the five seat objects into an array called allSeats.
         * The seats will need to be accessed one at a time in numerical order,
         * so they will be iterated through using for loops. Accessing the seats'
         * members is done through allSeats[i].member
         */
        Seat allSeats[NUM_OF_SEATS];

        ofArduino ard;      //Allows for serial communication with the Arduino
        string buttonState;
        string potValue;
        bool bSetupArduino; //Used to only perform certain actions once the Arduino has been setup
        int nSeatLoop;      //Used to iterate between the seats during the update function

    private:
        void setupArduino(const int & version);
        void digitalPinChanged(const int & pinNum);
        void analogPinChanged(const int & pinNum);
};
