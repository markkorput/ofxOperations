#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofLogToFile("log.txt");

    params.setName("ofxOperationsTestParam");
    params.add(sizeParam.set("size", 1.0f, 0.0f, 10.0f));

    ofxOperations::Generators::Params paramOpsGenerator(opsManager);
    paramOpsGenerator.generateFor(params);

    ofAddListener(terminal.commandSent, this, &ofApp::onTerminalCommand);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    terminal.draw(10, 10);
}

//--------------------------------------------------------------
void ofApp::onTerminalCommand(const string & cmd){
    ofLog() << "got terminal command: " << cmd;

    if(cmd == "quit" || cmd == "exit"){
        ofExit();
    }
}
