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

        void onFoo(ofxOperations::Operation &op);
        void onTitleChange(string &param);

    public: // parameters

        ofParameterGroup params, subParams;
        ofParameter<ofVec2f> posParam;
        ofParameter<string> strParam;

    private:
        ofxOperations::OperationGroup opsGroup;
        ofxOperations::gui::Launcher operationsLauncher;
        string idleMessage, activeMessage;
};

//--------------------------------------------------------------
// ofApp.cpp
//--------------------------------------------------------------

void ofApp::setup(){
    // configure params
    params.setName("ofxOperationsTestParam");
    params.add(posParam.set("pos", ofVec2f(10.0f, 120.0f)));
    subParams.setName("sub");
    subParams.add(strParam.set("window title", "ofxOperations example"));
    strParam.addListener(this, &ofApp::onTitleChange);
    params.add(subParams);

    ofSetWindowTitle(strParam.get());
    ofSetWindowShape(400,300);

    // generate some common operations
    opsGroup.add(ofxOperations::Generator::generateDefault());
    opsGroup.add(ofxOperations::Params::Generator::generateFor(params));
    // generate a custom operation and add a listener for when it's invoked
    opsGroup.add("foo");
    ofAddListener(opsGroup.getByName("foo")->startEvent, this, &ofApp::onFoo);

    // setup launcher GUI
    operationsLauncher.setup(&opsGroup, true /* register draw event */);

    // call for action
    idleMessage = "Press the tilde (~)\nto open the launcher";
    activeMessage = "Use up/down arrow keys\nto navigate the SuggestionsBox\n\nor start typing to narrow\ndown the suggestions";
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(ofColor::lightGreen);

    ofDrawBitmapStringHighlight(
        operationsLauncher.getActive() ? activeMessage : idleMessage,
        posParam.get().x,
        posParam.get().y);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if(operationsLauncher.getActive())
        return;

    if(key == '`')
        operationsLauncher.activate();
}

void ofApp::onFoo(ofxOperations::Operation &op){
    idleMessage = "Foo you very much";
}

void ofApp::onTitleChange(string &s){
    ofSetWindowTitle(s);
}

//--------------------------------------------------------------
// main.cpp
//--------------------------------------------------------------

int main( ){
    ofSetupOpenGL(1024,768,OF_WINDOW);
    ofRunApp(new ofApp());
}
