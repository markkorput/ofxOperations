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

void TextInput::draw(float x, float y){
    if(bActive){
        ofDrawBitmapStringHighlight(value, x,y);
        return;
    }

    ofDrawBitmapString(value, x,y);
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
            value.pop_back();
            ofNotifyEvent(changeEvent, *this, this);
            return;

        case OF_KEY_DEL:
            // TODO have a moveable carret => delete will delete current character
            break;

        case OF_KEY_TAB:
            setActive(false);
            break;

        case OF_KEY_ESC:
            ofNotifyEvent(escapeEvent, *this, this);
            return;

        default:
            if(event.key >= ' ' && event.key <= 255){
                // printable character
                value += ofToString(char(event.key));
                ofNotifyEvent(changeEvent, *this, this);
            }
    }
}
