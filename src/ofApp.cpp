#include "ofApp.h"


void ofApp::setup()
{
    
    ofSetFrameRate(30);
    
    rcv.setup(8999);
    disp = "none";
    
    pbd.setup();
    transparent.afterMainSetup(ofxTransparentWindow::NORMAL);
}

void ofApp::update()
{
    transparent.update();

    while (rcv.hasWaitingMessages())
    {
        ofxOscMessage m;
        rcv.getNextMessage(&m);
        
        if (m.getAddress() == "/kill")
        {
            disp = "kill";
            ofSystem("killall SonyShowRoom");
        }
        else if (m.getAddress() == "/boot")
        {
            disp = "boot";
            ofSystem("open ../../../../../SonyShowRoom/bin/SonyShowRoom.app");
        }
        else if (m.getAddress() == "/shutdown")
        {
            disp = "shutdown";
            ofSystem(shutdonwScript);
        }
    }
}

void ofApp::draw()
{
//    ofDrawBitmapString(disp, 10, 20);
//    ofDrawBitmapString(ofToString(ofGetFrameRate()), 10, 40);
}



void ofApp::keyPressed(int key){}
void ofApp::keyReleased(int key){}
void ofApp::mouseMoved(int x, int y){}
void ofApp::mouseDragged(int x, int y, int button){}
void ofApp::mousePressed(int x, int y, int button){}
void ofApp::mouseReleased(int x, int y, int button){}
void ofApp::windowResized(int w, int h){}
void ofApp::gotMessage(ofMessage msg){}
void ofApp::dragEvent(ofDragInfo dragInfo){}