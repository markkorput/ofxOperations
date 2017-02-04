#include "Operation.h"

using namespace ofxOperations::Params;

void Operation::perform(){
    if(!parameter) return;

    string newValue = getUserInput();

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
}

string Operation::getUserInput(){
    ofLog() << "TODO: implement ofxParameters::Params::Operations::getUserInput";
    return "";
}
