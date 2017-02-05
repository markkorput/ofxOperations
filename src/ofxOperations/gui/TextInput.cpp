// OF
#include "ofAppRunner.h"
#include "ofGraphics.h"
// ofxOperations
#include "TextInput.h"

using namespace ofxOperations::gui;

void TextInput::setup(){
    ofAddListener(ofEvents().keyPressed, this, &TextInput::keyPressed, OF_EVENT_ORDER_BEFORE_APP);
}

void TextInput::destroy(){
    ofRemoveListener(ofEvents().keyPressed, this, &TextInput::keyPressed);
}

#define CHAR_W (8.0f)
#define CHAR_H (5.0f)

void TextInput::draw(float x, float y){
    if(!bActive){
        // text
        ofSetColor(ofColor::white);
        ofDrawBitmapString(value, x,y);
        return;
    }

    // text, highlighted (active)
    ofSetColor(ofColor::white);
    ofDrawBitmapStringHighlight(value+" ", x,y);

    // cursor
    ofSetColor(200, 200, 200, 200);
    ofDrawRectangle(x+CHAR_W*cursorPos, y+CHAR_H-2.0f, CHAR_W, 4.0f);
}

void TextInput::setValue(const string &newValue){
    value=newValue;
    cursorPos=value.size();
}

void TextInput::setActive(bool active){
    bActive=active;

    if(bActive)
        ofSetEscapeQuitsApp(!bActive);
}

void TextInput::keyPressed(ofKeyEventArgs &event) {
    if(!bActive) return;

    switch (event.key) {

        case OF_KEY_RETURN:
            ofNotifyEvent(submitEvent, *this, this);
            return;

        case OF_KEY_BACKSPACE:
            if(cursorPos > 0){
                // value.pop_back();
                value.erase(cursorPos-1, 1);
                cursorPos--;
                ofNotifyEvent(changeEvent, *this, this);
            }
            return;

        case OF_KEY_DEL:
            if(cursorPos < value.size()){
                value.erase(cursorPos, 1);
                ofNotifyEvent(changeEvent, *this, this);
            }
            return;

        case OF_KEY_TAB:
            setActive(false);
            return;

        case OF_KEY_ESC:
            ofNotifyEvent(escapeEvent, *this, this);
            return;

        case OF_KEY_LEFT:
            if(cursorPos > 0)
                cursorPos--;
            return;

        case OF_KEY_RIGHT:
            if(cursorPos < value.size())
                cursorPos++;
            return;

        default:
            if(event.key >= ' ' && event.key <= 255){
                // printable character
                value.insert(cursorPos, ofToString(char(event.key)));
                cursorPos++;
                ofNotifyEvent(changeEvent, *this, this);
            }
    }
}
