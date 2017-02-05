#pragma once

#include "TextInput.h"
#include "SuggestionsBox.h"
#include "../OperationGroup.h"

namespace ofxOperations { namespace gui {
    class Launcher {
    public: // methods
        void setup(ofxOperations::OperationGroup *operationGroup=NULL);
        void draw();
        void activate(){ setActive(); }

    public: // getter/setter methods

        bool getActive(){ return bActive; }
        void setActive(bool active=true);

    private: // callbacks

        void onSuggestionSelect(Operation &op);
        void onTextInputEscape(TextInput &input);

    private: // attributes
        bool bActive;

        TextInput textInput;
        SuggestionsBox suggestionsBox;

        ofxOperations::OperationGroup *operationGroup;
        deque<shared_ptr<Operation>> suggestedOperations;
    };
}}
