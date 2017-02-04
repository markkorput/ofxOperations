// OF dependencies
#include "ofEventUtils.h"
// ofxOperations
#include "Operation.h"

using namespace ofxOperations;

Operation::Operation() : _id(""), name(""), description("") {
}

Operation::Operation(string _id, string name, string description){
    this->_id = _id;
    this->name = name;
    this->description = description;
}

void Operation::run(){
    ofNotifyEvent(startEvent, *this, this);
    perform();
    ofNotifyEvent(endEvent, *this, this);
}

void Operation::set(string _id, string name, string description){
    this->_id = _id;
    this->name = name;
    this->description = description;
}
