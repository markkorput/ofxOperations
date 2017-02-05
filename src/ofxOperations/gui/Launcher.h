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
        void updateSuggestions(const string& query);
        static bool match(const string& name, const string& query);

    public: // getter/setter methods

        bool getActive(){ return textInput.getActive(); }
        void setActive(bool active=true);

    private: // callbacks

        void onSuggestionSelect(Operation &op);
        void onTextInputEscape(TextInput &input);
        void onTextInputChange(TextInput &input);

    private: // attributes

        TextInput textInput;
        SuggestionsBox suggestionsBox;

        ofxOperations::OperationGroup *operationGroup;
        deque<shared_ptr<Operation>> suggestedOperations;
    };
}}
