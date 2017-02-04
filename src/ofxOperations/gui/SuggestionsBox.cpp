#include "SuggestionsBox.h"

#include "ofGraphics.h"

using namespace ofxOperations::gui;

void SuggestionsBox::setup(deque<shared_ptr<Operation>> * ops){
    setOperations(ops);
}

void SuggestionsBox::draw(float x, float y){
    float dy=15.0f;
    int i=0;

    for(auto op : (*operations)){
        if(i >= nVisibleCount)
            break;

        ofDrawBitmapString(op->getName(), 0.0f, y+i*dy);
        i++;
    }
}

void SuggestionsBox::setOperations(deque<shared_ptr<Operation>> * ops){
    operations = ops;
}
