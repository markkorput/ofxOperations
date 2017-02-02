// OF dependencies
#include "ofEventUtils.h"
// ofxOperations
#include "ofxOperations.h"


ofxOperation::ofxOperation() : _id(""), name(""), description("") {

}

ofxOperation::ofxOperation(string _id, string name, string description){
    setId(_id);
    setName(name);
    setDescription(description);
}

void ofxOperation::invoke(){
    ofNotifyEvent(runEvent, *this, this);
}
