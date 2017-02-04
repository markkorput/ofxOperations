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
        void setActive(bool active=true){ bActive=active; }

    private: // callbacks

        void keyPressed(ofKeyEventArgs &event);

    public: // events

        ofEvent<TextInput> submitEvent;

    private: // attributes

        bool bActive;
        string value;

    };
}}
