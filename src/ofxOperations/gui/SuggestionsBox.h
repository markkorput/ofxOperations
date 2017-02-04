#pragma once

// OF
#include "ofTypes.h"
// ofxOperations
#include "../Operation.h"

namespace ofxOperations { namespace gui {
    class SuggestionsBox {
    public: // methods
        SuggestionsBox() : nVisibleCount(5){}

        void setup(deque<shared_ptr<Operation>> * ops);
        void draw(float x=0.0f, float y=0.0f);

    public: // getter/setter methods
        void setOperations(deque<shared_ptr<Operation>> * ops);

    private: // attributes
        deque<shared_ptr<Operation>> *operations;
        int nVisibleCount;
    };
}}
