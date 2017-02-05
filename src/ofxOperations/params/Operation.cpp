#include "Operation.h"
// OF
#include "ofAppRunner.h"

using namespace ofxOperations::Params;

Operation::Operation() : parameter(NULL), bActive(false){
    setAsync();
    ofAddListener(textInput.submitEvent, this, &Operation::onInputSubmit);
    ofAddListener(textInput.escapeEvent, this, &Operation::onInputEscape);
    textInput.setup();
}

Operation::~Operation(){
    setActive(false);
}

void Operation::draw(float x, float y){
    textInput.draw(x, y);
}

void Operation::perform(){
    if(!parameter) return;

    setActive();
    textInput.setValue(ofToString(parameter->toString()));
    textInput.setActive();
}

void Operation::setActive(bool active){
    bActive = active;
    textInput.setActive(bActive);

    if(bActive){
        ofAddListener(ofEvents().draw, this, &Operation::onDraw);
        return;
    }

    ofRemoveListener(ofEvents().draw, this, &Operation::onDraw);
}

void Operation::onDraw(ofEventArgs&){
    if(!bActive) return;
    draw(100.0f, 100.0f);
}

void Operation::onInputSubmit(ofxOperations::gui::TextInput &input){
    string newValue = input.getValue();

    if(parameter->type() == typeid(ofParameter <int> ).name()){
        parameter->cast<int>() = ofToInt(newValue);
    }else if(parameter->type() == typeid(ofParameter <float> ).name()){
        parameter->cast<float>() = ofToFloat(newValue);
    }else if(parameter->type() == typeid(ofParameter <bool> ).name()){
        // TODO downcase for making case-insensitive
        parameter->cast<bool>() = (newValue == "true" || newValue == "1");
    }else if(parameter->type() == typeid(ofParameter <int64_t> ).name()){
        parameter->cast<int64_t>() = ofToInt(newValue);
    }else if(parameter->type() == typeid(ofParameter <string> ).name()){
        parameter->cast<string>() = newValue;
    }else{
        parameter->fromString(newValue);
    }

    ofNotifyEvent(endEvent, *this, this);
    setActive(false);
}

void Operation::onInputEscape(ofxOperations::gui::TextInput &input){
    ofNotifyEvent(endEvent, *this, this);
    setActive(false);
}
