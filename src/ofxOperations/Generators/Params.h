#pragma once

// OF
#include "ofParameterGroup.h"
// ofxOperations
#include "../OperationManager.h"

namespace ofxOperations { namespace Generators {

    class Params {
    public: // methods
        Params(OperationManager& operationManager);

        void generateFor(ofParameterGroup &parameterGroup);

    private: // attributes

        OperationManager* operationManager;
    };

}}
