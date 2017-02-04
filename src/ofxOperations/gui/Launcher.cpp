#include "Launcher.h"

using namespace ofxOperations::gui;

void Launcher::setup(ofxOperations::OperationGroup *operationGroup){
    this->operationGroup = operationGroup;
    textInput.setup();

    // these listeners don't need to be removed in a destructor,
    // because the destructor will also destruct the textInput and its events
    ofAddListener(textInput.submitEvent, this, &Launcher::onTextInputSubmit);
    ofAddListener(textInput.escapeEvent, this, &Launcher::onTextInputEscape);
}

void Launcher::draw(){
    textInput.draw();
}

void Launcher::setActive(bool active){
    bActive = active;

    if(bActive){
        textInput.focus();
        return;
    }

    textInput.setActive(false);
}

void Launcher::onTextInputSubmit(TextInput &input){
    input.setValue("");
}

void Launcher::onTextInputEscape(TextInput &input){
    setActive(false);
}
