#include "ofApp.h"
using namespace ofxCv;
using namespace cv;

int stageLengths[] = {10, 8, 45, 8, 5, 10, 6};

//--------------------------------------------------------------
void ofApp::setup(){
    //ofSetFullscreen(true);
    ofToggleFullscreen();
    ofSetVerticalSync(true);
//    finder.setup("haarcascade_frontalface_default.xml");
//    finder.setPreset(ObjectFinder::Fast);
//    finder.getTracker().setSmoothingRate(.3);
    cam.setup(1280,720);
    ofEnableAlphaBlending();
    ofSetFrameRate(120);
    
    //faceblur.load ("faceblur2.png");
    idle.load("idle.mov");
    loadscreen.load("loadscreen.mov");
    desktop.load("desktop.mov");
    crashscreen.load("crashscreen.mov");
    rebootscreen.load("rebootscreen.mov");
    powerdownscreen.load("powerdownscreen.mov");
    flatline.load("flatline.mp3");
    
}

//--------------------------------------------------------------
void ofApp::update(){
    
    //camera settings
    
    cam.update();
    if(cam.isFrameNew()) {
        finder.update(cam);
    }
    
    ofSoundUpdate();
    idle.update();
    loadscreen.update();
    desktop.update();
    crashscreen.update();
    rebootscreen.update();
    powerdownscreen.update();
   

    //stages
    timer += ofGetLastFrameTime();
    
    
//    if(finder.size() > 0 && timer >= stageLengths[stage]) {
    if(timer >= stageLengths[stage]) {
        stage++;
        timer = 0;
    }
  
    if (stage > 6){
        stage = 0;
    }


}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofBackground(0);

//idle
    if(stage==0) {
        idle.play();
        idle.draw(0,0, ofGetWindowWidth(),ofGetWindowHeight());
    }
    
//load screen
    else if(stage==1){
         loadscreen.play();
         loadscreen.draw(0,0, ofGetWindowWidth(),ofGetWindowHeight());
         idle.closeMovie();
    }
    
//desktop
     else if(stage==2){
         desktop.play();
         desktop.draw(0,0, ofGetWindowWidth(),ofGetWindowHeight());
         loadscreen.closeMovie();
    }

//crash screen
     else if(stage==3){
         crashscreen.play();
         crashscreen.draw(0,0, ofGetWindowWidth(),ofGetWindowHeight());
         desktop.closeMovie();
    }

//reboot screen
    else if(stage==4){
        rebootscreen.play();
        rebootscreen.draw(0,0, ofGetWindowWidth(),ofGetWindowHeight());
        crashscreen.closeMovie();
    }

//camera
    else if(stage==5){
         flatline.play();
        rebootscreen.closeMovie();
        cam.draw(68,51,720,360);
        cam.draw(193,228,720,360);
        cam.draw(46,484,720,360);
        cam.draw(400,456,720,360);
        cam.draw(758,51,720,360);
        cam.draw(670,297,720,360);
        cam.draw(828,493,720,360);
    }

//power down screen
   else if(stage==6){
       flatline.stop();
       powerdownscreen.play();
       powerdownscreen.draw(0,0, ofGetWindowWidth(),ofGetWindowHeight());
   } else {
       stage = 0;
   }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

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
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

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

//        for(int i = 0; i < finder.size(); i++) {
//            ofRectangle object = finder.getObjectSmoothed(i);
//            faceblur.setAnchorPercent(.5, .5);
//            float scaleAmount = .85 * object.width / faceblur.getWidth();
//            ofPushMatrix();
//            ofTranslate(object.x + object.width / 2., object.y + object.height * .42);
//            ofScale(scaleAmount, scaleAmount);
//            //  faceblur.draw(0, 0);
//            ofPopMatrix();
//        }


