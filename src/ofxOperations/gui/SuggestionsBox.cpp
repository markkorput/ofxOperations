#include "SuggestionsBox.h"
// OF
// #include "ofAppRunner.h"
#include "ofGraphics.h"

using namespace ofxOperations::gui;

void SuggestionsBox::setup(deque<shared_ptr<ofxOperations::Operation>> * ops){
    setOperations(ops);
    ofAddListener(ofEvents().keyPressed, this, &SuggestionsBox::keyPressed, OF_EVENT_ORDER_BEFORE_APP);
}

void SuggestionsBox::destroy(){
    ofRemoveListener(ofEvents().keyPressed, this, &SuggestionsBox::keyPressed);
}

void SuggestionsBox::draw(float x, float y){
    if(!operations) return;

    if(operations->size() == 0){
        string msg = "[no operations]";
        ofDrawBitmapString(msg, x, y);
        return;
    }

    int lastVisible = nFirstVisible+nVisibleCount-1;
    if(operations->size() <= lastVisible)
        lastVisible = operations->size()-1;

    float dy=15.0f;

    for(int i=nFirstVisible; i<=lastVisible; i++){
        auto op = (*operations)[i];
        ofDrawBitmapString(op->getName(), i == nSelected ? x + 10.0f : x, y);
        y += dy;
    }
}

void SuggestionsBox::setOperations(deque<shared_ptr<ofxOperations::Operation>> * ops){
    operations = ops;
}

shared_ptr<ofxOperations::Operation> SuggestionsBox::getSelected(){
    if(nSelected < 0)
        return nullptr;

    return (*operations)[nSelected];
}

void SuggestionsBox::keyPressed(ofKeyEventArgs &event) {
    if(!bActive || !operations) return;

    if(event.key == OF_KEY_DOWN){
        nSelected++;

        if(nSelected >= operations->size())
            nSelected = operations->size()-1;

        int lastVisible = nFirstVisible + nVisibleCount - 1;

        if(nSelected > lastVisible)
            nFirstVisible = nSelected-nVisibleCount+1;

        return;
    }

    if(event.key == OF_KEY_UP){
        nSelected--;

        if(nSelected < 0)
            nSelected = 0;

        if(nSelected < nFirstVisible)
            nFirstVisible = nSelected;

        return;
    }

    if(event.key == OF_KEY_RETURN){
        auto op = getSelected();
        if(op)
            ofNotifyEvent(selectEvent, *op.get(), this);
        return;
    }
}
