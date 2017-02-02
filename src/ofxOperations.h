#pragma once

// OF dependencies
#include "ofTypes.h"
#include "ofEvent.h"

class ofxOperation {

    public: // methods

        ofxOperation();
        ofxOperation(string _id, string name="", string description="");

        void invoke();

    public: // getters / setters

        void setId(string _id){ this->_id = _id; }
        void setName(string name){ this->name = name; }
        void setDescription(string desc){ this->description = desc; }

    public: // events

        ofEvent<ofxOperation> runEvent;

    private: // attributes

        string _id;
        string name;
        string description;
};
