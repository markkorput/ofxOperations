// OF
#include "ofAppRunner.h"
#include "ofGraphics.h"
#include "ofBitmapFont.h"
// ofxOperations
#include "TextInput.h"

using namespace ofxOperations::gui;

TextInput::TextInput() : bActive(false), cursorPos(0){
}

void TextInput::setup(){
    auto rect = getBitmapStringBoundingBox("W"); // random character
    charSize.set(rect.getWidth(), rect.getHeight());
    setPrompt(DEFAULT_PROMPT);
    ofAddListener(ofEvents().keyPressed, this, &TextInput::keyPressed, OF_EVENT_ORDER_BEFORE_APP);
}

void TextInput::destroy(){
    ofRemoveListener(ofEvents().keyPressed, this, &TextInput::keyPressed);
}

void TextInput::draw(float x, float y){
    if(!bActive){
        // text
        ofSetColor(ofColor::white);
        ofDrawBitmapString(value, x,y);
        return;
    }

    // text, highlighted (active)
    ofSetColor(ofColor::white);
    ofDrawBitmapStringHighlight(sPrompt+value+" ", x,y);

    // cursor
    ofSetColor(200, 200, 200, 150);
    ofDrawRectangle(x + cursorOffset.x + charSize.x * cursorPos,
                    y + cursorOffset.y,
                    charSize.x,
                    charSize.y);
}

// getBitmapStringBoundingBox function from @roymacdonald
// https://forum.openframeworks.cc/t/how-to-get-size-of-ofdrawbitmapstring/22578/7
ofRectangle TextInput::getBitmapStringBoundingBox(string text){
    vector<string> lines = ofSplitString(text, "\n");
        int maxLineLength = 0;
        for(int i = 0; i < (int)lines.size(); i++) {
            // tabs are not rendered
            const string & line(lines[i]);
            int currentLineLength = 0;
            for(int j = 0; j < (int)line.size(); j++) {
                if (line[j] == '\t') {
                    currentLineLength += 8 - (currentLineLength % 8);
                } else {
                    currentLineLength++;
                }
            }
            maxLineLength = MAX(maxLineLength, currentLineLength);
        }

        int padding = 4;
        int fontSize = 8;
        float leading = 1.7;
        int height = lines.size() * fontSize * leading - 1;
        int width = maxLineLength * fontSize;
    return ofRectangle(0,0,width, height);
}

void TextInput::setValue(const string &newValue){
    value=newValue;
    cursorPos=value.size();
    ofNotifyEvent(changeEvent, *this, this);
}

void TextInput::setActive(bool active){
    bActive=active;

    if(bActive)
        ofSetEscapeQuitsApp(!bActive);
}

void TextInput::setPrompt(const string& prompt){
    sPrompt = prompt;

    auto parts = ofSplitString(prompt, "\n");
    cursorOffset.set(parts.back().size() * charSize.x,
                    // move up additional 0.5 character height
                    // because of different render coordinate modes (?)
                    (parts.size()-1.8f) * charSize.y);
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
