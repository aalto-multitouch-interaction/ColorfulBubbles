#pragma once
#include "ofxiOS.h"

#define NUM_COLORS 8 // array of colors

class Flake{
    
public:
    void setup(ofVec3f myPoint){
        flakePoint = myPoint; //vec3f
        flakeRandom.set(ofRandom(-3, 3),ofRandom(-3, 3),0); //set flakeRandom=========it influence the speed==========
        ballSize = ofRandom(7,150); //size of Balls
        fingerPressed=true;
        randomColor=ofRandom(NUM_COLORS);
        
        //====================My super beautiful colors========================//
        myColors[0].set(255,225,185);   //light yellow
        //myColors[1].set(0,137,162);   //middle blue
        //myColors[1].set(149,250,205); //lighter green
        //myColors[4].set(255,129,247); //pink
        // myColors[4].set(26,176,255); //light blue
        myColors[1].set(255,157,77);    //orange
        myColors[2].set(250,201,103);
        myColors[3].set(255,77,125);
        myColors[4].set(255,203,249);
        myColors[5].set(211,127,247);   //purple
        myColors[6].set(40,250,245);    //light green
        myColors[7].set(255,157,77); //orange again
        //====================My super beautiful colors========================//
    }
    void update(){
        flakePoint += flakeRandom; //=========it influence the speed, vec3f(speedx,speedy,position)==========
        if(fingerPressed==false){ // if finger release
            if(ballSize > ofRandom(5,30)) ballSize -= ofRandom(0.05, 1); // balls become smaller,
        }
    }
    void draw(){
        
        ofSetColor(myColors[randomColor], 190); // color of balls, number is alpha
        ofDrawEllipse(flakePoint,ballSize,ballSize);
        
        //====================Circle Brush========================//
        int maxRadius = 10;  // Increase for a wider brush
        int radiusStepSize = 3;  // Decrease for more circles (i.e. a more opaque brush)
        int alpha = 30;  // alpha of the circles
        int maxOffsetDistance = ballSize/2;  // Increase for a larger spread based on size of circle
        //float brushSize;
        // draw smaller and smaller circles and layering (increasing) opaqueness
        for (int radius = maxRadius; radius > 0; radius -= radiusStepSize) {
            float angle = ofRandom(ofDegToRad(270));
            float distance = ofRandom(maxOffsetDistance);
            float xOffset = cos(angle) * distance + ofRandom(-distance/2,distance/2);
            float yOffset = sin(angle) * distance + ofRandom(-distance/2,distance/2);
            ofSetColor(myColors[randomColor], alpha);
            ofDrawEllipse(flakePoint.x+xOffset,flakePoint.y+yOffset,ballSize,ballSize);
            //ofDrawCircle(ofGetMouseX()+xOffset, ofGetMouseY()+yOffset, radius);
        }
        //=====================Circle Brush======================//
    }
    
    ofVec3f flakePoint;
    ofVec3f flakeRandom;
    bool fingerPressed;
    float ballSize;
    ofColor myColors[NUM_COLORS];
    int randomColor;
};
