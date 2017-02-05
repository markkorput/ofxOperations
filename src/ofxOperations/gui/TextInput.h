#pragma once

// OF
#include "ofEvents.h"
#include "ofRectangle.h"

#define DEFAULT_PROMPT ">"

namespace ofxOperations { namespace gui {

    class TextInput {

    public: // methods

        TextInput();
        ~TextInput(){ destroy(); }
        void setup();
        void destroy();
        void draw(float x=0.0f, float y=0.0f);

        void focus(){ setActive(); }
        static ofRectangle getBitmapStringBoundingBox(string text);

    public: // getter / setter methods

        const string& getValue(){ return value; }
        void setValue(const string &newValue);

        bool getActive(){ return bActive; }
        void setActive(bool active=true);

        const string& getPrompt(){ return sPrompt; }
        void setPrompt(const string& prompt);

    private: // callbacks

        void keyPressed(ofKeyEventArgs &event);

    public: // events

        ofEvent<TextInput> submitEvent;
        ofEvent<TextInput> escapeEvent;
        ofEvent<TextInput> changeEvent;

    private: // attributes

        bool bActive;
        string value;
        string sPrompt;
        size_t cursorPos;
        ofVec2f cursorOffset;
        ofVec2f charSize;

    };
}}
