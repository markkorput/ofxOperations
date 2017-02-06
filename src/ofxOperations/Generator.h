#pragma once

// std
#include <stdlib.h>
// ofxOperations
#include "OperationGroup.h"

namespace ofxOperations {
    class Generator {
        public:
            static shared_ptr<OperationGroup> generateDefault();
    };
}
