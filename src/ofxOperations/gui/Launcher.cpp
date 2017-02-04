#include "Launcher.h"

using namespace ofxOperations::gui;

void Launcher::setup(ofxOperations::OperationGroup *operationGroup){
    this->operationGroup = operationGroup;
    textInput.setup();

    // initial state; all operations are suggested
    if(operationGroup){
        for(auto op : operationGroup->getOperations()){
            suggestedOperations.push_back(op);
        }
    }

    suggestionsBox.setup(&suggestedOperations);

    // these listeners don't need to be removed in a destructor,
    // because the destructor will also destruct the textInput and its events
    ofAddListener(textInput.submitEvent, this, &Launcher::onTextInputSubmit);
    ofAddListener(textInput.escapeEvent, this, &Launcher::onTextInputEscape);
}

void Launcher::draw(){
    textInput.draw(10.0f, 10.0f);
    suggestionsBox.draw(10.0f, 25.0f);
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
