// OF dependencies
#include "ofEventUtils.h"
// ofxOperations
#include "Operation.h"

using namespace ofxOperations;

Operation::Operation() : name(""), description("") {
}

Operation::Operation(string name, string description){
    this->name = name;
    this->description = description;
}

void Operation::run(){
    ofNotifyEvent(startEvent, *this, this);
    perform();

    if(!bAsync)
        ofNotifyEvent(endEvent, *this, this);
}

void Operation::set(const string& name, const string& description){
    this->name = name;
    this->description = description;
}
