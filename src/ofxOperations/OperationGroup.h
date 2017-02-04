#pragma once

// OF
#include "ofTypes.h"
// ofxOperations
#include "Operation.h"

namespace ofxOperations {

    class OperationGroup {

        public: // methods

            void add(shared_ptr<OperationGroup> opGroup);
            void add(shared_ptr<Operation> op);

        public: // getters / setters
            const vector<shared_ptr<Operation>> & getOperations(){ return operations; }

        private: // attributes
            vector<shared_ptr<Operation>> operations;
    };

} // namespace ofxOperations
