#pragma once

// OF
#include "ofTypes.h"
// ofxOperations
#include "Operation.h"

namespace ofxOperations {

    class OperationGroup {

        public: // methods
            OperationGroup();

            void add(shared_ptr<Operation> op);
            void add(shared_ptr<OperationGroup> opGroup);
            shared_ptr<Operation> add(const string& _id, const string& name = "", const string &description = "");

        public: // getters / setters
            const vector<shared_ptr<Operation>> & getOperations(){ return operations; }

        private: // attributes
            vector<shared_ptr<Operation>> operations;
    };

} // namespace ofxOperations
