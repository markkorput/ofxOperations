#pragma once

// OF
#include "ofTypes.h"
// ofxOperations
#include "Operation.h"

namespace ofxOperations {

    class OperationGroup {

        public: // methods
            void add(shared_ptr<Operation> op);
            void remove(shared_ptr<Operation> op);
            void add(OperationGroup &opGroup);
            void add(shared_ptr<OperationGroup> opGroup);
            void remove(OperationGroup &opGroup);
            void remove(shared_ptr<OperationGroup> opGroup);
            shared_ptr<Operation> add(const string& name = "", const string &description = "");
            shared_ptr<Operation> getByName(const string& name);

        public: // getters / setters
            const vector<shared_ptr<Operation>> & getOperations(){ return operations; }

        private: // attributes
            vector<shared_ptr<Operation>> operations;
    };

} // namespace ofxOperations
