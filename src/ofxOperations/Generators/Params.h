#pragma once

// OF
#include <stdlib.h>
#include "ofParameterGroup.h"
// ofxOperations
#include "../OperationGroup.h"

namespace ofxOperations { namespace Generators {

    class Params {
    public: // methods
        shared_ptr<OperationGroup> generateFor(const ofParameterGroup &group, const string &prefix="");
        shared_ptr<OperationGroup> generateFor(const ofAbstractParameter &param, const string &prefix="");
    };

}}
