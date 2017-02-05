#pragma once

// OF
#include "ofTypes.h"
#include "ofEvents.h"
// ofxOperations
#include "../Operation.h"

#define DEFAULT_VISIBLE_COUNT 10
#define NONE_SELECTED (-1)

namespace ofxOperations { namespace gui {
    class SuggestionsBox {
    public: // methods
        SuggestionsBox() : bActive(false),
                            nVisibleCount(DEFAULT_VISIBLE_COUNT),
                            nFirstVisible(0),
                            nSelected(NONE_SELECTED){}
        ~SuggestionsBox(){ destroy(); }

        void setup(deque<shared_ptr<ofxOperations::Operation>> * ops);
        void destroy();
        void draw(float x=0.0f, float y=0.0f);

        void resetSelected();

    public: // getter/setter methods
        void setOperations(deque<shared_ptr<ofxOperations::Operation>> * ops);
        void setActive(bool active=true){ bActive=active; }
        shared_ptr<ofxOperations::Operation> getSelected();

    private: // callbacks

        void keyPressed(ofKeyEventArgs &event);

    public: // events

        ofEvent<Operation> selectEvent;

    private: // attributes
        bool bActive;
        deque<shared_ptr<ofxOperations::Operation>> *operations;
        int nVisibleCount;
        int nFirstVisible;
        int nSelected;
    };
}}
