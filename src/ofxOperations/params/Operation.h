#pragma once

// OF
#include "ofParameter.h"
// ofxOperations
#include "../Operation.h"
#include "../gui/TextInput.h"

namespace ofxOperations { namespace Params {

    class Operation : public ofxOperations::Operation {

    public: // methods

        Operation();
        ~Operation();

        void draw(float x=0.0f, float y=0.0f);

    public: // getter/setter methods

        void setParameter(ofAbstractParameter *param){ parameter = param; }

    protected: // methods

        void perform() override;
        void setActive(bool active=true);

    protected: // callbacks

        void onDraw(ofEventArgs&);
        void onInputSubmit(ofxOperations::gui::TextInput &input);
        void onInputEscape(ofxOperations::gui::TextInput &input);

    private: // attributes
        bool bActive;
        ofAbstractParameter* parameter;
        ofxOperations::gui::TextInput textInput;
    };
}}
