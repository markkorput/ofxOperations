// OF
#include "ofUtils.h"
#include "ofGraphics.h"
// ofxOperations
#include "Launcher.h"

using namespace ofxOperations::gui;

void Launcher::setup(ofxOperations::OperationGroup *operationGroup, bool registerDraw){
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

    if(registerDraw)
        ofAddListener(ofEvents().draw, this, &Launcher::onDraw);
}

void Launcher::destroy(){
    // this listener won't be registered by default, but try to remove anyway
    ofRemoveListener(ofEvents().draw, this, &Launcher::onDraw);
}

void Launcher::draw(float x, float y){
    ofEnableAlphaBlending();
    textInput.draw(x, y);
    suggestionsBox.draw(x, y+15.0f);
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

    string lName = ofToLower(name);
    string lQuery = ofToLower(query);

    // start at beginning of name
    std::size_t p = 0;

    // loop over all characters in query
    for(auto c : lQuery){
        // find the current character _after_ the previous searched character
        p = lName.find(c, p);

        // not found? no match
        if(p == string::npos)
            return false;

        // next query character must appear _after_ this one
        p += 1;
    }

    // all character found and in correct order
    return true;
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
    suggestionsBox.resetSelected();
}

void Launcher::onDraw(ofEventArgs &args){
    if(getActive())
        draw();
}
