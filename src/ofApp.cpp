#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofLogToFile("log.txt");

    params.setName("ofxOperationsTestParam");
    params.add(sizeParam.set("size", 1.0f));
    params.add(posParam.set("pos", ofVec2f(0.0f)));
    subParams.setName("sub");
    subParams.add(strParam.set("name", "no name"));
    params.add(subParams);

    ofxOperations::Params::Generator opsParamsGenerator;
    opsGroup.add(opsParamsGenerator.generateFor(params));
    opsGroup.add("111");
    opsGroup.add("222");
    opsGroup.add("333");
    opsGroup.add("444");
    opsGroup.add("555");
    opsGroup.add("666");

    operationsLauncher.setup(&opsGroup);

    // ofAddListener(terminal.commandSent, this, &ofApp::onTerminalCommand);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetColor(ofColor::white);
    ofDrawRectangle(posParam.get().x, posParam.get().y, sizeParam.get(), 10.0f);

    // terminal.draw(10, 10);
    if(operationsLauncher.getActive())
        operationsLauncher.draw();
}

//--------------------------------------------------------------
void ofApp::onTerminalCommand(const string & cmd){
    ofLog() << "got terminal command: " << cmd;

    if(cmd == "quit" || cmd == "exit"){
        ofExit();
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if(operationsLauncher.getActive())
        return;

    if(key == '`'){
        operationsLauncher.activate();
    }
}
