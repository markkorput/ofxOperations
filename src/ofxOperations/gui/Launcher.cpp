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
    ofAddListener(suggestionsBox.selectEvent, this, &Launcher::onSuggestionSelect);
    ofAddListener(textInput.escapeEvent, this, &Launcher::onTextInputEscape);
}

void Launcher::draw(){
    textInput.draw(10.0f, 10.0f);
    suggestionsBox.draw(10.0f, 25.0f);
}

void Launcher::setActive(bool active){
    bActive = active;

    suggestionsBox.setActive(bActive);
    textInput.setActive(bActive);
}

void Launcher::onSuggestionSelect(Operation &op){
    textInput.setValue("");
    setActive(false);
    op.run();
}

void Launcher::onTextInputEscape(TextInput &input){
    setActive(false);
}
