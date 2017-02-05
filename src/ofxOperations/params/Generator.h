#pragma once

// OF
#include <stdlib.h>
#include "ofParameterGroup.h"
// ofxOperations
#include "../OperationGroup.h"

namespace ofxOperations { namespace Params {

    class Generator {
    public: // methods
        shared_ptr<OperationGroup> generateFor(ofParameterGroup &group, const string &prefix="");
        shared_ptr<OperationGroup> generateFor(ofAbstractParameter &param, const string &prefix="");
    };

}}
