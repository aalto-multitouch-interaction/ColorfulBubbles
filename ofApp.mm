#include "ofApp.h"
void ofApp::setup(){
    ofBackground(0, 0, 0);
    ofSetCircleResolution(100); //make circle more smooth
    grabber.setup(1280, 720, OF_PIXELS_BGRA);//camera setup, only work with 1280*720 screen,otherwise would be too small
}
//--------------------------------------------------------------
void ofApp::update(){
    for(int i=0 ; i<myFlakes.size() ; i++){
        myFlakes[i].update(); //"myFlakes" is a vector, update vector
    }
    grabber.update();//camera update
}
//--------------------------------------------------------------
void ofApp::draw(){
    ofSetColor(180); //camera fliter
    grabber.draw(0, 0, grabber.getWidth(), grabber.getHeight()); //camera draw
    for(int i=0;i<myFlakes.size();i++){
        myFlakes[i].draw(); //draw vector
    }
}
//--------------------------------------------------------------
void ofApp::touchDown(ofTouchEventArgs & touch){
    newball(touch.x, touch.y); // touch the screen, create new balls
}
//--------------------------------------------------------------
void ofApp::touchMoved(ofTouchEventArgs & touch){
    newball(touch.x, touch.y); // touch the screen, create new balls
}
//--------------------------------------------------------------
void ofApp::touchUp(ofTouchEventArgs & touch){ //finger release
    for(int i=0;i<myFlakes.size();i++){
        myFlakes[i].fingerPressed=false;
    }
}
//--------------------------------------------------------------
void ofApp::newball(float x, float y){ //
    ofVec3f pos(x,y,0);
    Flake newFlake; // create new object
    newFlake.setup(pos);
    myFlakes.push_back(newFlake); //"push_back" adds a new element to the end of the vector.
}
//--------------------------------------------------------------
void ofApp::exit(){}
//--------------------------------------------------------------
void ofApp::touchDoubleTap(ofTouchEventArgs & touch){}
//--------------------------------------------------------------
void ofApp::touchCancelled(ofTouchEventArgs & touch){}
//--------------------------------------------------------------
void ofApp::lostFocus(){}
//--------------------------------------------------------------
void ofApp::gotFocus(){
}
//--------------------------------------------------------------
void ofApp::gotMemoryWarning(){
}
//--------------------------------------------------------------
void ofApp::deviceOrientationChanged(int newOrientation){
}
//-------------------------------------------------------------------------------
