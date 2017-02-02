#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofLogToFile("log.txt");
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
    ofLog() << "got terminal command; " << cmd;
}
