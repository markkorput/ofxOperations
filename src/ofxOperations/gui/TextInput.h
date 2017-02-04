#pragma once

#include "ofEvents.h"

namespace ofxOperations { namespace gui {

    class TextInput {

    public: // methods

        TextInput() : bActive(false){}
        ~TextInput(){ destroy(); }
        void setup();
        void destroy();
        void draw();

        void focus(){ setActive(); }

    public: // getter / setter methods

        const string& getValue(){ return value; }
        void setValue(const string &newValue){ value=newValue; }
        void setActive(bool active=true);

    private: // callbacks

        void keyPressed(ofKeyEventArgs &event);

    public: // events

        ofEvent<TextInput> submitEvent;
        ofEvent<TextInput> escapeEvent;

    private: // attributes

        bool bActive;
        string value;

    };
}}
