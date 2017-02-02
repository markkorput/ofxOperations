#pragma once

// OF
#include "ofTypes.h"
// ofxOperations
#include "Operation.h"

namespace ofxOperations {

    class OperationManager {

        public: // methods
            const vector<shared_ptr<Operation>> & getOperations(){ return operations; }

        private: // attributes
            vector<shared_ptr<Operation>> operations;
    };

} // namespace ofxOperations
