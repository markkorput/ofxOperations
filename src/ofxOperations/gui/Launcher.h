#pragma once

// OF
#include "ofEvents.h"
// ofxOperations
#include "TextInput.h"
#include "SuggestionsBox.h"
#include "../OperationGroup.h"

namespace ofxOperations { namespace gui {
    class Launcher {

    public: // methods
        ~Launcher(){ destroy(); }
        void setup(ofxOperations::OperationGroup *operationGroup=NULL, bool registerDraw=false);
        void destroy();
        void draw(float x=10.0f, float y=10.0f);

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
        void onDraw(ofEventArgs &args);

    private: // attributes

        TextInput textInput;
        SuggestionsBox suggestionsBox;

        ofxOperations::OperationGroup *operationGroup;
        deque<shared_ptr<Operation>> suggestedOperations;
    };
}}
