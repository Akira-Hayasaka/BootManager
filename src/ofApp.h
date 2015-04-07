#pragma once

#include "ofMain.h"
#include "ofxTransparentWindow.h"
#include "ofxOsc.h"
#include "PowerButtonDetector.h"

class ofApp : public ofBaseApp
{
public:
    void setup();
    void update();
    void draw();
    
    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y);
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
    
private:
    
    PowerButtonDetector pbd;
    
    const string shutdonwScript = "osascript -e \'tell app \"System Events\" to shut down\'";
    
    ofxTransparentWindow transparent;
    ofxOscReceiver rcv;
    string disp;
};
