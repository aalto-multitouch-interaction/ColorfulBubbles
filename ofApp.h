#pragma once

#include "ofxiOS.h"
#include "flake.h"

#include "ofxiOSCoreMotion.h"

class ofApp : public ofxiOSApp {
	
    public:
        void setup();
        void update();
        void draw();
        void exit();
        void newball(float x, float y); // a new function I create

        void erase();
        void touchDown(ofTouchEventArgs & touch);
        void touchMoved(ofTouchEventArgs & touch);
        void touchUp(ofTouchEventArgs & touch);
        void touchDoubleTap(ofTouchEventArgs & touch);
        void touchCancelled(ofTouchEventArgs & touch);

        void lostFocus();
        void gotFocus();
        void gotMemoryWarning();
        void deviceOrientationChanged(int newOrientation);
    
    ofxiOSCoreMotion coreMotion;

    vector <Flake> myFlakes; //vector, like an arraylist
    
    ofVideoGrabber grabber; //set camera

};


