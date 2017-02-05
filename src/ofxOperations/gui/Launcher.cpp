#include "Launcher.h"

using namespace ofxOperations::gui;

void Launcher::setup(ofxOperations::OperationGroup *operationGroup){
    this->operationGroup = operationGroup;

    // initial state; all operations are suggested
    updateSuggestions("");

    // setup child-components
    suggestionsBox.setup(&suggestedOperations);
    textInput.setup();

    // register listeners. These don't need to be removed in a destructor,
    // because the destructor will also destruct the components and their events
    ofAddListener(suggestionsBox.selectEvent, this, &Launcher::onSuggestionSelect);
    ofAddListener(textInput.escapeEvent, this, &Launcher::onTextInputEscape);
    ofAddListener(textInput.changeEvent, this, &Launcher::onTextInputChange);
}

void Launcher::draw(){
    textInput.draw(10.0f, 10.0f);
    suggestionsBox.draw(10.0f, 25.0f);
}

void Launcher::updateSuggestions(const string& query){
    suggestedOperations.clear();

    // we need an operationGroup to have any operations at all
    if(!operationGroup)
        return;

    for(auto op : operationGroup->getOperations()){
        if(match(op->getName(), query))
            suggestedOperations.push_back(op);
    }
}

bool Launcher::match(const string& name, const string& query){
    if(query == "")
        return true;

    return name.find(query) != string::npos;
}

void Launcher::setActive(bool active){
    suggestionsBox.setActive(active);
    textInput.setActive(active);
}

void Launcher::onSuggestionSelect(Operation &op){
    textInput.setValue("");
    setActive(false);
    op.run();
}

void Launcher::onTextInputEscape(TextInput &input){
    setActive(false);
}

void Launcher::onTextInputChange(TextInput &input){
    updateSuggestions(input.getValue());
}
