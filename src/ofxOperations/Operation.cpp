// OF dependencies
#include "ofEventUtils.h"
// ofxOperations
#include "Operation.h"

using namespace ofxOperations;

Operation::Operation() : _id(""), name(""), description("") {

}

Operation::Operation(string _id, string name, string description){
    setId(_id);
    setName(name);
    setDescription(description);
}

void Operation::invoke(){
    ofNotifyEvent(runEvent, *this, this);
}
