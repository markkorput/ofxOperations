//--------------------------------------------------------------
// ofApp.h
//--------------------------------------------------------------

#include "ofMain.h"
#include "ofxOperations.h"

class ofApp : public ofBaseApp{

    public:
        void setup();
        void draw();
        void keyPressed(int key);

    public: // parameters

        ofParameterGroup params, subParams;
        ofParameter<float> sizeParam;
        ofParameter<ofVec2f> posParam;
        ofParameter<string> strParam;

    private:
        ofxOperations::OperationGroup opsGroup;
        ofxOperations::gui::Launcher operationsLauncher;
};

//--------------------------------------------------------------
// ofApp.cpp
//--------------------------------------------------------------

void ofApp::setup(){
    // setup params
    params.setName("ofxOperationsTestParam");
    params.add(sizeParam.set("size", 1.0f));
    params.add(posParam.set("pos", ofVec2f(0.0f)));
    subParams.setName("sub");
    subParams.add(strParam.set("name", "no name"));
    params.add(subParams);

    // generate operations for all params
    opsGroup.add(ofxOperations::Params::Generator::generateFor(params));
    // generate some dummy operations that do nothing
    opsGroup.add("111");
    opsGroup.add("222");
    opsGroup.add("333");
    opsGroup.add("444");
    opsGroup.add("555");
    opsGroup.add("666");

    // setup launcher operations GUI
    operationsLauncher.setup(&opsGroup);
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetColor(ofColor::red);
    ofDrawRectangle(posParam.get().x, posParam.get().y, sizeParam.get(), 10.0f);

    if(operationsLauncher.getActive())
        operationsLauncher.draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if(operationsLauncher.getActive())
        return;

    if(key == '`')
        operationsLauncher.activate();
}

//--------------------------------------------------------------
// main.cpp
//--------------------------------------------------------------

int main( ){
    ofSetupOpenGL(1024,768,OF_WINDOW);
    ofRunApp(new ofApp());
}
