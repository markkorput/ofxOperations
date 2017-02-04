#pragma once

// OF
#include "ofParameter.h"
// ofxOperations
#include "../Operation.h"

namespace ofxOperations { namespace Params {

    class Operation : public ofxOperations::Operation {

    public: // methods

        Operation() : parameter(NULL){}

    public: // getter/setter methods

        void setParameter(ofAbstractParameter *param){ parameter = param; }

    protected: // methods

        void perform() override;
        string getUserInput();

    private: // attributes

        ofAbstractParameter* parameter;
    };
}}
