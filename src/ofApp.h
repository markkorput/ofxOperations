#pragma once

#include "ofMain.h"
#include "ofxTerminal.h"
#include "ofxOperations.h"

class ofApp : public ofBaseApp{

    public:
        void setup();
        void update();
        void draw();

        void onTerminalCommand(const string & cmd);

        void keyPressed(int key);

//		void keyReleased(int key);
//		void mouseMoved(int x, int y );
//		void mouseDragged(int x, int y, int button);
//		void mousePressed(int x, int y, int button);
//		void mouseReleased(int x, int y, int button);
//		void mouseEntered(int x, int y);
//		void mouseExited(int x, int y);
//		void windowResized(int w, int h);
//		void dragEvent(ofDragInfo dragInfo);
//		void gotMessage(ofMessage msg);

    public: // parameters

        ofParameterGroup params, subParams;
        ofParameter<float> sizeParam;
        ofParameter<ofVec2f> posParam;
        ofParameter<string> strParam;

    private:
        // ofxTerminal terminal;
        ofxOperations::OperationGroup opsGroup;
        ofxOperations::gui::Launcher operationsLauncher;
};
